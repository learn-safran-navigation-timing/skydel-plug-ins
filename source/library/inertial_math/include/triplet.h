#ifndef IML_TRIPLET_H
#define IML_TRIPLET_H

#include <blaze_math.h>

namespace Iml {

typedef blaze::StaticVector<double, 3, blaze::rowVector> Triplet;

class Attitude : public Triplet
{
public:
  using Triplet::Triplet;

  inline double roll()  const { return at(0); }
  inline double pitch() const { return at(1); }
  inline double yaw()   const { return at(2); }
};

class Xyz : public Triplet
{
public:
  using Triplet::Triplet;

  inline double x() const { return at(0); }
  inline double y() const { return at(1); }
  inline double z() const { return at(2); }
};

class Lla : public Triplet
{
public:
  using Triplet::Triplet;

  inline double latitude()  const { return at(0); }
  inline double longitude() const { return at(1); }
  inline double altitude()  const { return at(2); }
};

} // namespace Iml

#endif // IML_TRIPLET_H
