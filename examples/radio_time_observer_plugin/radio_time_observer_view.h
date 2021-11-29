#ifndef RADIO_TIME_OBSERVER_VIEW_H
#define RADIO_TIME_OBSERVER_VIEW_H

#include <QLabel>
#include <QWidget>

#include "skydel_plug_ins/skydel_position_observer_interface.h"
#include "skydel_plug_ins/skydel_radio_time_observer_interface.h"

namespace Ui
{
class RadioTimeObserverView;
}

class RadioTimeObserverView : public QWidget
{
  Q_OBJECT

public:
  explicit RadioTimeObserverView(QWidget* parent = nullptr);
  ~RadioTimeObserverView();
  void clear();
  void setEnableFileLogging(bool enable);
  void setEnableNetworkLogging(bool enable);
  void setAddress(const QString& address);
  void setPort(int port);

public slots:
  void updatePosition(const SkydelRuntimePositionObserver::TimedPosition& timedPosition, int64_t usUntilRfTx);
  void updateRadioTime(const SkydelRuntimeRadioTimeObserver::RadioTimeEstimate&);
  void lockConfiguration(bool lock);

signals:
  void enableFileLoggingClicked(bool checked);
  void enableNetworkLoggingClicked(bool checked);
  void addressChanged(const QString& address);
  void portChanged(int port);

private:
  void updateLabelValue(QLabel* label, double value);

  QList<SkydelRuntimePositionObserver::TimedPosition> m_processedPositions;
  Ui::RadioTimeObserverView* m_ui;
};

#endif // RADIO_TIME_OBSERVER_VIEW_H
