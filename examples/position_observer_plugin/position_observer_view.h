#ifndef POSITION_OBSERVER_VIEW_H
#define POSITION_OBSERVER_VIEW_H

#include <QLabel>
#include <QWidget>

#include "skydel_plug_ins/skydel_position_observer_interface.h"

namespace Ui
{
class PositionObserverView;
}

class PositionObserverView : public QWidget
{
  Q_OBJECT

public:
  explicit PositionObserverView(QWidget* parent = nullptr);
  ~PositionObserverView();
  void clear();
  void setEnableFileLogging(bool enable);
  void setEnableNetworkLogging(bool enable);
  void setAddress(const QString& address);
  void setPort(int port);

public slots:
  void updatePosition(const SkydelRuntimePositionObserver::TimedPosition& timedPosition);
  void lockConfiguration(bool lock);

signals:
  void enableFileLoggingClicked(bool checked);
  void enableNetworkLoggingClicked(bool checked);
  void addressChanged(const QString& address);
  void portChanged(int port);

private:
  void updateLabelValue(QLabel* label, double value);

  Ui::PositionObserverView* m_ui;
};

#endif // POSITION_OBSERVER_VIEW_H
