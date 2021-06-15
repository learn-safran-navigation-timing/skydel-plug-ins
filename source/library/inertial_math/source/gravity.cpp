#include "gravity.h"

#include "constant.h"
#include "coriolis_force.h"
#include "utility.h"

namespace Iml
{
double gravityWGS84(double latitude, double altitude)
{
  double geocentricLatitude = std::atan(std::pow(SEMI_MINOR_AXIS, 2.0) / std::pow(SEMI_MAJOR_AXIS, 2.0) *
                                        std::tan(latitude));
  double radius = SEMI_MAJOR_AXIS * (1.0 - FLATTENING * sin2(geocentricLatitude)) - altitude;

  return -(-GEOCENTRIC_GRAVITATIONAL_CONSTANT / std::pow(radius, 2.0) *
             (1.0 - 3.0 * DERIVED_DYNAMIC_FORM_FACTOR * std::pow(SEMI_MAJOR_AXIS, 2.0) / (2.0 * std::pow(radius, 2.0)) *
                      (3.0 * sin2(geocentricLatitude) - 1.0)) +
           std::pow(ROTATION_RATE, 2.0) * radius * cos2(geocentricLatitude));
}

double gravityGRS67(double latitude, double altitude)
{
  double geocentricLatitude = std::atan(std::pow(SEMI_MINOR_AXIS, 2.0) / std::pow(SEMI_MAJOR_AXIS, 2.0) *
                                        std::tan(latitude));

  return NORMAL_GRAVITY_AT_EQUATOR *
         (1.0 + WRS67_COEFFICIENT_A * sin2(geocentricLatitude) + WRS67_COEFFICIENT_B * sin2(2.0 * geocentricLatitude)) /
         std::pow(1.0 + (altitude / earthMeanRadiusOfCurvature(geocentricLatitude)), 2.0);
}

Triplet nedAccelerationFromGravity(const Triplet& llaPosition, GravityModel gravityModel)
{
  auto gravityFunction = &gravityGRS67;
  if (gravityModel == WGS84)
    gravityFunction = &gravityWGS84;
  return {0, 0, gravityFunction(latitude(llaPosition), altitude(llaPosition))};
}

} // namespace Iml
