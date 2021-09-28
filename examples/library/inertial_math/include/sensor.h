#ifndef IML_SENSOR_H
#define IML_SENSOR_H

#include "gravity.h"
#include "triplet.h"

namespace Iml
{
/**
 * @brief Simulate the output of an ideal accelerometer.
 *
 * @param llaPosition      LLA position in radian, radian and meter.
 * @param ecefVelocity     ECEF velocity in meter/second^2.
 * @param ecefAcceleration ECEF acceleration in meter/second^2.
 * @param attitude         ECEF attitude in radian.
 * @param gravityModel     Gravity model used.
 * @return Proper acceleration in meter/second^2.
 */
Triplet idealAccelerometer(const Triplet& llaPosition,
                           const Triplet& ecefVelocity,
                           const Triplet& ecefAcceleration,
                           const Triplet& attitude,
                           GravityModel gravityModel);

/**
 * @brief Simulate the output of an ideal gyroscope.
 *
 * @param llaPosition        LLA position in radian, radian and meter.
 * @param ecefVelocity       ECEF velocity in meter/second^2.
 * @param attitude           Attitude in radian.
 * @param nedAngularVelocity NED angular velocity in radian/second.
 * @return Proper angular velocity in radian/second.
 */
Triplet idealGyroscope(const Triplet& llaPosition,
                       const Triplet& ecefVelocity,
                       const Triplet& attitude,
                       const Triplet& nedAngularVelocity);

} // namespace Iml

#endif // IML_SENSOR_H
