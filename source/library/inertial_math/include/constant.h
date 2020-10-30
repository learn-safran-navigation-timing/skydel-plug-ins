#ifndef IML_CONSTANT_H
#define IML_CONSTANT_H

#include <cmath>

namespace Iml {

// General
const double PI = 3.14159265358979323846;

// Earth Model - WGS 84
const double FLATTENING = 1.0 / 298.257223563;
const double FIRST_ECCENTRICITY_SQUARED = 6.69437999014e-3;
const double SECOND_ECCENTRICITY_SQUARED = (2.0 - FLATTENING) * FLATTENING/ std::pow(1.0 - FLATTENING, 2.0);
const double EARTH_ANGULAR_VELOCITY = 7.292115e-5; // rad/s
const double SEMI_MAJOR_AXIS = 6378137.0; // m
const double SEMI_MINOR_AXIS = 6356752.314245; // m
const double POLAR_RADIUS_OF_CURVATURE = SEMI_MAJOR_AXIS * std::sqrt(1.0 + SECOND_ECCENTRICITY_SQUARED); // m
const double GEOCENTRIC_GRAVITATIONAL_CONSTANT = 3.986004418e14; // m^3 / s^2
const double DERIVED_DYNAMIC_FORM_FACTOR = 1.081874e-3;
const double ROTATION_RATE = 7.2921155e-5; // rad/s

} // namespace Iml

#endif // IMU_CONSTANT_H
