#pragma once

#include <map>
#include <string>
#include <variant>
#include <vector>

namespace Sdx::CS
{

using ConstellationParameter = std::variant<uint32_t, int32_t, double, bool>;
using ConstellationParameters = std::map<std::string, ConstellationParameter>;
using ConstellationData = std::vector<ConstellationParameters>;
using ConstellationDatas = std::map<std::string, ConstellationData>;

// Data Set Types
constexpr auto EPHEMERIS_DATA_SET_KEY = "EPHEMERIS";

// Kepler
constexpr auto PRN_KEY = "prn";
constexpr auto IOD_KEY = "iod";
constexpr auto WNOP_KEY = "wnop";
constexpr auto TOP_KEY = "top";
constexpr auto WNOC_KEY = "wnoc";
constexpr auto TOC_KEY = "toc";
constexpr auto AF0_KEY = "af0";
constexpr auto AF1_KEY = "af1";
constexpr auto AF2_KEY = "af2";
constexpr auto WNOE_KEY = "wnoe";
constexpr auto TOE_KEY = "toe";
constexpr auto SQRTA_KEY = "sqrtA";
constexpr auto ECCENTRICITY_KEY = "eccentricity";
constexpr auto INCLINATION_KEY = "inclination";
constexpr auto LON_ASCEND_NODE_KEY = "lonAscendNode";
constexpr auto RATE_OF_RIGHT_ASCEN_KEY = "rateOfRightAscen";
constexpr auto MEAN_ANOMALY_KEY = "meanAnomaly";
constexpr auto ARGUMENT_OF_PERIGEE_KEY = "argumentOfPerigee";
constexpr auto MEAN_MOTION_DIFF_KEY = "meanMotionDiff";
constexpr auto I_DOT_KEY = "iDot";
constexpr auto CRS_KEY = "crs";
constexpr auto CRC_KEY = "crc";
constexpr auto CUC_KEY = "cuc";
constexpr auto CUS_KEY = "cus";
constexpr auto CIC_KEY = "cic";
constexpr auto CIS_KEY = "cis";

// Gps
constexpr auto TGD_KEY = "tgd";
constexpr auto GPS_IODC_KEY = "iodc";
constexpr auto CODES_ON_L2_KEY = "codesOnL2";
constexpr auto L2P_DATA_FLAG_KEY = "l2PDataFlag";
constexpr auto SV_SIGNAL_HEALTH_KEY = "svSignalHealth";
constexpr auto SV_DATA_HEALTH_KEY = "svDataHealth";
constexpr auto FIT_INTERVAL_KEY = "fitInterval";
constexpr auto GPS_URA_INDEX_KEY = "uraIndex";
constexpr auto INTEGRITY_STATUS_FLAG_KEY = "integrityStatusFlag";
constexpr auto L2C_PHASING_KEY = "l2CPhasing";
constexpr auto URA_ED_INDEX_KEY = "uraEdIndex";
constexpr auto URA_NED_0_INDEX_KEY = "uraNed0Index";
constexpr auto URA_NED_1_INDEX_KEY = "uraNed1Index";
constexpr auto URA_NED_2_INDEX_KEY = "uraNed2Index";
constexpr auto ISC_L1C_AVAILABLE_KEY = "iscL1CaAvailable";
constexpr auto ISC_L2C_AVAILABLE_KEY = "iscL2CAvailable";
constexpr auto ISC_L5I5_AVAILABLE_KEY = "iscL5I5Available";
constexpr auto ISC_L5Q5_AVAILABLE_KEY = "iscL5Q5Available";
constexpr auto ISC_L1CP_AVAILABLE_KEY = "iscL1CPAvailable";
constexpr auto ISC_L1CD_AVAILABLE_KEY = "iscL1CDAvailable";
constexpr auto ISC_L1CA_KEY = "iscL1Ca";
constexpr auto ISC_L2C_KEY = "iscL2C";
constexpr auto ISC_L5I5_KEY = "iscL5I5";
constexpr auto ISC_L5Q5_KEY = "iscL5Q5";
constexpr auto ISC_L1CP_KEY = "iscL1CP";
constexpr auto ISC_L1CD_KEY = "iscL1CD";
constexpr auto SIGNAL_HEALTH_KEY = "signalHealth";
constexpr auto DATA_HEALTH_KEY = "dataHealth";
constexpr auto SV_CONFIG_KEY = "svConfig";
constexpr auto L1_HEALTH_KEY = "l1Health";
constexpr auto L2_HEALTH_KEY = "l2Health";
constexpr auto L5_HEALTH_KEY = "l5Health";
constexpr auto L1C_HEALTH_KEY = "l1cHealth";
constexpr auto NAV_ALERT_FLAG_KEY = "navAlertFlag";
constexpr auto CNAV_ALERT_FLAG_KEY = "cNavAlertFlag";

// Galileo
constexpr auto BGD_E5A_KEY = "bgdE5a";
constexpr auto BGD_E5B_KEY = "bgdE5b";
constexpr auto SISA_E5A_KEY = "sisaE5a";
constexpr auto SISA_E5B_KEY = "sisaE5b";
constexpr auto SIGNAL_HEALTH_E5A_KEY = "signalHealthE5a";
constexpr auto SIGNAL_HEALTH_E5B_KEY = "signalHealthE5b";
constexpr auto SIGNAL_HEALTH_E1B_KEY = "signalHealthE1B";
constexpr auto DATA_HEALTH_E5A_KEY = "dataHealthE5a";
constexpr auto DATA_HEALTH_E5B_KEY = "dataHealthE5b";
constexpr auto DATA_HEALTH_E1B_KEY = "dataHealthE1B";

// BeiDou
constexpr auto TGD_1_KEY = "tgd1";
constexpr auto TGD_2_KEY = "tgd2";
constexpr auto TGD_B1CP_KEY = "tgdb1cp";
constexpr auto TGD_B2AP_KEY = "tgdb2ap";
constexpr auto AODC_KEY = "aodc";
constexpr auto AODE_KEY = "aode";
constexpr auto BEIDOU_IODC_KEY = "iodc";
constexpr auto SAT_H2_KEY = "satH2";
constexpr auto ISC_B1C_AVAILABLE_KEY = "iscB1CdAvailable";
constexpr auto ISC_B1CD_KEY = "iscB1Cd";
constexpr auto URA_INDEX_KEY = "uraIndex";
constexpr auto HEALTH_INFO_KEY = "healthInfo";
constexpr auto AUTONOMOUS_HEALTH_KEY = "autonomousHealth";
constexpr auto CNAV_HEALTH_INFO_KEY = "cnavHealthInfo";
constexpr auto HEALTH_STATUS_KEY = "healthStatus";

// Glonass
constexpr auto T_LAMBDA_KEY = "t_lambda";
constexpr auto TAU_C_KEY = "tau_c";
constexpr auto TAU_GPS_KEY = "tau_gps";
constexpr auto ALM_TAU_N_KEY = "tau_n";
constexpr auto LAMBDA_KEY = "lambda";
constexpr auto DELTA_I_KEY = "delta_i";
constexpr auto OMEGA_KEY = "omega";
constexpr auto E_KEY = "e";
constexpr auto DELTA_T_KEY = "delta_t";
constexpr auto DELTA_TO_RATE_KEY = "delta_t_rate";
constexpr auto EPH_TAU_N_KEY = "tauN";
constexpr auto SV_RELATIVE_FREQUENCY_BIAS_KEY = "svRelativeFrequencyBias";
constexpr auto MESSAGE_FRAME_TIME_KEY = "messageFrameTime";
constexpr auto AGE_KEY = "age";
constexpr auto POSITION_X_KEY = "positionX";
constexpr auto POSITION_Y_KEY = "positionY";
constexpr auto POSITION_Z_KEY = "positionZ";
constexpr auto VELOCITY_X_KEY = "velocityX";
constexpr auto VELOCITY_Y_KEY = "velocityY";
constexpr auto VELOCITY_Z_KEY = "velocityZ";
constexpr auto ACCELERATION_X_KEY = "accelerationX";
constexpr auto ACCELERATION_Y_KEY = "accelerationY";
constexpr auto ACCELERATION_Z_KEY = "accelerationZ";

} // namespace Sdx::CS
