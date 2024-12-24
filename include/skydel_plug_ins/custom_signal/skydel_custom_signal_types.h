#pragma once

#include <cstdint>
#include <vector>

namespace Sdx::CS
{

struct InitData
{
  /*
   * startWeek and startSecondOfWeek are defining the simulation start time
   * startWeek is the week number relative to the epoch of the attached constellation
   * startSecondOfWeek is the second number in that week, between 0 and 604799.
   */
  uint32_t startWeek;
  uint32_t startSecondOfWeek;
  char pathToXml[512];   // NULL terminated string
  char xmlFileName[512]; // NULL terminated string
};

enum ConstellationEnum
{
  GPS,
  GALILEO,
  BEIDOU,
  CONSTELLATION_COUNT
};

struct GpsEphemeris
{
  double gpsTgd; // gps time group delay // seconds

  uint32_t iodc; // Issue of Data, Clock

  uint32_t codesOnL2;
  uint32_t l2PDataFlag;

  uint32_t svSignalHealth; // 0..31  (0 all signals ok)
  uint32_t svDataHealth;   // 0..7   (0 data data ok)

  uint32_t fitInterval;

  uint32_t uraIndex;
  uint32_t integrityStatusFlag; // bit (0 = ok)
  uint32_t l2CPhasing;          // bit

  double uraEdIndex;
  double uraNed0Index;
  double uraNed1Index;
  double uraNed2Index;

  bool iscL1CaAvailable;
  bool iscL2CAvailable;
  bool iscL5I5Available;
  bool iscL5Q5Available;
  bool iscL1CPAvailable;
  bool iscL1CDAvailable;
  double iscL1Ca; // seconds
  double iscL2C;  // seconds
  double iscL5I5; // seconds
  double iscL5Q5; // seconds
  double iscL1CP; // seconds
  double iscL1CD; // seconds

  uint8_t signalHealth;
  uint8_t dataHealth;
  int svConfig;
  bool l1Health;
  bool l2Health;
  bool l5Health;
  bool l1cHealth;
  bool navAlertFlag;
  bool cNavAlertFlag;
};

struct GalileoEphemeris
{
  double galileoBgdE5a; // galileo broadcast group delay E5a  // seconds
  double galileoBgdE5b; // galileo broadcast group delay E5b // seconds

  uint32_t sisaE5a;
  uint32_t sisaE5b;

  uint32_t signalHealthE5a;
  uint32_t signalHealthE5b;
  uint32_t signalHealthE1B;
  bool dataHealthE5a;
  bool dataHealthE5b;
  bool dataHealthE1B;
};

struct BeiDouEphemeris
{
  double beiDouTgd1;    // beidou time group delay 1 // seconds
  double beiDouTgd2;    // beidou time group delay 2 // seconds
  double beiDouTgdb1cp; // beiDou time group delay B1Cp // seconds
  double beiDouTgdb2ap; // beiDou time group delay B2ap // seconds

  uint32_t aodc;  // Age of Data, Clock
  uint32_t aode;  // Age of Data, Ephemeris
  uint32_t iodc;  // Issue of Data, Clock
  uint32_t satH2; // Satellite Health Flag for Integrity and Differential Correction Information
  bool iscB1CdAvailable;
  double iscB1Cd; // seconds
                  //  (2020/05) to add to the next version of the interface:
                  //  bool iscB2adAvailable;
                  //  double iscB2ad;          // seconds
  uint32_t uraIndex;

  uint16_t healthInfo;
  bool autonomousHealth;
  uint8_t cnavHealthInfo;
  uint8_t healthStatus;
};

struct GlonassEphemeris
{
  double t_lambda;     // reference time of almanac;
  double tau_c;        // correction from GLONASS to UTC;
  double tau_gps;      // correction to GPS time relative to GLONASS;
  double tau_n;        // correction of satellite time relative to GLONASS
  double lambda;       // longitude of first ascending node passage, in semi-cycles
  double delta_i;      // correction to the mean value of inclination, in semi-cycles
  double omega;        // argument of perigee, in semi-cycles
  double e;            // eccentricity
  double delta_t;      // correction of the mean value of Draconian period, in seconds
  double delta_t_rate; // rate of change of Draconian period, in seconds/coil

