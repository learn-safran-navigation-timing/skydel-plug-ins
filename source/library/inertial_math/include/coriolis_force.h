#ifndef IML_CORIOLIS_FORCE_H
#define IML_CORIOLIS_FORCE_H

#include "rotation_matrix.h"
#include "triplet.h"

namespace Iml
{
/**
 * @brief Compute NED angular velocity due to coriolis force.
 *
 * @param llaPosition LLA position in radian, radian and meter.
 * @param nedVelocity NED velocity in meter/second.
 * @return NED angular velocity due to the coriolis force in radian/second.
 */
Triplet nedAngularVelocityFromCoriolisForce(const Triplet& llaPosition, const Triplet& nedVelocity);

/**
 * @brief Compute NED acceleration due to coriolis force/
 *
 * @param llaPosition LLA position in radian, radian and meter.
 * @param nedVelocity NED velocity in meter/second.
 * @return NED acceleration due to the coriolis force in meter/second^2.
 */
Triplet nedAccelerationFromCoriolisForce(const Triplet& llaPosition, const Triplet& nedVelocity);
/**
 * @brief Compute the coriolis force skew symmetric matrix based on NED Earth rate.
 *
 * @param nedEarthRate NED Earth rate in radian/second.
 * @return Coriolis force skew symmetric matrix.
 */
RotationMatrix coriolisForceSkewSymmetricMatrix(const Triplet& nedEarthRate);

/**
 * @brief Compute the transport rate of the Earth relative to LLA position and NED velocity.
 *
 * @param eastVelocity   East velocity in meter/second.
 * @param northVelocity  North velocity in meter/second.
 * @param latitude       Latitude in radian.
 * @param altitude       Altitude in meter.
 * @return Transport rate in radian/second.
 */
Triplet transportRate(double eastVelocity, double northVelocity, double latitude, double altitude);

/**
 * @brief Compute the Earth rate resolved into the local NED frame.
 *
 * @param latitude Latitude in radian.
 * @return Earth rate in radian/second.
 */
Triplet earthRate(double latitude);

/**
 * @brief Compute the Earth prime vertical(east/west) radius of curvature based the refenrece ellipsoid WSG-84.
 *
 * @param latitude Latitude in radian.
 * @return Earth prime vertial radius of curvature in radian.
 */
double earthPrimeVerticalRadiusOfCurvature(double latitude);

/**
 * @brief Compute the Earth meridian(north/south) radius of curvature based the refenrece ellipsoid WSG-84.
 *
 * @param latitude Latitude in radian.
 * @return Earth meridian radius of curvature in radian.
 */
double earthMeridianRadiusOfCurvature(double latitude);

/**
 * @brief Compute the Earth mean radius of curvature based the refenrece ellipsoid WSG-84.
 *
 * @param latitude Latitude in radian.
 * @return Earth mean radius of curvature in radian.
 */
double earthMeanRadiusOfCurvature(double latitude);

} // namespace Iml

#endif // IML_CORIOLIS_FORCE_H
