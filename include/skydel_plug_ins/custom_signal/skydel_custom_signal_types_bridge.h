#pragma once

#include <cstring>

#include "skydel_custom_signal_types.h"

namespace Sdx::CS
{

inline InitData convertToLegacyInitData(const InitializationDatas& datas)
{
  InitData initData;

  initData.startWeek = std::get<uint32_t>(datas.at(START_WEEK_KEY));
  initData.startSecondOfWeek = std::get<uint32_t>(datas.at(START_SECOND_OF_WEEK_KEY));

  std::memset(initData.pathToXml, 0, sizeof(initData.pathToXml));
  std::memset(initData.xmlFileName, 0, sizeof(initData.pathToXml));
  std::memset(initData.customSignalName, 0, sizeof(initData.customSignalName));

  std::get<std::string>(datas.at(PATH_TO_XML_KEY)).copy(initData.pathToXml, sizeof(initData.pathToXml) - 1);
  std::get<std::string>(datas.at(XML_FILE_NAME_KEY)).copy(initData.xmlFileName, sizeof(initData.xmlFileName) - 1);
  std::get<std::string>(datas.at(CUSTOM_SIGNAL_NAME_KEY))
    .copy(initData.customSignalName, sizeof(initData.customSignalName) - 1);

  return initData;
}

inline ConstellationEnum convertToLegacyConstellationEnum(const ConstellationParameters& parameters)
{
  if (parameters.contains(TGD_KEY))
  {
    return ConstellationEnum::GPS;
  }
  else if (parameters.contains(BGD_E5A_KEY))
  {
    return ConstellationEnum::GALILEO;
  }
  else if (parameters.contains(TGD_1_KEY))
  {
    return ConstellationEnum::BEIDOU;
  }

  return CONSTELLATION_COUNT;
}

inline GpsEphemeris convertToLegacyGpsEphemeris(const ConstellationParameters& parameters)
{
  GpsEphemeris ephemeris {};

  if (convertToLegacyConstellationEnum(parameters) == ConstellationEnum::GPS)
  {
    ephemeris.gpsTgd = std::get<double>(parameters.at(TGD_KEY));
    ephemeris.iodc = std::get<uint32_t>(parameters.at(GPS_IODC_KEY));
    ephemeris.codesOnL2 = std::get<uint32_t>(parameters.at(CODES_ON_L2_KEY));
    ephemeris.l2PDataFlag = std::get<uint32_t>(parameters.at(L2P_DATA_FLAG_KEY));
    ephemeris.svSignalHealth = std::get<uint32_t>(parameters.at(SV_SIGNAL_HEALTH_KEY));
    ephemeris.svDataHealth = std::get<uint32_t>(parameters.at(SV_DATA_HEALTH_KEY));
    ephemeris.fitInterval = std::get<uint32_t>(parameters.at(FIT_INTERVAL_KEY));
    ephemeris.uraIndex = std::get<uint32_t>(parameters.at(GPS_URA_INDEX_KEY));
    ephemeris.integrityStatusFlag = std::get<uint32_t>(parameters.at(INTEGRITY_STATUS_FLAG_KEY));
    ephemeris.l2CPhasing = std::get<uint32_t>(parameters.at(L2C_PHASING_KEY));
    ephemeris.uraEdIndex = static_cast<double>(std::get<int32_t>(parameters.at(URA_ED_INDEX_KEY)));
    ephemeris.uraNed0Index = static_cast<double>(std::get<int32_t>(parameters.at(URA_NED_0_INDEX_KEY)));
    ephemeris.uraNed1Index = static_cast<double>(std::get<int32_t>(parameters.at(URA_NED_1_INDEX_KEY)));
    ephemeris.uraNed2Index = static_cast<double>(std::get<int32_t>(parameters.at(URA_NED_2_INDEX_KEY)));
    ephemeris.iscL1CaAvailable = std::get<bool>(parameters.at(ISC_L1C_AVAILABLE_KEY));
    ephemeris.iscL2CAvailable = std::get<bool>(parameters.at(ISC_L2C_AVAILABLE_KEY));
    ephemeris.iscL5I5Available = std::get<bool>(parameters.at(ISC_L5I5_AVAILABLE_KEY));
    ephemeris.iscL5Q5Available = std::get<bool>(parameters.at(ISC_L5Q5_AVAILABLE_KEY));
    ephemeris.iscL1CPAvailable = std::get<bool>(parameters.at(ISC_L1CP_AVAILABLE_KEY));
    ephemeris.iscL1CDAvailable = std::get<bool>(parameters.at(ISC_L1CD_AVAILABLE_KEY));
    ephemeris.iscL1Ca = std::get<double>(parameters.at(ISC_L1CA_KEY));
    ephemeris.iscL2C = std::get<double>(parameters.at(ISC_L2C_KEY));
    ephemeris.iscL5I5 = std::get<double>(parameters.at(ISC_L5I5_KEY));
    ephemeris.iscL5Q5 = std::get<double>(parameters.at(ISC_L5Q5_KEY));
    ephemeris.iscL1CP = std::get<double>(parameters.at(ISC_L1CP_KEY));
    ephemeris.iscL1CD = std::get<double>(parameters.at(ISC_L1CD_KEY));
    ephemeris.signalHealth = static_cast<uint8_t>(std::get<uint32_t>(parameters.at(SIGNAL_HEALTH_KEY)));
    ephemeris.dataHealth = static_cast<uint8_t>(std::get<uint32_t>(parameters.at(DATA_HEALTH_KEY)));
    ephemeris.svConfig = std::get<int32_t>(parameters.at(SV_CONFIG_KEY));
    ephemeris.l1Health = std::get<bool>(parameters.at(L1_HEALTH_KEY));
    ephemeris.l2Health = std::get<bool>(parameters.at(L2_HEALTH_KEY));
    ephemeris.l5Health = std::get<bool>(parameters.at(L5_HEALTH_KEY));
    ephemeris.l1cHealth = std::get<bool>(parameters.at(L1C_HEALTH_KEY));
    ephemeris.navAlertFlag = std::get<bool>(parameters.at(NAV_ALERT_FLAG_KEY));
    ephemeris.cNavAlertFlag = std::get<bool>(parameters.at(CNAV_ALERT_FLAG_KEY));
  }

  return ephemeris;
}

inline GalileoEphemeris convertToLegacyGalileoEphemeris(const ConstellationParameters& parameters)
{
  GalileoEphemeris ephemeris {};

  if (convertToLegacyConstellationEnum(parameters) == ConstellationEnum::GALILEO)
  {
    ephemeris.galileoBgdE5a = std::get<double>(parameters.at(BGD_E5A_KEY));
    ephemeris.galileoBgdE5b = std::get<double>(parameters.at(BGD_E5B_KEY));
    ephemeris.sisaE5a = std::get<uint32_t>(parameters.at(SISA_E5A_KEY));
    ephemeris.sisaE5b = std::get<uint32_t>(parameters.at(SISA_E5B_KEY));
    ephemeris.signalHealthE5a = std::get<uint32_t>(parameters.at(SIGNAL_HEALTH_E5A_KEY));
    ephemeris.signalHealthE5b = std::get<uint32_t>(parameters.at(SIGNAL_HEALTH_E5B_KEY));
    ephemeris.signalHealthE1B = std::get<uint32_t>(parameters.at(SIGNAL_HEALTH_E1B_KEY));
    ephemeris.dataHealthE5a = std::get<bool>(parameters.at(DATA_HEALTH_E5A_KEY));
    ephemeris.dataHealthE5b = std::get<bool>(parameters.at(DATA_HEALTH_E5B_KEY));
    ephemeris.dataHealthE1B = std::get<bool>(parameters.at(DATA_HEALTH_E1B_KEY));
  }

  return ephemeris;
}

inline BeiDouEphemeris convertToLegacyBeiDouEphemeris(const ConstellationParameters& parameters)
{
  BeiDouEphemeris ephemeris {};

  if (convertToLegacyConstellationEnum(parameters) == ConstellationEnum::BEIDOU)
  {
    ephemeris.beiDouTgd1 = std::get<double>(parameters.at(TGD_1_KEY));
    ephemeris.beiDouTgd2 = std::get<double>(parameters.at(TGD_2_KEY));
    ephemeris.beiDouTgdb1cp = std::get<double>(parameters.at(TGD_B1CP_KEY));
    ephemeris.beiDouTgdb2ap = std::get<double>(parameters.at(TGD_B2AP_KEY));
    ephemeris.aodc = std::get<uint32_t>(parameters.at(AODC_KEY));
    ephemeris.aode = std::get<uint32_t>(parameters.at(AODE_KEY));
    ephemeris.iodc = std::get<uint32_t>(parameters.at(BEIDOU_IODC_KEY));
    ephemeris.satH2 = std::get<uint32_t>(parameters.at(SAT_H2_KEY));
    ephemeris.iscB1CdAvailable = std::get<bool>(parameters.at(ISC_B1C_AVAILABLE_KEY));
    ephemeris.iscB1Cd = std::get<double>(parameters.at(ISC_B1CD_KEY));
    ephemeris.uraIndex = std::get<uint32_t>(parameters.at(URA_INDEX_KEY));
    ephemeris.healthInfo = static_cast<uint16_t>(std::get<uint32_t>(parameters.at(HEALTH_INFO_KEY)));
    ephemeris.autonomousHealth = std::get<bool>(parameters.at(AUTONOMOUS_HEALTH_KEY));
    ephemeris.cnavHealthInfo = static_cast<uint8_t>(std::get<uint32_t>(parameters.at(CNAV_HEALTH_INFO_KEY)));
    ephemeris.healthStatus = static_cast<uint8_t>(std::get<uint32_t>(parameters.at(HEALTH_STATUS_KEY)));
  }

  return ephemeris;
}

inline GlonassEphemeris convertToLegacyGlonassEphemeris(const ConstellationParameters& parameters)
{
  GlonassEphemeris ephemeris {};

  if (parameters.contains(T_LAMBDA_KEY))
  {
    ephemeris.t_lambda = std::get<double>(parameters.at(T_LAMBDA_KEY));
    ephemeris.tau_c = std::get<double>(parameters.at(TAU_C_KEY));
    ephemeris.tau_gps = std::get<double>(parameters.at(TAU_GPS_KEY));
    ephemeris.tau_n = std::get<double>(parameters.at(ALM_TAU_N_KEY));
    ephemeris.lambda = std::get<double>(parameters.at(LAMBDA_KEY));
    ephemeris.delta_i = std::get<double>(parameters.at(DELTA_I_KEY));
    ephemeris.omega = std::get<double>(parameters.at(OMEGA_KEY));
    ephemeris.e = std::get<double>(parameters.at(E_KEY));
    ephemeris.delta_t = std::get<double>(parameters.at(DELTA_T_KEY));
    ephemeris.delta_t_rate = std::get<double>(parameters.at(DELTA_TO_RATE_KEY));
    ephemeris.tauN = std::get<double>(parameters.at(EPH_TAU_N_KEY));
    ephemeris.svRelativeFrequencyBias = std::get<double>(parameters.at(SV_RELATIVE_FREQUENCY_BIAS_KEY));
    ephemeris.messageFrameTime = std::get<uint32_t>(parameters.at(MESSAGE_FRAME_TIME_KEY));
    ephemeris.age = std::get<uint32_t>(parameters.at(AGE_KEY));
    ephemeris.positionX = std::get<double>(parameters.at(POSITION_X_KEY));
    ephemeris.positionY = std::get<double>(parameters.at(POSITION_Y_KEY));
    ephemeris.positionZ = std::get<double>(parameters.at(POSITION_Z_KEY));
    ephemeris.velocityX = std::get<double>(parameters.at(VELOCITY_X_KEY));
    ephemeris.velocityY = std::get<double>(parameters.at(VELOCITY_Y_KEY));
    ephemeris.velocityZ = std::get<double>(parameters.at(VELOCITY_Z_KEY));
    ephemeris.accelerationX = std::get<double>(parameters.at(ACCELERATION_X_KEY));
    ephemeris.accelerationY = std::get<double>(parameters.at(ACCELERATION_Y_KEY));
    ephemeris.accelerationZ = std::get<double>(parameters.at(ACCELERATION_Z_KEY));
  }

  return ephemeris;
}

inline Ephemeris convertToLegacyBaseEphemeris(const ConstellationParameters& parameters)
{
  Ephemeris ephemeris {};

  if (!parameters.empty())
  {
    ephemeris.prn = std::get<uint32_t>(parameters.at(PRN_KEY));

    if (parameters.contains(IOD_KEY))
    {
      ephemeris.iod = std::get<uint32_t>(parameters.at(IOD_KEY));
      ephemeris.wnop = std::get<uint32_t>(parameters.at(WNOP_KEY));
      ephemeris.top = std::get<uint32_t>(parameters.at(TOP_KEY));
      ephemeris.wnoc = std::get<uint32_t>(parameters.at(WNOC_KEY));
      ephemeris.toc = std::get<uint32_t>(parameters.at(TOC_KEY));
      ephemeris.af0 = std::get<double>(parameters.at(AF0_KEY));
      ephemeris.af1 = std::get<double>(parameters.at(AF1_KEY));
      ephemeris.af2 = std::get<double>(parameters.at(AF2_KEY));
      ephemeris.wnoe = std::get<uint32_t>(parameters.at(WNOE_KEY));
      ephemeris.toe = std::get<uint32_t>(parameters.at(TOE_KEY));
      ephemeris.sqrtA = std::get<double>(parameters.at(SQRTA_KEY));
      ephemeris.eccentricity = std::get<double>(parameters.at(ECCENTRICITY_KEY));
      ephemeris.inclination = std::get<double>(parameters.at(INCLINATION_KEY));
      ephemeris.lonAscendNode = std::get<double>(parameters.at(LON_ASCEND_NODE_KEY));
      ephemeris.rateOfRightAscen = std::get<double>(parameters.at(RATE_OF_RIGHT_ASCEN_KEY));
      ephemeris.meanAnomaly = std::get<double>(parameters.at(MEAN_ANOMALY_KEY));
      ephemeris.argumentOfPerigee = std::get<double>(parameters.at(ARGUMENT_OF_PERIGEE_KEY));
      ephemeris.meanMotionDiff = std::get<double>(parameters.at(MEAN_MOTION_DIFF_KEY));
      ephemeris.iDot = std::get<double>(parameters.at(I_DOT_KEY));
      ephemeris.aDot = 0.;
      ephemeris.deltaN0Dot = 0.;
      ephemeris.crs = std::get<double>(parameters.at(CRS_KEY));
      ephemeris.crc = std::get<double>(parameters.at(CRC_KEY));
      ephemeris.cuc = std::get<double>(parameters.at(CUC_KEY));
      ephemeris.cus = std::get<double>(parameters.at(CUS_KEY));
      ephemeris.cic = std::get<double>(parameters.at(CIC_KEY));
      ephemeris.cis = std::get<double>(parameters.at(CIS_KEY));
    }
  }

  return ephemeris;
}

inline Ephemeris convertToLegacyEphemeris(const ConstellationParameters& parameters)
{
  Ephemeris ephemeris = convertToLegacyBaseEphemeris(parameters);

  ephemeris.constellation = convertToLegacyConstellationEnum(parameters);

  ephemeris.gpsEphemeris = convertToLegacyGpsEphemeris(parameters);
  ephemeris.galileoEphemeris = convertToLegacyGalileoEphemeris(parameters);
  ephemeris.beidouEphemeris = convertToLegacyBeiDouEphemeris(parameters);
  ephemeris.glonassEphemeris = convertToLegacyGlonassEphemeris(parameters);

  return ephemeris;
}

inline Ephemeris convertToLegacyEphemeris(uint32_t svID, const ConstellationDatas& constellationDatas)
{
  const auto& satelliteParameters = constellationDatas.at(EPHEMERIS_DATA_SET_KEY).at(svID - 1u);

  return convertToLegacyEphemeris(satelliteParameters);
}

inline std::vector<Ephemeris> convertToLegacyEphemerides(const ConstellationDatas& constellationDatas)
{
  std::vector<Ephemeris> ephemerides;

  for (const auto& constellationParameters : constellationDatas.at(EPHEMERIS_DATA_SET_KEY))
  {
    ephemerides.emplace_back(convertToLegacyEphemeris(constellationParameters));
  }

  return ephemerides;
}

inline IonosphereTerms convertToLegacyIonosphereTerms(const InitializationDatas& data)
{
  return {std::get<double>(data.at(KLOBUCHAR_ALPHA_0_KEY)),
          std::get<double>(data.at(KLOBUCHAR_ALPHA_1_KEY)),
          std::get<double>(data.at(KLOBUCHAR_ALPHA_2_KEY)),
          std::get<double>(data.at(KLOBUCHAR_ALPHA_3_KEY)),
          std::get<double>(data.at(KLOBUCHAR_BETA_0_KEY)),
          std::get<double>(data.at(KLOBUCHAR_BETA_1_KEY)),
          std::get<double>(data.at(KLOBUCHAR_BETA_2_KEY)),
          std::get<double>(data.at(KLOBUCHAR_BETA_3_KEY))};
}

inline UtcTerms convertToLegacyUtcTerms(const InitializationDatas& data)
{
  return {std::get<uint32_t>(data.at(TOT_KEY)),
          std::get<uint32_t>(data.at(WNOT_KEY)),
          std::get<double>(data.at(A0_KEY)),
          std::get<double>(data.at(A1_KEY)),
          std::get<double>(data.at(A2_KEY)),
          static_cast<uint32_t>(std::get<int32_t>(data.at(DELTA_TLS_KEY))),
          std::get<uint32_t>(data.at(WN_LSF_KEY)),
          std::get<uint32_t>(data.at(DN_KEY)),
          std::get<int32_t>(data.at(DELTA_TLSF_KEY))};
}

inline Constellation convertToLegacyConstellation(const ConstellationDatas& constellationData)
{
  return {static_cast<uint32_t>(constellationData.at(EPHEMERIS_DATA_SET_KEY).size()),
          convertToLegacyEphemerides(constellationData),
          {},
          {},
          {}};
}

inline Constellation convertToLegacyConstellation(const InitializationDatas& initializationData,
                                                  const ConstellationDatas& constellationData)
{
  return {static_cast<uint32_t>(constellationData.at(EPHEMERIS_DATA_SET_KEY).size()),
          convertToLegacyEphemerides(constellationData),
          convertToLegacyIonosphereTerms(initializationData),
          convertToLegacyUtcTerms(initializationData),
          {0., 0., 0., 0., 0., 0.}};
}

} // namespace Sdx::CS
