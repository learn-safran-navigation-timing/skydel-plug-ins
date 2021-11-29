#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QHostAddress>
#include <QString>
#include <QUdpSocket>

#include "skydel_plug_ins/skydel_position_observer_interface.h"
#include "skydel_plug_ins/skydel_transmitter_observer_interface.h"

class Logger
{
public:
  Logger() = default;

  void reset(const QHostAddress& address,
             uint16_t port,
             bool enableNetworkLogging,
             bool enableFileLogging,
             const QString& logPath);

  void pushTransmitters(const SkydelRuntimeTransmitterObserver::TimedTransmitters& txs);
  void pushPosition(const SkydelRuntimePositionObserver::TimedPosition& p);

  void close();

private:
  void processMs();

  SkydelRuntimePositionObserver::TimedPosition m_currentPosition;
  SkydelRuntimeTransmitterObserver::TimedTransmitters m_currentTransmitters;

  int64_t m_lastProcessedMs;
  bool m_enableFileLogging;
  bool m_enableNetworkLogging;
  QHostAddress m_address;
  uint16_t m_port;
  QString m_logPath;
  QFile m_file;
  QUdpSocket m_socket;
};

#endif // LOGGER_H
