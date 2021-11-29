#ifndef RUNTIME_TRANSMITTER_OBSERVER_H
#define RUNTIME_TRANSMITTER_OBSERVER_H

#include <QFile>
#include <QUdpSocket>

#include "skydel_plug_ins/skydel_plugin.h"

// Runtime position observer implementation
class RuntimeTransmitterObserver : public SkydelRuntimeTransmitterObserver
{
  Q_OBJECT

public:
  explicit RuntimeTransmitterObserver() = default; // Called at simulation initialization phase
  ~RuntimeTransmitterObserver() override;          // Called at simluation ending phase

  void pushTransmitters(const SkydelRuntimeTransmitterObserver::TimedTransmitters&)
    override; // Called at simluation running phase at 1000 Hz
  void connectToView(QWidget*) override;

signals:
  void updateTransmitters(const SkydelRuntimeTransmitterObserver::TimedTransmitters& txs);
  void lockConfiguration(bool lock);
};

#endif // RUNTIME_TRANSMITTER_OBSERVER_H
