#ifndef SKYDEL_HIL_OBSERVER_INTERFACE_H
#define SKYDEL_HIL_OBSERVER_INTERFACE_H

#include <QObject>
#include <QWidget>

class SkydelRuntimeHilObserver : public QObject
{
public:
  virtual ~SkydelRuntimeHilObserver() = default;

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

  virtual void pushHilInput(const TimedPosition&) = 0;
  virtual void connectToView(QWidget* view) = 0;
};

class SkydelHilObserverInterface
{
public:
  virtual ~SkydelHilObserverInterface() = default;

  virtual SkydelRuntimeHilObserver* createRuntimeHilObserver() = 0;

  static constexpr auto ID = "SkydelHilObserver";
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_HIL_OBSERVER_INTERFACE_H
