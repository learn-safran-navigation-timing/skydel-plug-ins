#include "radio_time_observer_plugin.h"

#include "radio_time_observer_view.h"
#include "runtime_objects.h"

RadioTimeObserverPlugin::RadioTimeObserverPlugin(QObject* parent) : QObject(parent)
{
}

void RadioTimeObserverPlugin::setConfiguration(const QString&, const QJsonObject& configuration)
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

QJsonObject RadioTimeObserverPlugin::getConfiguration() const
{
  return {{"enableFileLogging", m_enableFileLogging},
          {"enableNetworkLogging", m_enableNetworkLogging},
          {"address", m_address.toString()},
          {"port", m_port}};
}

QWidget* RadioTimeObserverPlugin::createUI()
{
  auto view = new RadioTimeObserverView;

  view->setEnableFileLogging(m_enableFileLogging);
  view->setEnableNetworkLogging(m_enableNetworkLogging);
  view->setAddress(m_address.toString());
  view->setPort(static_cast<int>(m_port));

  connect(view, &RadioTimeObserverView::enableFileLoggingClicked, [this](bool checked) {
    m_enableFileLogging = checked;
    m_skydelNotifier->setDirty();
  });

  connect(view, &RadioTimeObserverView::enableNetworkLoggingClicked, [this](bool checked) {
    m_enableNetworkLogging = checked;
    m_skydelNotifier->setDirty();
  });

  connect(view, &RadioTimeObserverView::addressChanged, [this](const QString& address) {
    m_address = QHostAddress(address);
    m_skydelNotifier->setDirty();
  });

  connect(view, &RadioTimeObserverView::portChanged, [this](int port) {
    m_port = port;
    m_skydelNotifier->setDirty();
  });

  connect(this, &RadioTimeObserverPlugin::configurationChanged, [this, view]() {
    view->setEnableFileLogging(m_enableFileLogging);
    view->setEnableNetworkLogging(m_enableNetworkLogging);
    view->setAddress(m_address.toString());
    view->setPort(static_cast<int>(m_port));
  });

  connect(&m_logger, &RadioTimeLogger::updatePosition, view, &RadioTimeObserverView::updatePosition);
  connect(&m_logger, &RadioTimeLogger::updateRadioTime, view, &RadioTimeObserverView::updateRadioTime);
  connect(this, &RadioTimeObserverPlugin::lockConfiguration, view, &RadioTimeObserverView::lockConfiguration);

  return view;
}

SkydelRuntimeRadioTimeObserver* RadioTimeObserverPlugin::createRuntimeRadioTimeObserver()
{
  emit lockConfiguration(true);
  m_logger.reset(m_skydelNotifier, m_address, m_port, m_enableNetworkLogging, m_enableFileLogging, m_logPath);
  auto* frtoPtr = new ForwardingRadioTimeObserver;
  connect(frtoPtr, &ForwardingRadioTimeObserver::newRadioTimeEstimate, &m_logger, &RadioTimeLogger::pushRadioTime);
  connect(frtoPtr,
          &QObject::destroyed,
          this,
          &RadioTimeObserverPlugin::onRuntimeObjectsDestroyed); // Close file and DelayedBroadcaster

  return frtoPtr;
}

SkydelRuntimePositionObserver* RadioTimeObserverPlugin::createRuntimePositionObserver()
{
  auto* fpoPtr = new ForwardingPositionObserver();
  connect(fpoPtr, &ForwardingPositionObserver::newPosition, &m_logger, &RadioTimeLogger::pushPosition);

  return fpoPtr;
}

void RadioTimeObserverPlugin::onRuntimeObjectsDestroyed()
{
  m_logger.close();
  emit lockConfiguration(false);
}
