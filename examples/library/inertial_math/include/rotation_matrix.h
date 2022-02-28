#ifndef IML_ROTATION_MATRIX_H
#define IML_ROTATION_MATRIX_H

#include <blaze/Math.h>

#include <cmath>

#include "triplet.h"

namespace Iml
{
using RotationMatrix = blaze::StaticMatrix<double, 3, 3>;

enum class Axis
{
  X,
  Y,
  Z
};

/**
 * @brief Generate a rotation matrix for rotation around a single axis.
 *
 * @param angle Rotation angle around the axis in radian.
 * @param axis  Axis to rotate around.
 * @return Rotation matrix for elemental rotation a single axis.
 */
RotationMatrix rotationMatrixForElementalRotation(double angle, Axis axis);

/**
 * @brief Generate a rotation matrix for rotation around x-y-z axis.
 *
 * @param angles Rotation angles around x-y-z axis in radian.
 * @return Rotation matrix for rotation around x-y-z axis.
 */
RotationMatrix rotationMatrixForXYZRotation(const Triplet& angles);

/**
 * @brief Perform a rotation of a triplet with a rotation matrix.
 *
 * @param rotationMatrix Rotation matrix.
 * @param triplet        Triplet.
 * @return Rotated triplet.
 */
Triplet rotate(const RotationMatrix& rotationMatrix, const Triplet& triplet);

} // namespace Iml

#endif // IML_ROTATION_MATRIX_H
