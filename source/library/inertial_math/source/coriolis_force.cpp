#include "coriolis_force.h"

#include "constant.h"
#include "utility.h"

namespace Iml {

void coriolis(const Lla &position, const Xyz &velocityNed, Xyz &acceleration, Attitude &angularVelocity)
{
  Triplet er = earthRate(position.latitude());
  Triplet tr = transportRate(velocityNed.y(), velocityNed.x(), position.latitude(), position.altitude());

  acceleration += applyRotationMatrix(velocityNed, coriolisForce(er));
  angularVelocity = er + tr;
}

RotationMatrix coriolisForce(const Triplet &earthRate)
{
  return 2.0 * SkewSymmetricMatrix(earthRate);
}

Triplet earthRate(double latitude)
{
  return Triplet { std::cos(latitude), 0.0, -std::sin(latitude) } * EARTH_ANGULAR_VELOCITY;
}

Triplet transportRate(double eastVelocity, double northVelocity, double latitude, double altitude)
{
  double re = eastMeridianRadius(latitude);
  double rn = northMeridianRadius(latitude);
  return { eastVelocity / (re + altitude),
           -northVelocity / (rn + altitude),
           -eastVelocity * std::tan(latitude) / (re + altitude) };
}

double eastMeridianRadius(double latitude)
{
  return SEMI_MAJOR_AXIS / std::pow(1.0 - FIRST_ECCENTRICITY_SQUARED * sin2(latitude), 0.5);
}

double northMeridianRadius(double latitude)
{
  return SEMI_MAJOR_AXIS * (1.0 - FIRST_ECCENTRICITY_SQUARED) / std::pow(1.0 - FIRST_ECCENTRICITY_SQUARED * sin2(latitude), 1.5);
}

} // namespace Iml
