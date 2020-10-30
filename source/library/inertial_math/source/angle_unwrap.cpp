#include "angle_unwrap.h"

#include <cmath>

#include "constant.h"

namespace Iml {

Attitude unwrap(const Attitude &previous, const Attitude &current, Attitude &correction)
{
  return { unwrap(previous[0], current[0], correction[0]),
           unwrap(previous[1], current[1], correction[1]),
           unwrap(previous[2], current[2], correction[2]) };
}

double unwrap(double previous, double current, double &correction)
{
  correction += phaseCorrection(previous, current);

  return current - correction;
}

double phaseCorrection(double previous, double current)
{
  double delta = current - previous;
  if (std::abs(delta) > PI)
  {
    if (current <= 0.0)
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