  double tauN;
  double svRelativeFrequencyBias;
  uint32_t messageFrameTime;
  uint32_t age;         // Age of oper. information  (days)
  double positionX;     // position (km)
  double positionY;     // position (km)
  double positionZ;     // position (km)
  double velocityX;     // velocity (km/s)
  double velocityY;     // velocity (km/s)
  double velocityZ;     // velocity (km/s)
  double accelerationX; // acceleration (km/s^2)
  double accelerationY; // acceleration (km/s^2)
  double accelerationZ; // acceleration (km/s^2)
};

struct Ephemeris
{
  uint32_t prn;

  uint32_t iod; // iode (Issue of Data, Ephemeris) or iodnav (Issue of Data of the nav batch)

  uint32_t wnop; // week num of prediction // gps weeks
  uint32_t top;  // time of predicition // seconds

  uint32_t wnoc; // week num of clock // gps weeks
  uint32_t toc;  // time of clock // seconds
  double af0;    // sv cock bias // seconds
  double af1;    // sv cock drift // sec/sec
  double af2;    // sv cock drift rate // sec/sec^2

  uint32_t wnoe; // week num of ephemeris // gps weeks
  uint32_t toe;  // time of ephemeris // seconds

  double sqrtA;             // square root semi major axis // sqrt(meters)
  double eccentricity;      // eccentricity // unitless
  double inclination;       // inclination angle // semi-circles
  double lonAscendNode;     // longitude of ascending node // semi-circles
  double rateOfRightAscen;  // rate of right ascension (bigOmegaDot) // semi-circles/sec^2
  double meanAnomaly;       // mean anomaly // semi-circles
  double argumentOfPerigee; // argument of perigee
  double meanMotionDiff;    // mean motion difference // semi-circles/sec

  double iDot;       // rate of inclination angle // semi-circles/sec
  double aDot;       // change rate in semi-major axis // meters/sec
  double deltaN0Dot; // rate of mean motion difference  // semi-circles/sec^2

  double crs; // correction radius sine // meters
  double crc; // correction radius cosine // meters
  double cuc; // correction argument lat sine // radians
  double cus; // correction argument lat sine // radians
  double cic; // correction inclination sine // radians
  double cis; // correction inclination sine // radians

  ConstellationEnum constellation;

  GpsEphemeris gpsEphemeris;
  GalileoEphemeris galileoEphemeris;
  BeiDouEphemeris beidouEphemeris;
  GlonassEphemeris glonassEphemeris;
};

///
/// Terms for ionospheric corrections
///
struct IonosphereTerms
{
  double alpha0; // seconds
  double alpha1; // seconds/semi-circle
  double alpha2; // seconds/semi-circle^2
  double alpha3; // seconds/semi-circle^3
  double beta0;  // seconds
  double beta1;  // seconds/semi-circle
  double beta2;  // seconds/semi-circle^2
  double beta3;  // seconds/semi-circle^3
};

///
/// Terms for UTC calculation
///
struct UtcTerms
{
  uint32_t tot;      // Time data reference TOW
  uint32_t wnot;     // time data reference week number
  double a0;         // bias coefficient of GPS to UTC
  double a1;         // drift coefficient of GPS to UTC
  double a2;         // drift rate coefficient of GPS to UTC
  uint32_t deltaTLS; // leap second count
  uint32_t wnLSF;    // week number of future leap second
  uint32_t dn;       // day of future leap second
  int32_t deltaTLSF; // current or future leap second count
};

///
/// Earth orientation parameters for ECEF-to-ECI coordinate transformation
///
struct PolarMotionTerms
{
  double pmx;         // X-Axis polar motion     arc-seconds
  double pmxDot;      // Polar motion drift (X)  arc-seconds/day
  double pmy;         // Y-Axis polar motion     arc-seconds
  double pmyDot;      // polar motion drift (Y)  arc-seconds/day
  double deltaUT1;    // UT1-UTV, seconds
  double deltaUT1Dot; // UT1-UTV Drift, seconds/day
};

///
/// This struct is to contain all pertinent information regarding the
/// constellation, including SV ephemeris, configuration and more in future
/// versions of this library.
///
/// "config" and "ephemeris" are vectors to contain prnCount number of their respective
/// structs, and are zero based, with index 0 corresponding to PRN 1.
///
struct Constellation
{
  uint32_t prnCount;
  std::vector<Ephemeris> ephemeris;
  IonosphereTerms ionosphere;
  UtcTerms utc;
  PolarMotionTerms polarMotion;
};

} // namespace Sdx::CS
