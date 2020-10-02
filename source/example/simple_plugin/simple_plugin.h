#ifndef SIMPLE_PLUGIN_H
#define SIMPLE_PLUGIN_H

#include "skydel_core_interface.h"
#include "skydel_plugin.h"

// Plugin implementation
class SimplePlugin : public QObject, public SkydelCoreInterface
{
  Q_OBJECT
public:
  explicit SimplePlugin(QObject* parent = nullptr);
  ~SimplePlugin() = default;

  void setLogPath(const QString &) override { }
  void setNotifier(SkydelNotifierInterface* notifier) override { m_skydelNotifier = notifier; }
  void setConfiguration(const QString& version, const QJsonObject& configuration) override;
  QJsonObject getConfiguration() const override;
  QWidget* createUI() override;

signals:
  void configurationChanged();

private:
  QString m_logPath;
  SkydelNotifierInterface* m_skydelNotifier;
  QString m_notificationMessage;
  SkydelNotifierInterface::Type m_notificationType;
};

// Required boilerplate
class SimplePluginFactory : public QObject, public SkydelPlugin<SimplePlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "SimplePlugin" FILE "simple_plugin.json")
  Q_INTERFACES(SkydelPluginBase)

public:
  explicit SimplePluginFactory(QObject *parent = nullptr);
};

#endif // SIMPLE_PLUGIN_H
