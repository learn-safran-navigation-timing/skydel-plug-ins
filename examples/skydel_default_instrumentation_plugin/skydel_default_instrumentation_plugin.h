#ifndef SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_H
#define SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_H

#include <optional>

#include "skydel_plug_ins/skydel_plugin.h"

// Plugin implementation
class SkydelDefaultInstrumentationPlugin :
  public QObject,
  public SkydelCoreInterface,
  public SkydelInstrumentationInterface
{
public:
  // SkydelCoreInterface
  void setLogPath(const QString& path) override;
  inline void setNotifier([[maybe_unused]] SkydelNotifierInterface* notifier) override {}
  inline void setConfiguration([[maybe_unused]] const QString& version,
                               [[maybe_unused]] const QJsonObject& configuration) override
  {
  }
  inline QJsonObject getConfiguration() const override { return QJsonObject {}; }
  inline QWidget* createUI() override { return nullptr; }
  inline void initialize() override {}

  // SkydelInstrumentationInterface
  void setEngineGraph(const std::vector<Node>& nodes, const std::vector<Pipe>& pipes) override;
  void pushQueueMeasures(const std::vector<QueueMeasure>& queues) override;

private:
  QString m_path;
  std::optional<int> m_queueSizeReference;
};

// Required boilerplate
class SkydelDefaultInstrumentationPluginFactory :
  public QObject,
  public SkydelPlugin<SkydelDefaultInstrumentationPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "SkydelDefaultInstrumentationPlugin" FILE "skydel_default_instrumentation_plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // SKYDEL_DEFAULT_INSTRUMENTATION_PLUGIN_H
