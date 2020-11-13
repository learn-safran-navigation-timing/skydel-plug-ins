#ifndef IML_GRAVITY_H
#define IML_GRAVITY_H

#include "triplet.h"

namespace Iml {

/**
 * @brief Compute the Earth gravity as a function of latitude and altitude.
 * 
 * @param latitude Latitude in radian.
 * @param altitude Altitude in meter.
 * @return Gavity in meter/second^2.
 */
double gravity(double latitude, double altitude);

/**
 * @brief Compute NED acceleration due to Earth gravity based on the LLA position.
 * 
 * @param llaPosition LLA position in radian, radian and meter.
 * @return NED acceleration due to Earth gravity in meter/second^2.
 */
Triplet nedAccelerationFromGravity(const Triplet &llaPosition);

} // namespace Iml

#endif // IML_GRAVITY_H
