#ifndef RUNTIME_OBJECTS_H
#define RUNTIME_OBJECTS_H

#include "skydel_plug_ins/skydel_position_observer_interface.h"
#include "skydel_plug_ins/skydel_radio_time_observer_interface.h"

class ForwardingRadioTimeObserver : public SkydelRuntimeRadioTimeObserver
{
  Q_OBJECT

public:
  // Called at simluation running phase at 1000 Hz
  void pushRadioTime(const SkydelRuntimeRadioTimeObserver::RadioTimeEstimate& rte) override
  {
    emit newRadioTimeEstimate(rte);
  }

  void connectToView(QWidget*) override {}

signals:
  void newRadioTimeEstimate(const SkydelRuntimeRadioTimeObserver::RadioTimeEstimate&);
};

class ForwardingPositionObserver : public SkydelRuntimePositionObserver
{
  Q_OBJECT

public:
  // Called at simluation running phase at 1000 Hz
  void pushPosition(const SkydelRuntimePositionObserver::TimedPosition& p) override { emit newPosition(p); }

  void connectToView(QWidget*) override {}

signals:
  void newPosition(const SkydelRuntimePositionObserver::TimedPosition& p);
};

#endif // RUNTIME_OBJECTS_H
