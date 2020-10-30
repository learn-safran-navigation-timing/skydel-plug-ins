#ifndef IML_TRANSFORMATION_H
#define IML_TRANSFORMATION_H

#include "dynamic.h"
#include "rotation_matrix.h"
#include "triplet.h"

namespace Iml {

enum Axis { X, Y, Z };

RotationMatrix conversionMatrix(const Triplet &angles);
RotationMatrix rotationArroundAxis(double angle, Axis axis);
RotationMatrix accelerationOffsetRotationMatrix(double p, double q, double r, double dp, double dq, double dr);
Xyz accelerationOffset(const Attitude &currentVelocity, const Attitude &previousVelocity, const Xyz &offset, double t);
double primeVerticalRadiusOfCurvature(double latitude);
Lla toLla(const Xyz &ecef);
void ecefToNed(const Lla &reference, Xyz &velocityEcef, Xyz &accelerationEcef);
void nedToBody(const Attitude &attitude, Xyz &accelerationNed, Attitude &angularVelocityNed, Attitude &angularVelocityCorrection);
void bodyToImu(const Attitude &angularOffset, Xyz &accelerationBody, Attitude &angularVelocityBody);
void bodyInertialTruth(InertialData &data);

} // namespace Iml

#endif // IML_TRANSFORMATION_H
