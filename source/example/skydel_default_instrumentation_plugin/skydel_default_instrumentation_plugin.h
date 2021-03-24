#ifndef SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_H
#define SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_H

#include <optional>

#include "skydel_plugin.h"

class SkydelDefaultInstrumentationPlugin : public QObject, public SkydelCoreInterface, public SkydelInstrumentationInterface
{
  // SkydelCoreInterface interface
public:
  void setLogPath(const QString &path) override;
  inline void setNotifier([[maybe_unused]] SkydelNotifierInterface* notifier) override {}
  inline void setConfiguration([[maybe_unused]] const QString &version, [[maybe_unused]] const QJsonObject &configuration) override {}
  QJsonObject getConfiguration() const override;
  QWidget *createUI() override;

  // SkydelInstrumentationInterface interface
public:
  void setEngineGraph(const std::vector<Node>& nodes, const std::vector<Pipe>& pipes) override;
  void pushQueueMeasures(const std::vector<QueueMeasure>& queues) override;

private:
  QString m_path;
  std::optional<int> m_queueSizeReference;
};

class SkydelDefaultInstrumentationPluginFactory : public QObject, public SkydelPlugin<SkydelDefaultInstrumentationPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "SkydelDefaultInstrumentationPlugin" FILE "skydel_default_instrumentation_plugin.json")
  Q_INTERFACES(SkydelPluginBase)

public:
  explicit SkydelDefaultInstrumentationPluginFactory(QObject *parent = nullptr);
};

#endif // SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_H
