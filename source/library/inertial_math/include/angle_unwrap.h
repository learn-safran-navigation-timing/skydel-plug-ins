#ifndef IML_ANGLE_UNWRAP_H
#define IML_ANGLE_UNWRAP_H

#include "triplet.h"

namespace Iml
{
/**
 * @brief Whenever the jump between consecutive angles is greater than Pi radians,
 *        unwrap shifts the current angle by adding multiples of +/- 2Pi until the jump is less than Pi.
 *        For more information about unwrapping, see https://ccrma.stanford.edu/~jos/filters/Phase_Unwrapping.html
 *
 * @param[in]     previousAngle Previous angle in radian.
 * @param[in]     currentAngle  Current angle in radian.
 * @param[in,out] correction    [in]  Previous phase correction in radian.
 *                              [out] Updated phase correction in radian.
 * @return Corrected current angle.
 */
double unwrap(double previousAngle, double currentAngle, double& correction);

/**
 * @brief Apply unwrap on Triplet.
 *
 * @param[in]      previousAngles Previous angles in radian.
 * @param[in]      currentAngles  Current angles in radian.
 * @param[in,out]  corrections    [in]  Previous phase corrections in radian.
 *                                [out] Updated phase corrections in radian.
 * @return Corrected current angles.
 */
Triplet unwrap(const Triplet& previousAngles, const Triplet& currentAngles, Triplet& corrections);

/**
 * @brief Compute a multiple of +/- 2Pi from the difference between previous and current angles.
 *        Used to find a current angle which difference is less than +/- Pi from the previous angle.
 *
 * @param previousAngle Previous angle in radian.
 * @param currentAngle  Current angle in radian.
 * @return Rounded difference between previous and current angle.
 */
double roundDifferenceToClosest2PiMultiple(double previousAngle, double currentAngle);

} // namespace Iml

#endif // IML_ANGLE_UNWRAP_H
