#ifndef IMU_PLUGIN_H
#define IMU_PLUGIN_H

#include "imu_configuration.h"
#include "imu_dynamic.h"
#include "skydel_plug_ins/skydel_plugin.h"

// Plugin implementation
class ImuPlugin : public QObject, public SkydelCoreInterface, public SkydelPositionObserverInterface
{
  Q_OBJECT

public:
  // SkydelCoreInterface
  inline void setLogPath(const QString& path) override { m_logPath = path; }
  inline void setNotifier(SkydelNotifierInterface* notifier) override { m_skydelNotifier = notifier; }
  void setConfiguration(const QString&, const QJsonObject& configuration) override;
  inline QJsonObject getConfiguration() const override { return m_configuration.getConfiguration(); }
  QWidget* createUI() override;
  inline void initialize() override {}

  // SkydelPositionObserverInterface
  SkydelRuntimePositionObserver* createRuntimePositionObserver() override
  {
    return new ImuDynamic(m_configuration, m_logPath);
  }

signals:
  void configurationChanged();

private:
  QString m_logPath;
  SkydelNotifierInterface* m_skydelNotifier;
  ImuConfiguration m_configuration;
};

// Required boilerplate
class ImuPluginFactory : public QObject, public SkydelPlugin<ImuPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "ImuPlugin" FILE "imu_plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // IMU_PLUGIN_H
