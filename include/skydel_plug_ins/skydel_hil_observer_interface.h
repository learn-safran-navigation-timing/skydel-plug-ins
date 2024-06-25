#pragma once

#include <QObject>

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
    double time;             // ms
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
  static constexpr auto VERSION = 2;
};
