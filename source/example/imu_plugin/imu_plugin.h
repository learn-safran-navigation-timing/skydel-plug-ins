#ifndef IMU_PLUGIN_H
#define IMU_PLUGIN_H

#include "imu_configuration.h"
#include "imu_dynamic.h"
#include "skydel_plugin.h"

class ImuPlugin : public QObject, public SkydelCoreInterface, public SkydelPositionObserverInterface
{
  Q_OBJECT
public:
  explicit ImuPlugin(QObject* parent = nullptr);

  void setLogPath(const QString &path) override { m_logPath = path; }
  void setNotifier(SkydelNotifierInterface* notifier) override { m_skydelNotifier = notifier; }
  void setConfiguration(const QString&, const QJsonObject& configuration) override;
  QJsonObject getConfiguration() const  override { return m_configuration.getConfiguration(); }
  QWidget* createUI() override;

  SkydelRuntimePositionObserver* createRuntimePositionObserver() override { return new ImuDynamic(m_configuration, m_logPath); }

signals:
  void configurationChanged();

private:
  QString m_logPath;
  SkydelNotifierInterface* m_skydelNotifier;
  ImuConfiguration m_configuration;
};

class ImuPluginFactory : public QObject, public SkydelPlugin<ImuPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "ImuPlugin" FILE "imu_plugin.json")
  Q_INTERFACES(SkydelPluginBase)

public:
  explicit ImuPluginFactory(QObject *parent = nullptr);
};

#endif // IMU_PLUGIN_H
