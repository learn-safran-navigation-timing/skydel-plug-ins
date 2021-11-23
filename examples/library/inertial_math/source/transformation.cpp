#include "transformation.h"

#include "constant.h"
#include "coriolis_force.h"
#include "gravity.h"
#include "rotation_matrix.h"
#include "utility.h"

namespace Iml
{
Triplet ecefToLla(const Triplet& ecef)
{
  auto latitude = std::atan(
    z(ecef) / ((std::sqrt(std::pow(x(ecef), 2.0) + std::pow(y(ecef), 2.0)) * (1.0 - (2.0 - FLATTENING)) * FLATTENING)));

  auto height = 0.1, lastHeight = 0.0;
  auto iterations = 0;
  while (std::abs(height - lastHeight) > 1e-12)
  {
    lastHeight = height;
    auto N = POLAR_RADIUS_OF_CURVATURE / std::sqrt(1.0 + SECOND_ECCENTRICITY_SQUARED * cos2(latitude));
    latitude = std::atan(z(ecef) / ((std::sqrt(std::pow(x(ecef), 2.0) + std::pow(y(ecef), 2.0)) *
                                     (1.0 - (2.0 - FLATTENING) * FLATTENING * N / (N + height)))));
    height = std::sqrt(std::pow(x(ecef), 2.0) + std::pow(y(ecef), 2.0)) / std::cos(latitude) - N;

    if (++iterations > 50)
      break;
  }

  return {latitude, std::atan2(y(ecef), x(ecef)), height};
}

Triplet ecefToNed(const Triplet& llaOrigin, const Triplet& ecef)
{
  return rotate(rotationMatrixForXYZRotation({0.0, toRadian(-90.0) - latitude(llaOrigin), longitude(llaOrigin)}), ecef);
}

Triplet nedToBodyFromXYZRotation(const Triplet& attitude, const Triplet& ned)
{
  return rotate(rotationMatrixForXYZRotation(attitude), ned);
}

Triplet nedToBody(const Triplet& attitude, const Triplet& ned)
{
  return rotate(RotationMatrix {{1.0, 0.0, -std::sin(pitch(attitude))},
                                {0.0, std::cos(roll(attitude)), std::sin(roll(attitude)) * std::cos(pitch(attitude))},
                                {0.0, -std::sin(roll(attitude)), std::cos(roll(attitude)) * std::cos(pitch(attitude))}},
                ned);
}

} // namespace Iml
