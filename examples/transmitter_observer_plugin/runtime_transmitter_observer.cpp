#include "runtime_transmitter_observer.h"

#include <QDir>
#include <QTextStream>

#include <stdexcept>

#include "transmitter_observer_view.h"

RuntimeTransmitterObserver::~RuntimeTransmitterObserver()
{
  emit lockConfiguration(false);
}

void RuntimeTransmitterObserver::pushTransmitters(const TimedTransmitters& txs)
{
  emit updateTransmitters(txs);
}

void RuntimeTransmitterObserver::connectToView(QWidget* view)
{
  if (auto positionObserverView = dynamic_cast<TransmitterObserverView*>(view))
  {
    positionObserverView->clear();
    positionObserverView->lockConfiguration(true);
    connect(this,
            &RuntimeTransmitterObserver::updateTransmitters,
            positionObserverView,
            &TransmitterObserverView::updateTransmitters);
    connect(this,
            &RuntimeTransmitterObserver::lockConfiguration,
            positionObserverView,
            &TransmitterObserverView::lockConfiguration);
  }
}
