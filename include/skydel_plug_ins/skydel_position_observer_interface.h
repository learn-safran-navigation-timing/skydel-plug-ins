#ifndef SKYDEL_POSITON_OBSERVER_INTERFACE_H
#define SKYDEL_POSITON_OBSERVER_INTERFACE_H

#include <QObject>
#include <QWidget>

#include <cstdint>

class SkydelRuntimePositionObserver : public QObject
{
public:
  virtual ~SkydelRuntimePositionObserver() = default;

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
  struct TimedPosition
  {
    int64_t time;            // ms
    Ecef position;           // m
    Orientation orientation; // rad
  };

  virtual void pushPosition(const TimedPosition&) = 0;
  virtual void connectToView(QWidget* view) = 0;
};

class SkydelPositionObserverInterface
{
public:
  virtual ~SkydelPositionObserverInterface() = default;

  virtual SkydelRuntimePositionObserver* createRuntimePositionObserver() = 0;

  static constexpr auto ID = "SkydelPositionObserver";
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_POSITON_OBSERVER_INTERFACE_H
