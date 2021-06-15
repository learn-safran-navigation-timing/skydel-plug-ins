#include "position_observer_plugin.h"

#include "position_observer_view.h"

void PositionObserverPlugin::setConfiguration(const QString&, const QJsonObject& configuration)
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

QJsonObject PositionObserverPlugin::getConfiguration() const
{
  return {{"enableFileLogging", m_enableFileLogging},
          {"enableNetworkLogging", m_enableNetworkLogging},
          {"address", m_address.toString()},
          {"port", m_port}};
}

QWidget* PositionObserverPlugin::createUI()
{
  auto view = new PositionObserverView;

  view->setEnableFileLogging(m_enableFileLogging);
  view->setEnableNetworkLogging(m_enableNetworkLogging);
  view->setAddress(m_address.toString());
  view->setPort(static_cast<int>(m_port));

  connect(view, &PositionObserverView::enableFileLoggingClicked, [this](bool checked) {
    m_enableFileLogging = checked;
    m_skydelNotifier->setDirty();
  });

  connect(view, &PositionObserverView::enableNetworkLoggingClicked, [this](bool checked) {
    m_enableNetworkLogging = checked;
    m_skydelNotifier->setDirty();
  });

  connect(view, &PositionObserverView::addressChanged, [this](const QString& address) {
    m_address = QHostAddress(address);
    m_skydelNotifier->setDirty();
  });

  connect(view, &PositionObserverView::portChanged, [this](int port) {
    m_port = port;
    m_skydelNotifier->setDirty();
  });

  connect(this, &PositionObserverPlugin::configurationChanged, [this, view]() {
    view->setEnableFileLogging(m_enableFileLogging);
    view->setEnableNetworkLogging(m_enableNetworkLogging);
    view->setAddress(m_address.toString());
    view->setPort(static_cast<int>(m_port));
  });

  return view;
}
