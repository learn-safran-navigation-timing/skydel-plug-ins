#ifndef SKYDEL_RAW_DATA_OBSERVER_INTERFACE_H
#define SKYDEL_RAW_DATA_OBSERVER_INTERFACE_H

#include <QObject>

#include <cstdint>

class SkydelRuntimeRawDataObserver : public QObject
{
public:
  struct SignalRawData
  {
    int signal;

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
    int system;
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
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_RAW_DATA_OBSERVER_INTERFACE_H
