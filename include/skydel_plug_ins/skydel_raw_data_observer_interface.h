#pragma once

#include <QObject>

#include <cstdint>

class SkydelRuntimeRawDataObserver : public QObject
{
public:
  struct Ecef
  {
    double x;
    double y;
    double z;
  };

  struct SignalRawData
  {
    uint32_t id;
    double svElapsedTimeMs;
    Ecef position;
    Ecef positionError;
    double bodyAzimuth;
    double bodyElevation;
    double range;
    double adr;
    double clockCorrection;
    double clockNoise;
    double deltaAf0;
    double deltaAf1;
    double ionoCorrection;
    double tropoCorrection;
    double psrOffset;
    double receiverAntennaAzimuth;
    double receiverAntennaElevation;
    double receiverAntennaGain;
    double svAntennaAzimuth;
    double svAntennaElevation;
    double relativePowerLevel;
    double receiverCarrierPhaseOffset;
    double satelliteCarrierPhaseOffset;
    double calibrationOffset;
    double psrSatTime;
    double pseudorange;
    double gpsTow;
    double gpsWeekNumber;
    double sbas;
  };

  struct SVRawData
  {
    uint32_t id;
    std::vector<SignalRawData> signalsRawData;
  };

  struct ConstellationRawData
  {
    uint32_t id;
    std::vector<SVRawData> svsRawData;
  };

  struct TimedRawData
  {
    int64_t elapsedTimeMs;
    std::vector<ConstellationRawData> constellationsRawData;
  };

  virtual void pushRawData(const TimedRawData&) = 0;
  virtual void connectToView(QWidget* view) = 0;
};

using SkydelConstellationIDToStringMap = std::map<uint32_t, QString>;
using SkydelSignalIDToStringMap = std::map<uint32_t, QString>;

class SkydelRawDataObserverInterface
{
public:
  virtual ~SkydelRawDataObserverInterface() = default;

  virtual SkydelRuntimeRawDataObserver* createRuntimeRawDataObserver(const SkydelConstellationIDToStringMap&,
                                                                     const SkydelSignalIDToStringMap&) = 0;

  static constexpr auto ID = "SkydelRawDataObserver";
  static constexpr auto VERSION = 5;
};
