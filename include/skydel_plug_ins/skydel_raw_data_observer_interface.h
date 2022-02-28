#ifndef SKYDEL_RAW_DATA_OBSERVER_INTERFACE_H
#define SKYDEL_RAW_DATA_OBSERVER_INTERFACE_H

#include <QObject>

#include <cstdint>

class SkydelRuntimeRawDataObserver : public QObject
{
public:
  enum class Constellation
  {
    GPS,
    GLONASS,
    GALILEO,
    BEIDOU,
    SBAS,
    QZSS,
    NAVIC
  };

  enum class Signal
  {
    GPS_L1_CA,
    GPS_L1C,
    GPS_L2C,
    GPS_L1_PCODE,
    GPS_L2_PCODE,
    GPS_L1_MCODE_E,
    GPS_L2_MCODE_E,
    GPS_L1_MCODE_R,
    GPS_L2_MCODE_R,
    GPS_L5,
    GLONASS_G1,
    GLONASS_G2,
    GALILEO_E1,
    GALILEO_E1_PRS,
    GALILEO_E5a,
    GALILEO_E5b,
    GALILEO_E5ALTBOC,
    GALILEO_E6,
    GALILEO_E6_PRS,
    BEIDOU_B1,
    BEIDOU_B2,
    BEIDOU_B1C,
    BEIDOU_B2a,
    SBAS_L1,
    SBAS_L5,
    QZSS_L1_CA,
    QZSS_L1_CB,
    QZSS_L1C,
    QZSS_L1S,
    QZSS_L2C,
    QZSS_L5,
    QZSS_L5S,
    NAVIC_L5
  };

  struct SignalRawData
  {
    Signal signal;

    double svElapsedTimeMs;
    double pseudorange;
    double adr;
  };

  struct SVRawData
  {
    uint32_t svID;
    std::vector<SignalRawData> rawDatas;
  };

  struct ConstellationRawData
  {
    Constellation system;
    std::vector<SVRawData> svs;
  };

  struct TimedRawData
  {
    int64_t elapsedTimeMs;
    std::vector<ConstellationRawData> svsData;
  };

  virtual void pushRawData(const TimedRawData&) = 0;
  virtual void connectToView(QWidget* view) = 0;
};

class SkydelRawDataObserverInterface
{
public:
  virtual ~SkydelRawDataObserverInterface() = default;

  virtual SkydelRuntimeRawDataObserver* createRuntimeRawDataObserver() = 0;

  static constexpr auto ID = "SkydelRawDataObserver";
  static constexpr auto VERSION = 2;
};

#endif // SKYDEL_RAW_DATA_OBSERVER_INTERFACE_H
