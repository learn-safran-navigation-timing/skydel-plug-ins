#ifndef POSITION_LOGGER_H
#define POSITION_LOGGER_H

#include <QFile>
#include <QUdpSocket>

#include "skydel_plug_ins/skydel_plugin.h"

// Runtime position observer implementation
class PositionLogger : public SkydelRuntimePositionObserver
{
  Q_OBJECT
public:
  explicit PositionLogger(SkydelNotifierInterface* skydelNotifier,
                          const QHostAddress& address,
                          uint16_t port,
                          bool enableNetworkLogging,
                          bool enableFileLogging,
                          const QString& logPath); // Called at simulation initialization phase
  ~PositionLogger();                               // Called at simluation ending phase
  void pushPosition(
    const SkydelRuntimePositionObserver::TimedPosition&) override; // Called at simluation running phase at 1000 Hz
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
#endif // POSITION_LOGGER_H
