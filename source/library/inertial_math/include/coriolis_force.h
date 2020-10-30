#ifndef IML_CORIOLIS_FORCE_H
#define IML_CORIOLIS_FORCE_H

#include "rotation_matrix.h"
#include "triplet.h"

namespace Iml {

void coriolis(const Lla &position, const Xyz &velocityNed, Xyz &acceleration, Attitude &angularVelocity);
RotationMatrix coriolisForce(const Triplet &earthRate);
Triplet earthRate(double latitude);
Triplet transportRate(double eastVelocity, double northVelocity, double latitude, double altitude);
double eastMeridianRadius(double latitude);
double northMeridianRadius(double latitude);

} // namespace Iml

#endif // IML_CORIOLIS_FORCE_H
