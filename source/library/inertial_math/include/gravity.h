#ifndef IML_GRAVITY_H
#define IML_GRAVITY_H

#include "triplet.h"

namespace Iml {

double gravity(double latitude, double altitude);
void gravity(const Lla &lla, Xyz &xyz);

} // namespace Iml

#endif // IML_GRAVITY_H
