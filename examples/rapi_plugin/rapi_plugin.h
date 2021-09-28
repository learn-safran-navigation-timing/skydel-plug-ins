#ifndef RAPI_PLUGIN_H
#define RAPI_PLUGIN_H

#include <optional>

#include "skydel_plug_ins/skydel_plugin.h"
#include "skydel_plug_ins/skydel_rapi_access.h"

// Plugin implementation
class RapiPlugin : public QObject, public SkydelCoreInterface, public SkydelRapiAccess
{
public:
  // SkydelCoreInterface
  inline void setLogPath([[maybe_unused]] const QString& path) override {};
  inline void setNotifier(SkydelNotifierInterface* notifier) override { m_notifier = notifier; }
  inline void setConfiguration([[maybe_unused]] const QString& version,
                               [[maybe_unused]] const QJsonObject& configuration) override
  {
  }
  inline QJsonObject getConfiguration() const override { return QJsonObject {}; }
  QWidget* createUI() override;
  inline void initialize() override {}

private:
  SkydelNotifierInterface* m_notifier;
};

// Required boilerplate
class RapiPluginFactory : public QObject, public SkydelPlugin<RapiPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "RapiPlugin" FILE "rapi_plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // RAPI_PLUGIN_H
