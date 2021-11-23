#include "angle_unwrap.h"

#include <cmath>

#include "constant.h"

namespace Iml
{
double unwrap(double previousAngle, double currentAngle, double& correction)
{
  correction += roundDifferenceToClosest2PiMultiple(previousAngle, currentAngle);

  return currentAngle - correction;
}

Triplet unwrap(const Triplet& previousAngles, const Triplet& currentAngles, Triplet& corrections)
{
  return {unwrap(previousAngles[0], currentAngles[0], corrections[0]),
          unwrap(previousAngles[1], currentAngles[1], corrections[1]),
          unwrap(previousAngles[2], currentAngles[2], corrections[2])};
}

double roundDifferenceToClosest2PiMultiple(double previousAngle, double currentAngle)
{
  double delta = currentAngle - previousAngle;
  if (std::abs(delta) > PI)
  {
    if (currentAngle <= 0.0)
    {
      return 2.0 * PI * std::floor(delta / (2.0 * PI));
    }
    else
    {
      return 2.0 * PI * std::ceil(delta / (2.0 * PI));
    }
  }

  return 0.0;
}

} // namespace Iml
