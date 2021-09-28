#include "rotation_matrix.h"

namespace Iml
{
RotationMatrix rotationMatrixForElementalRotation(double angle, Axis axis)
{
  switch (axis)
  {
    case Axis::X:
    {
      return {{1.0, 0.0, 0.0}, {0.0, std::cos(angle), std::sin(angle)}, {0.0, -std::sin(angle), std::cos(angle)}};
    }
    case Axis::Y:
    {
      return {{std::cos(angle), 0.0, -std::sin(angle)}, {0.0, 1.0, 0.0}, {std::sin(angle), 0.0, std::cos(angle)}};
    }
    case Axis::Z:
    default:
    {
      return {{std::cos(angle), std::sin(angle), 0.0}, {-std::sin(angle), std::cos(angle), 0.0}, {0.0, 0.0, 1.0}};
    }
  }
}

RotationMatrix rotationMatrixForXYZRotation(const Triplet& angles)
{
  return rotationMatrixForElementalRotation(roll(angles), Axis::X) *
         rotationMatrixForElementalRotation(pitch(angles), Axis::Y) *
         rotationMatrixForElementalRotation(yaw(angles), Axis::Z);
}

Triplet rotate(const RotationMatrix& rotationMatrix, const Triplet& triplet)
{
  return trans(rotationMatrix * trans(triplet));
}

} // namespace Iml
