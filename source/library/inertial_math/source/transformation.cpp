#include "transformation.h"

#include "constant.h"
#include "coriolis_force.h"
#include "gravity.h"
#include "utility.h"

namespace Iml {

RotationMatrix conversionMatrix(const Triplet &angles)
{
  return rotationArroundAxis(angles[0], X) * rotationArroundAxis(angles[1], Y) * rotationArroundAxis(angles[2], Z);
}

RotationMatrix conversionMatrix2(const Triplet &angles)
{
  return { { 1.0, 0.0, -std::sin(angles[1]) },
           { 0.0, std::cos(angles[0]), std::sin(angles[0]) * std::cos(angles[1]) },
           { 0.0, -std::sin(angles[0]), std::cos(angles[0]) * std::cos(angles[1]) } };
}

RotationMatrix rotationArroundAxis(double angle, Axis axis)
{
  switch (axis)
  {
    case Axis::X:
    {
      return { { 1.0,  0.0,             0.0             },
               { 0.0,  std::cos(angle), std::sin(angle) },
               { 0.0, -std::sin(angle), std::cos(angle) } };
    }
    case Axis::Y:
    {
      return { { std::cos(angle), 0.0, -std::sin(angle) },
               { 0.0,             1.0, 0.0            },
               { std::sin(angle), 0.0, std::cos(angle)  } };
    }
    case Axis::Z:
    default:
    {
      return { { std::cos(angle),  std::sin(angle), 0.0 },
               { -std::sin(angle), std::cos(angle), 0.0 },
               { 0.0,              0.0,             1.0 } };
    }
  }
}

RotationMatrix accelerationOffsetRotationMatrix(double p, double q, double r, double dp, double dq, double dr)
{
  return { { std::pow(q, 2.0) + std::pow(r, 2.0), -(p * q - dr), -(p * r + dq) },
           { -(p * q + dr), std::pow(p, 2.) + std::pow(r, 2.0), -(q * r - dp) },
           { -(p * r - dq), -(q * r + dp), std::pow(p, 2.0) + std::pow(q, 2.0) } };
}

Xyz accelerationOffset(const Attitude &currentVelocity, const Attitude &previousVelocity, const Xyz &offset, double t)
{
  auto velocityChangeRate = slope(previousVelocity, currentVelocity, t);

  return applyRotationMatrix(offset, accelerationOffsetRotationMatrix(currentVelocity.roll(),
                                                                      currentVelocity.pitch(),
                                                                      currentVelocity.yaw(),
                                                                      velocityChangeRate.roll(),
                                                                      velocityChangeRate.pitch(),
                                                                      velocityChangeRate.yaw()));
}

double primeVerticalRadiusOfCurvature(double latitude)
{
  return POLAR_RADIUS_OF_CURVATURE / std::sqrt(1.0 + SECOND_ECCENTRICITY_SQUARED * cos2(latitude));
}

Lla toLla(const Xyz &ecef)
{
  auto latitude = std::atan(ecef.z() / ((std::sqrt(std::pow(ecef.x(), 2.0) + std::pow(ecef.y(), 2.0)) * (1.0 - (2.0 - FLATTENING)) * FLATTENING)));

  auto height = 0.1, lastHeight = 0.0;
  auto iterations = 0;
  while (std::abs(height - lastHeight) > 1e-12)
  {
    lastHeight = height;
    auto N = primeVerticalRadiusOfCurvature(latitude);
    latitude = std::atan(ecef.z() / ((std::sqrt(std::pow(ecef.x(), 2.0) + std::pow(ecef.y(), 2.0)) * (1.0 - (2.0 - FLATTENING) * FLATTENING * N / (N + height)))));
    height = std::sqrt(std::pow(ecef.x(), 2.0) + std::pow(ecef.y(), 2.0)) / std::cos(latitude) - N;

    if (++iterations > 50)
      break;
  }

  return { latitude, std::atan2(ecef.y(), ecef.x()), height };
}

void ecefToNed(const Lla &reference, Xyz &velocityEcef, Xyz &accelerationEcef)
{
  applyRotationMatrixTo(conversionMatrix({ 0.0, toRadian(-90.0) - reference.latitude(), reference.longitude() }), velocityEcef, accelerationEcef);
}

void nedToBody(const Attitude &attitude, Xyz &accelerationNed, Attitude &angularVelocityNed, Attitude &angularVelocityCorrection)
{
  applyRotationMatrixTo(conversionMatrix(attitude), accelerationNed, angularVelocityCorrection);
  applyRotationMatrixTo(conversionMatrix2(attitude), angularVelocityNed);
}

void bodyToImu(const Attitude &angularOffset, Xyz &accelerationBody, Attitude &angularVelocityBody)
{
  applyRotationMatrixTo(conversionMatrix(angularOffset), accelerationBody, angularVelocityBody);
}

void bodyInertialTruth(InertialData &data)
{
  const Lla positionLla = toLla(data.position);

  ecefToNed(positionLla, data.velocity, data.acceleration);

  Attitude angularVelocityCorrection { 0.0, 0.0, 0.0 };

  coriolis(positionLla, data.velocity, data.acceleration, angularVelocityCorrection);

  gravity(positionLla, data.acceleration);

  nedToBody(data.attitude, data.acceleration, data.angularVelocity, angularVelocityCorrection);

  data.angularVelocity += angularVelocityCorrection;
}

} // namespace Iml
