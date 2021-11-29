#ifndef RUNTIME_POSITION_OBSERVER_H
#define RUNTIME_POSITION_OBSERVER_H

#include "skydel_plug_ins/skydel_plugin.h"
#include "skydel_plug_ins/skydel_position_observer_interface.h"

class RuntimePositionObserver : public SkydelRuntimePositionObserver
{
  Q_OBJECT

public:
  explicit RuntimePositionObserver() = default;
  ~RuntimePositionObserver() override = default; // Called at simluation ending phase

  void pushPosition(const SkydelRuntimePositionObserver::TimedPosition&) override; // Called during simulation
  void connectToView(QWidget* view) override;

signals:
  void updatePosition(const SkydelRuntimePositionObserver::TimedPosition& p);
};

#endif // RUNTIME_POSITION_OBSERVER_H
