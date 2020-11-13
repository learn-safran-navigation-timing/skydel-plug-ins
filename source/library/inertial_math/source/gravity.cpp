#include "gravity.h"

#include "constant.h"
#include "utility.h"

namespace Iml {

double gravity(double latitude, double altitude)
{
  double geocentricLatitude = std::atan(std::pow(SEMI_MINOR_AXIS, 2.0) / std::pow(SEMI_MAJOR_AXIS, 2.0) * std::tan(latitude));
  double radius = SEMI_MAJOR_AXIS * (1.0 - FLATTENING * sin2(geocentricLatitude)) - altitude;

  return  -(-GEOCENTRIC_GRAVITATIONAL_CONSTANT / std::pow(radius, 2.0) *
          (1.0 - 3.0 * DERIVED_DYNAMIC_FORM_FACTOR * std::pow(SEMI_MAJOR_AXIS, 2.0) / (2.0 * std::pow(radius, 2.0)) * (3.0 * sin2(geocentricLatitude) - 1.0)) +
          std::pow(ROTATION_RATE, 2.0) * radius * cos2(geocentricLatitude));
}

Triplet nedAccelerationFromGravity(const Triplet &llaPosition)
{
  return { 0.0, 0.0, gravity(latitude(llaPosition), altitude(llaPosition)) };
}

} // namespace Iml
