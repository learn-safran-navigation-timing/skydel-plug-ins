#include "coriolis_force.h"

#include "constant.h"
#include "utility.h"

namespace Iml
{
Triplet nedAngularVelocityFromCoriolisForce(const Triplet& llaPosition, const Triplet& nedVelocity)
{
  return earthRate(latitude(llaPosition)) +
         transportRate(east(nedVelocity), north(nedVelocity), latitude(llaPosition), altitude(llaPosition));
}

Triplet nedAccelerationFromCoriolisForce(const Triplet& llaPosition, const Triplet& nedVelocity)
{
  return rotate(coriolisForceSkewSymmetricMatrix(earthRate(latitude(llaPosition))), nedVelocity);
}

RotationMatrix coriolisForceSkewSymmetricMatrix(const Triplet& nedEarthRate)
{
  return 2.0 * RotationMatrix {{0.0, -down(nedEarthRate), east(nedEarthRate)},
                               {down(nedEarthRate), 0.0, -north(nedEarthRate)},
                               {-east(nedEarthRate), north(nedEarthRate), 0.0}};
}

Triplet transportRate(double eastVelocity, double northVelocity, double latitude, double altitude)
{
  double re = earthPrimeVerticalRadiusOfCurvature(latitude);
  double rn = earthMeridianRadiusOfCurvature(latitude);
  return {eastVelocity / (re + altitude),
          -northVelocity / (rn + altitude),
          -eastVelocity * std::tan(latitude) / (re + altitude)};
}

Triplet earthRate(double latitude)
{
  return Triplet {std::cos(latitude), 0.0, -std::sin(latitude)} * EARTH_ANGULAR_VELOCITY;
}

double earthPrimeVerticalRadiusOfCurvature(double latitude)
{
  return SEMI_MAJOR_AXIS / std::pow(1.0 - FIRST_ECCENTRICITY_SQUARED * sin2(latitude), 0.5);
}

double earthMeridianRadiusOfCurvature(double latitude)
{
  return SEMI_MAJOR_AXIS * (1.0 - FIRST_ECCENTRICITY_SQUARED) /
         std::pow(1.0 - FIRST_ECCENTRICITY_SQUARED * sin2(latitude), 1.5);
}

double earthMeanRadiusOfCurvature(double latitude)
{
  return std::sqrt(earthPrimeVerticalRadiusOfCurvature(latitude) * earthMeridianRadiusOfCurvature(latitude));
}

} // namespace Iml
