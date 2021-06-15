#ifndef IML_TRANSFORMATION_H
#define IML_TRANSFORMATION_H

#include "dynamic.h"
#include "triplet.h"

namespace Iml
{
/**
 * @brief Convert triplet from geocentric Earth-centered Earth-fixed (ECEF) to geodetic (LLA).
 *
 * @param ecef ECEF triplet in meter.
 * @return LLA triplet in radian, radian and meter.
 */
Triplet ecefToLla(const Triplet& ecef);

/**
 * @brief Convert triplet from geocentric Earth-centered Earth-fixed (ECEF) to local north-east-down (NED).
 *
 * @param llaOrigin Geodetic coordinate (LLA) of local NED system origin in radian, radian and meter.
 * @param ecef ECEF triplet in meter.
 * @return NED triplet in meter.
 */
Triplet ecefToNed(const Triplet& llaOrigin, const Triplet& ecef);

/**
 * @brief Convert triplet from local north-east-down (NED) to body via x-y-z axis rotation.
 *
 * @param attitude Attitude triplet in radian.
 * @param ned      NED triplet.
 * @return Body triplet.
 */
Triplet nedToBodyFromXYZRotation(const Triplet& attitude, const Triplet& ned);

/**
 * @brief Convert angular velocity from local north-east-down (NED) to body.
 *
 * @param attitude Attitude triplet in radian.
 * @param ned      NED triplet.
 * @return Body triplet.
 */
Triplet nedToBody(const Triplet& attitude, const Triplet& ned);

} // namespace Iml

#endif // IML_TRANSFORMATION_H
