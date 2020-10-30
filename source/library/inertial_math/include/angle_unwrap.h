#ifndef IML_ANGLE_UNWRAP_H
#define IML_ANGLE_UNWRAP_H

#include "triplet.h"

namespace Iml {

Attitude unwrap(const Attitude &previous, const Attitude &current, Attitude &correction);
double unwrap(double previous, double current, double &correction);
double phaseCorrection(double previous, double current);

} // namespace Iml

#endif // IML_ANGLE_UNWRAP_H
