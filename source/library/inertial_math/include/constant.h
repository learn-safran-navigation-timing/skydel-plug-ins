#ifndef IML_CONSTANT_H
#define IML_CONSTANT_H

#include <cmath>

namespace Iml
{
// General
inline constexpr double PI = 3.14159265358979323846;

// Earth Model - WGS 84
inline constexpr double FLATTENING = 1.0 / 298.257223563;
inline constexpr double FIRST_ECCENTRICITY_SQUARED = 6.69437999014e-3;
inline constexpr double SECOND_ECCENTRICITY_SQUARED = 6.7394967422764341e-3;
inline constexpr double EARTH_ANGULAR_VELOCITY = 7.2921155e-5;              // rad/s
inline constexpr double SEMI_MAJOR_AXIS = 6378137.0;                        // m
inline constexpr double SEMI_MINOR_AXIS = 6356752.314245;                   // m
inline constexpr double POLAR_RADIUS_OF_CURVATURE = 6399593.6257584924;     // m
inline constexpr double GEOCENTRIC_GRAVITATIONAL_CONSTANT = 3.986004418e14; // m^3 / s^2
inline constexpr double DERIVED_DYNAMIC_FORM_FACTOR = 1.081874e-3;
inline constexpr double ROTATION_RATE = 7.2921155e-5; // rad/s

// Geodetic Reference System 1967
inline constexpr double NORMAL_GRAVITY_AT_EQUATOR = 9.780318; // m/s^2
inline constexpr double WRS67_COEFFICIENT_A = 5.3024e-03;
inline constexpr double WRS67_COEFFICIENT_B = -5.9e-06;

} // namespace Iml

#endif // IMU_CONSTANT_H
