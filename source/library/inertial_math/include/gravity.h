#ifndef IML_GRAVITY_H
#define IML_GRAVITY_H

#include <stdexcept>

#include "triplet.h"

namespace Iml
{
enum GravityModel
{
  WGS84,
  GRS67
};

const GravityModel ALL_GRAVITY_MODEL[] = {GravityModel::WGS84, GravityModel::GRS67};

inline const char* toString(GravityModel gravityModel)
{
  switch (gravityModel)
  {
    case GravityModel::WGS84:
      return "WGS84";
    case GravityModel::GRS67:
      return "GRS67";
  }
  throw std::runtime_error {"Unknown GravityModel"};
}

/**
 * @brief Compute the Earth gravity as a function of latitude and altitude
 *        based on WGS84.
 *
 * @param latitude Latitude in radian.
 * @param altitude Altitude in meter.
 * @return Gavity in meter/second^2.
 */
double gravityWGS84(double latitude, double altitude);

/**
 * @brief Compute the Earth gravity as a function of latitude and altitude based on
 *        the normal gravity formula of Geodetic Reference System 1967.
 *
 * @param latitude Latitude in radian.
 * @param altitude Altitude in meter.
 * @return Gavity in meter/second^2.
 */
double gravityGRS67(double latitude, double altitude);

/**
 * @brief Compute NED acceleration due to Earth gravity based on the LLA position.
 *
 * @param llaPosition  LLA position in radian, radian and meter.
 * @param gravityModel Gravity model used.
 * @return NED acceleration due to Earth gravity in meter/second^2.
 */
Triplet nedAccelerationFromGravity(const Triplet& llaPosition, GravityModel gravityModel);

} // namespace Iml

#endif // IML_GRAVITY_H
