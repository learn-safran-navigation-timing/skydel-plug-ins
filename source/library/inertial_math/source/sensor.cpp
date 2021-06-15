#include "sensor.h"

#include "coriolis_force.h"
#include "gravity.h"
#include "transformation.h"

namespace Iml
{
Triplet idealAccelerometer(const Triplet& llaPosition,
                           const Triplet& ecefVelocity,
                           const Triplet& ecefAcceleration,
                           const Triplet& attitude,
                           GravityModel gravityModel)
{
  auto nedVelocity = ecefToNed(llaPosition, ecefVelocity);
  auto nedAcceleration = ecefToNed(llaPosition, ecefAcceleration);

  nedAcceleration += nedAccelerationFromCoriolisForce(llaPosition, nedVelocity);

  nedAcceleration -= nedAccelerationFromGravity(llaPosition, gravityModel);

  return nedToBodyFromXYZRotation(attitude, nedAcceleration);
}

Triplet idealGyroscope(const Triplet& llaPosition,
                       const Triplet& ecefVelocity,
                       const Triplet& attitude,
                       const Triplet& nedAngularVelocity)
{
  auto nedVelocity = ecefToNed(llaPosition, ecefVelocity);

  auto nedAngularVelocityCorrection = nedAngularVelocityFromCoriolisForce(llaPosition, nedVelocity);

  auto bodyAngularVelocity = nedToBody(attitude, nedAngularVelocity);

  bodyAngularVelocity += nedToBodyFromXYZRotation(attitude, nedAngularVelocityCorrection);

  return bodyAngularVelocity;
}

} // namespace Iml
