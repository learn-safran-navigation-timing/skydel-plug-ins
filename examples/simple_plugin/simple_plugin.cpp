#include "simple_plugin.h"

#include "simple_plugin_view.h"

void SimplePlugin::setConfiguration(const QString& version, const QJsonObject& configuration)
{
  m_skydelNotifier->notify("Configuration comes from version " + version.toStdString());

  if (configuration.contains("message") && configuration["message"].isString())
  {
    m_notificationMessage = configuration["message"].toString();
  }

  if (configuration.contains("type"))
  {
    m_notificationType = static_cast<SkydelNotifierInterface::Type>(configuration["type"].toInt());
  }

  emit configurationChanged();
}

QJsonObject SimplePlugin::getConfiguration() const
{
  return {{"message", m_notificationMessage}, {"type", static_cast<int>(m_notificationType)}};
}

QWidget* SimplePlugin::createUI()
{
  auto view = new SimplePluginView;

  view->setNotification(m_notificationMessage, m_notificationType);

  connect(view, &SimplePluginView::sendNotificationClicked, [this]() {
    m_skydelNotifier->notify(m_notificationMessage.toStdString(), m_notificationType);
  });

  connect(view, &SimplePluginView::messageChanged, [this](const QString& message) {
    m_notificationMessage = message;
    m_skydelNotifier->setDirty();
  });

  connect(view, &SimplePluginView::typeChanged, [this](int type) {
    m_notificationType = static_cast<SkydelNotifierInterface::Type>(type);
    m_skydelNotifier->setDirty();
  });

  connect(this, &SimplePlugin::configurationChanged, [this, view]() {
    view->setNotification(m_notificationMessage, m_notificationType);
  });

  return view;
}
