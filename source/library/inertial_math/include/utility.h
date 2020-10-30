#ifndef IML_UTILITY_H
#define IML_UTILITY_H

#include <cmath>

#include "constant.h"

namespace Iml {

template<typename T>
T slope(const T &a, const T &b, double t)
{
  return (b - a) / t;
}

template<typename T>
T toDegree(T radian)
{
  return radian * 180.0 / PI;
}

template<typename T>
T toRadian(T degree)
{
  return degree * PI / 180.0;
}

template<typename T>
T cos2(T angle)
{
  return std::pow(std::cos(angle), 2.0);
}

template<typename T>
T sin2(T angle)
{
  return std::pow(std::sin(angle), 2.0);
}

} // namespace Iml

#endif // IML_UTILITY_H
