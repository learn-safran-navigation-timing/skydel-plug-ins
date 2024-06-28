#pragma once

#include <QObject>
#include <QString>

#include <cstdint>
#include <vector>

class SkydelRuntimeTransmitterObserver : public QObject
{
public:
  virtual ~SkydelRuntimeTransmitterObserver() = default;

  struct Ecef
  {
    double x;
    double y;
    double z;
  };

  struct Orientation
  {
    double roll;
    double pitch;
    double yaw;
  };

  struct InterferenceSignal
  {
    QString id;
    bool isEnabled;
    int64_t centerFrequency;
    double propagationLoss;
    double gainAtTransmitter;
    double gainAtVehicle;
    double signalPower;
    QString typeName;
  };

  struct Transmitter
  {
    QString id;
    QString name;
    QString colorName;
    Ecef position;
    Orientation orientation;
    bool isEnabled;
    bool isMasked;
    bool usingManualPropagationLoss;
    double referencePower;
    double range;
    double elevation;
    double azimuth;
    std::vector<InterferenceSignal> interferenceSignals;
  };

  struct TimedTransmitters
  {
    int64_t elapsedTimeMs;
    std::vector<Transmitter> interferences;
    std::vector<Transmitter> spoofers;
  };

  virtual void pushTransmitters(const TimedTransmitters&) = 0;
  virtual void connectToView(QWidget* view) = 0;
};

class SkydelTransmitterObserverInterface
{
public:
  virtual ~SkydelTransmitterObserverInterface() = default;

  virtual SkydelRuntimeTransmitterObserver* createRuntimeTransmitterObserver() = 0;

  static constexpr auto ID = "SkydelTransmitterObserver";
  static constexpr auto VERSION = 1;
};
