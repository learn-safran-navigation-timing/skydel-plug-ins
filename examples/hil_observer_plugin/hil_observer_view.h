#ifndef HIL_OBSERVER_VIEW_H
#define HIL_OBSERVER_VIEW_H

#include <QLabel>
#include <QWidget>

#include "skydel_plug_ins/skydel_hil_observer_interface.h"

namespace Ui
{
class HilObserverView;
}

class HilObserverView : public QWidget
{
  Q_OBJECT

public:
  explicit HilObserverView(QWidget* parent = nullptr);
  ~HilObserverView();
  void clear();
  void setEnableFileLogging(bool enable);

public slots:
  void updatePosition(const SkydelRuntimeHilObserver::TimedPosition& timedPosition);
  void lockConfiguration(bool lock);

signals:
  void enableFileLoggingClicked(bool checked);

private:
  void updateLabelValue(QLabel* label, double value);

  Ui::HilObserverView* m_ui;
};
#endif // HIL_OBSERVER_VIEW_H
