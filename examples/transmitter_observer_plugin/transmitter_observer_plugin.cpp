#include "transmitter_observer_plugin.h"

#include "runtime_position_observer.h"
#include "runtime_transmitter_observer.h"
#include "transmitter_observer_view.h"

void TransmitterObserverPlugin::setConfiguration(const QString&, const QJsonObject& configuration)
{
  if (configuration.contains("enableFileLogging") && configuration["enableFileLogging"].isBool())
  {
    m_enableFileLogging = configuration["enableFileLogging"].toBool();
  }

  if (configuration.contains("enableNetworkLogging") && configuration["enableNetworkLogging"].isBool())
  {
    m_enableNetworkLogging = configuration["enableNetworkLogging"].toBool();
  }

  if (configuration.contains("address") && configuration["address"].isString())
  {
    m_address = QHostAddress(configuration["address"].toString());
  }

  if (configuration.contains("port"))
  {
    m_port = configuration["port"].toInt();
  }

  emit configurationChanged();
}

QJsonObject TransmitterObserverPlugin::getConfiguration() const
{
  return {{"enableFileLogging", m_enableFileLogging},
          {"enableNetworkLogging", m_enableNetworkLogging},
          {"address", m_address.toString()},
          {"port", m_port}};
}

QWidget* TransmitterObserverPlugin::createUI()
{
  auto view = new TransmitterObserverView;

  view->setEnableFileLogging(m_enableFileLogging);
  view->setEnableNetworkLogging(m_enableNetworkLogging);
  view->setAddress(m_address.toString());
  view->setPort(static_cast<int>(m_port));

  connect(view, &TransmitterObserverView::enableFileLoggingClicked, [this](bool checked) {
    m_enableFileLogging = checked;
    m_skydelNotifier->setDirty();
  });

  connect(view, &TransmitterObserverView::enableNetworkLoggingClicked, [this](bool checked) {
    m_enableNetworkLogging = checked;
    m_skydelNotifier->setDirty();
  });

  connect(view, &TransmitterObserverView::addressChanged, [this](const QString& address) {
    m_address = QHostAddress(address);
    m_skydelNotifier->setDirty();
  });

  connect(view, &TransmitterObserverView::portChanged, [this](int port) {
    m_port = port;
    m_skydelNotifier->setDirty();
  });

  connect(this, &TransmitterObserverPlugin::configurationChanged, [this, view]() {
    view->setEnableFileLogging(m_enableFileLogging);
    view->setEnableNetworkLogging(m_enableNetworkLogging);
    view->setAddress(m_address.toString());
    view->setPort(static_cast<int>(m_port));
  });

  return view;
}

SkydelRuntimeTransmitterObserver* TransmitterObserverPlugin::createRuntimeTransmitterObserver()
{
  m_logger.reset(m_address, m_port, m_enableNetworkLogging, m_enableFileLogging, m_logPath);
  auto* txObserver = new RuntimeTransmitterObserver();

  connect(txObserver,
          &RuntimeTransmitterObserver::updateTransmitters,
          this,
          &TransmitterObserverPlugin::onNewTransmitterUpdate);
  connect(txObserver, &QObject::destroyed, this, &TransmitterObserverPlugin::onSimulationEnd);

  return txObserver;
}

SkydelRuntimePositionObserver* TransmitterObserverPlugin::createRuntimePositionObserver()
{
  auto* positionObserver = new RuntimePositionObserver();

  connect(positionObserver,
          &RuntimePositionObserver::updatePosition,
          this,
          &TransmitterObserverPlugin::onNewPositionUpdate);

  return positionObserver;
}

void TransmitterObserverPlugin::onNewTransmitterUpdate(const SkydelRuntimeTransmitterObserver::TimedTransmitters& txs)
{
  m_logger.pushTransmitters(txs);
}

void TransmitterObserverPlugin::onNewPositionUpdate(const SkydelRuntimePositionObserver::TimedPosition& p)
{
  m_logger.pushPosition(p);
}

void TransmitterObserverPlugin::onSimulationEnd()
{
  m_logger.close();
}
