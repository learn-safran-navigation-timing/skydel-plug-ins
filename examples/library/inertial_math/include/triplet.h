#ifndef IML_TRIPLET_H
#define IML_TRIPLET_H

#include <blaze/Math.h>

namespace Iml
{
using Triplet = blaze::StaticVector<double, 3, blaze::rowVector>;

inline double roll(const Triplet& triplet)
{
  return triplet.at(0);
}
inline double pitch(const Triplet& triplet)
{
  return triplet.at(1);
}
inline double yaw(const Triplet& triplet)
{
  return triplet.at(2);
}

inline double x(const Triplet& triplet)
{
  return triplet.at(0);
}
inline double y(const Triplet& triplet)
{
  return triplet.at(1);
}
inline double z(const Triplet& triplet)
{
  return triplet.at(2);
}

inline double north(const Triplet& triplet)
{
  return triplet.at(0);
}
inline double east(const Triplet& triplet)
{
  return triplet.at(1);
}
inline double down(const Triplet& triplet)
{
  return triplet.at(2);
}

inline double latitude(const Triplet& triplet)
{
  return triplet.at(0);
}
inline double longitude(const Triplet& triplet)
{
  return triplet.at(1);
}
inline double altitude(const Triplet& triplet)
{
  return triplet.at(2);
}

} // namespace Iml

#endif // IML_TRIPLET_H
