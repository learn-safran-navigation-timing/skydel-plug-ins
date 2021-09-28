#ifndef IML_UTILITY_H
#define IML_UTILITY_H

#include <cmath>

#include "constant.h"

namespace Iml
{
/**
 * @brief Compute the slope that defines the transition from point a to point b over a distance t.
 *
 * @tparam Point Type.
 * @param a First point.
 * @param b Second point.
 * @param t Distance between the two points.
 * @return Resulting slope.
 */
template<typename T>
T slope(const T& a, const T& b, double t)
{
  return (b - a) / t;
}

/**
 * @brief Convert an angle from radian to degree.
 *
 * @tparam T Type must support decimal precision, operator+ and operator/
 * @param radian Angle in radian.
 * @return Angle in degree.
 */
template<typename T>
T toDegree(const T& radian)
{
  return radian * 180.0 / PI;
}

/**
 * @brief Convert an angle from degree to radian.
 *
 * @tparam T Angle type.
 * @param degree Angle in degree.
 * @return Angle in radian.
 */
template<typename T>
T toRadian(const T& degree)
{
  return degree * PI / 180.0;
}

/**
 * @brief Compute the cosine squared.
 *
 * @tparam T Angle type.
 * @param angle Angle in radian.
 * @return Cosine squared of the angle.
 */
template<typename T>
T cos2(const T& angle)
{
  return std::pow(std::cos(angle), 2.0);
}

/**
 * @brief Compute the sine squared.
 *
 * @tparam T Angle type.
 * @param angle Angle in radian.
 * @return Sine squared of the angle.
 */
template<typename T>
T sin2(const T& angle)
{
  return std::pow(std::sin(angle), 2.0);
}

} // namespace Iml

#endif // IML_UTILITY_H
