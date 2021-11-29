#ifndef TRANSMITTER_OBSERVER_PLUGIN_H
#define TRANSMITTER_OBSERVER_PLUGIN_H

#include <QString>
#include <QUdpSocket>

#include "logger.h"
#include "skydel_plug_ins/skydel_plugin.h"

// Plugin implementation
class TransmitterObserverPlugin :
  public QObject,
  public SkydelCoreInterface,
  public SkydelPositionObserverInterface,
  public SkydelTransmitterObserverInterface
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

  // SkydelTransmitterObserverInterface
  SkydelRuntimeTransmitterObserver* createRuntimeTransmitterObserver() override;

  // SkydelPositionObserverInterface
  SkydelRuntimePositionObserver* createRuntimePositionObserver() override;

signals:
  void configurationChanged();

private slots:
  void onNewTransmitterUpdate(const SkydelRuntimeTransmitterObserver::TimedTransmitters& txs);
  void onNewPositionUpdate(const SkydelRuntimePositionObserver::TimedPosition& p);
  void onSimulationEnd();

private:
  bool m_enableFileLogging {true};
  bool m_enableNetworkLogging {true};
  uint16_t m_port {161};
  Logger m_logger;
  QHostAddress m_address {QHostAddress(QHostAddress::LocalHost)};
  QString m_logPath;
  SkydelNotifierInterface* m_skydelNotifier;
};

// Required boilerplate
class TransmitterObserverPluginFactory : public QObject, public SkydelPlugin<TransmitterObserverPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "TransmitterObserverPlugin" FILE "transmitter_observer_plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // TRANSMITTER_OBSERVER_PLUGIN_H
