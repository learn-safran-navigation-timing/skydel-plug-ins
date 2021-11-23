#ifndef POSITION_OBSERVER_PLUGIN_H
#define POSITION_OBSERVER_PLUGIN_H

#include <QString>
#include <QUdpSocket>

#include "position_logger.h"
#include "skydel_plug_ins/skydel_plugin.h"

// Plugin implementation
class PositionObserverPlugin : public QObject, public SkydelCoreInterface, public SkydelPositionObserverInterface
{
  Q_OBJECT

public:
  // SkydelCoreInterface
  inline void setLogPath(const QString& path) override { m_logPath = path; }
  inline void setNotifier(SkydelNotifierInterface* notifier) override { m_skydelNotifier = notifier; }
  void setConfiguration(const QString& version, const QJsonObject& configuration) override;
  QJsonObject getConfiguration() const override;
  QWidget* createUI() override;
  inline void initialize() override {}

  // SkydelPositionObserverInterface
  inline SkydelRuntimePositionObserver* createRuntimePositionObserver() override
  {
    return new PositionLogger(m_skydelNotifier,
                              m_address,
                              m_port,
                              m_enableNetworkLogging,
                              m_enableFileLogging,
                              m_logPath);
  }

signals:
  void configurationChanged();

private:
  bool m_enableFileLogging {true};
  bool m_enableNetworkLogging {true};
  QHostAddress m_address {QHostAddress(QHostAddress::LocalHost)};
  uint16_t m_port {161};
  QString m_logPath;
  SkydelNotifierInterface* m_skydelNotifier;
};

// Required boilerplate
class PositionObserverPluginFactory : public QObject, public SkydelPlugin<PositionObserverPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "PositionObserverPlugin" FILE "position_observer_plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // POSITION_OBSERVER_PLUGIN_H
