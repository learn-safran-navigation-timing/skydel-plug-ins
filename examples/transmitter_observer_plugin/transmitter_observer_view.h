#ifndef TRANSMITTER_OBSERVER_VIEW_H
#define TRANSMITTER_OBSERVER_VIEW_H

#include <QLabel>
#include <QWidget>

#include "skydel_plug_ins/skydel_position_observer_interface.h"
#include "skydel_plug_ins/skydel_transmitter_observer_interface.h"

namespace Ui
{
class TransmitterObserverView;
}

class TransmitterObserverView : public QWidget
{
  Q_OBJECT

public:
  explicit TransmitterObserverView(QWidget* parent = nullptr);
  ~TransmitterObserverView();
  void clear();
  void setEnableFileLogging(bool enable);
  void setEnableNetworkLogging(bool enable);
  void setAddress(const QString& address);
  void setPort(int port);

public slots:
  void updateTransmitters(const SkydelRuntimeTransmitterObserver::TimedTransmitters& timedTransmitters);
  void updatePosition(const SkydelRuntimePositionObserver::TimedPosition& timedPosition);
  void lockConfiguration(bool lock);

signals:
  void enableFileLoggingClicked(bool checked);
  void enableNetworkLoggingClicked(bool checked);
  void addressChanged(const QString& address);
  void portChanged(int port);

private:
  void updateLabelValue(QLabel* label, double value);

  Ui::TransmitterObserverView* m_ui;
};

#endif // TRANSMITTER_OBSERVER_VIEW_H
