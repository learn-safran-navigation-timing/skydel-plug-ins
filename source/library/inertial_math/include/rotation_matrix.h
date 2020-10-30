#ifndef IML_ROTATION_MATRIX_H
#define IML_ROTATION_MATRIX_H

#include <blaze_math.h>

#include "triplet.h"

namespace Iml {

typedef blaze::StaticMatrix<double, 3, 3> RotationMatrix;

template<typename T>
T applyRotationMatrix(const T &triplet, const RotationMatrix &rotationMatrix)
{
  return trans(rotationMatrix * trans(triplet));
}

template<typename T>
void applyRotationMatrixTo(const RotationMatrix &rotationMatrix, T &triplet)
{
  triplet = applyRotationMatrix(triplet, rotationMatrix);
}

template<typename T,  typename... Args>
void applyRotationMatrixTo(const RotationMatrix &rotationMatrix, T &triplet, Args&... args)
{
  applyRotationMatrixTo(rotationMatrix, triplet);
  applyRotationMatrixTo(rotationMatrix, args...);
}

class SkewSymmetricMatrix : public RotationMatrix
{
public:
  SkewSymmetricMatrix(const Triplet &a) :
    RotationMatrix({ {  0.0,  -a[2],  a[1] },
                     {  a[2],  0.0,  -a[0] },
                     { -a[1],  a[0],  0.0  } })
  {}
};


} // namespace Iml

#endif // IML_ROTATION_MATRIX_H
