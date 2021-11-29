#include "runtime_position_observer.h"

#include "transmitter_observer_view.h"

void RuntimePositionObserver::pushPosition(const SkydelRuntimePositionObserver::TimedPosition& p)
{
  emit updatePosition(p);
}

void RuntimePositionObserver::connectToView(QWidget* view)
{
  if (auto txObserverView = dynamic_cast<TransmitterObserverView*>(view))
  {
    connect(this, &RuntimePositionObserver::updatePosition, txObserverView, &TransmitterObserverView::updatePosition);
  }
}
