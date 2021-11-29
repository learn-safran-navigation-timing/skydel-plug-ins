#ifndef HIL_OBSERVER_PLUGIN_H
#define HIL_OBSERVER_PLUGIN_H

#include "skydel_plug_ins/skydel_plugin.h"

// Plugin implementation
class HilObserverPlugin : public QObject, public SkydelCoreInterface, public SkydelHilObserverInterface
{
  Q_OBJECT

public:
  // SkydelCoreInterface
  inline void setLogPath(const QString& logPath) override { m_logPath = logPath; }
  inline void setNotifier(SkydelNotifierInterface* notifier) override { m_skydelNotifier = notifier; }
  void setConfiguration(const QString&, const QJsonObject& configuration) override;
  QJsonObject getConfiguration() const override;
  QWidget* createUI() override;
  inline void initialize() override {}

  // SkydelHilObserverInterface
  SkydelRuntimeHilObserver* createRuntimeHilObserver() override;

signals:
  void configurationChanged();

private:
  QString m_logPath;
  bool m_enableFileLogging;
  SkydelNotifierInterface* m_skydelNotifier;
};

// Required boilerplate
class HilObserverPluginFactory : public QObject, public SkydelPlugin<HilObserverPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "HilObserverPlugin" FILE "hil_observer_plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // HIL_OBSERVER_PLUGIN_H
