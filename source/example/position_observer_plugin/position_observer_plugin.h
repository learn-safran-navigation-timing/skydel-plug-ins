#ifndef POSITION_OBSERVER_PLUGIN_H
#define POSITION_OBSERVER_PLUGIN_H

#include <QFile>
#include <QString>
#include <QUdpSocket>

#include "skydel_core_interface.h"
#include "skydel_plugin.h"
#include "skydel_position_observer_interface.h"

// Runtime position observer implementation
class PositionLogger : public SkydelRuntimePositionObserver
{
  Q_OBJECT
public:
  explicit PositionLogger(SkydelNotifierInterface* skydelNotifier, const QHostAddress& address, uint16_t port, bool enableNetworkLogging, bool enableFileLogging, const QString &logPath); // Called at simulation initialization phase
  ~PositionLogger(); // Called at simluation ending phase
  void pushPosition(const SkydelRuntimePositionObserver::TimedPosition &) override; // Called at simluation running phase at 1000 Hz
  void connectToView(QWidget*) override;

signals:
  void updatePosition(const SkydelRuntimePositionObserver::TimedPosition& p);
  void lockConfiguration(bool lock);

private:
  QString toString(const SkydelRuntimePositionObserver::TimedPosition& p);

  SkydelNotifierInterface* m_skydelNotifier;
  bool m_enableFileLogging;
  bool m_enableNetworkLogging;
  QHostAddress m_address;
  uint16_t m_port;
  QString m_logPath;
  QFile m_file;
  QUdpSocket m_socket;
};

// Plugin implementation
class PositionObserverPlugin : public QObject, public SkydelCoreInterface, public SkydelPositionObserverInterface
{
  Q_OBJECT
public:
  explicit PositionObserverPlugin(QObject* parent = nullptr);
  ~PositionObserverPlugin() = default;

  void setLogPath(const QString &path) override { m_logPath = path; }
  void setNotifier(SkydelNotifierInterface* notifier) override { m_skydelNotifier = notifier; }
  void setConfiguration(const QString& version, const QJsonObject& configuration) override;
  QJsonObject getConfiguration() const override;
  QWidget* createUI() override;

  SkydelRuntimePositionObserver* createRuntimePositionObserver() override { return new PositionLogger(m_skydelNotifier, m_address, m_port, m_enableNetworkLogging, m_enableFileLogging, m_logPath); }

signals:
  void configurationChanged();

private:
  bool m_enableFileLogging;
  bool m_enableNetworkLogging;
  QHostAddress m_address;
  uint16_t m_port;
  QString m_logPath;
  SkydelNotifierInterface* m_skydelNotifier;
};

// Required boilerplate
class PositionObserverPluginFactory : public QObject, public SkydelPlugin<PositionObserverPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "PositionObserverPlugin" FILE "position_observer_plugin.json")
  Q_INTERFACES(SkydelPluginBase)

public:
  explicit PositionObserverPluginFactory(QObject *parent = nullptr);
};

#endif // POSITION_OBSERVER_PLUGIN_H
