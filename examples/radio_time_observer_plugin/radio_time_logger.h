#ifndef RADIO_TIME_LOGGER_H
#define RADIO_TIME_LOGGER_H

#include <QFile>
#include <QObject>

#include "delayed_broadcaster.h"
#include "skydel_plug_ins/skydel_plugin.h"

// This class will receive data from the runtime objects and do the following
// - Log, over network or by file, the time data was processed relative to RF transmission
// - Transmit, via DelayedBroadcaster, the received position at approximately the same time as RF transmission
class RadioTimeLogger : public QObject
{
  Q_OBJECT
public:
  void reset(SkydelNotifierInterface* skydelNotifier,
             const QHostAddress& address,
             uint16_t port,
             bool enableNetworkLogging,
             bool enableFileLogging,
             const QString& logPath);
  ~RadioTimeLogger();
  void connectToView(QWidget*);

public slots:
  void pushRadioTime(const SkydelRuntimeRadioTimeObserver::RadioTimeEstimate&);
  void pushPosition(const SkydelRuntimePositionObserver::TimedPosition&);
  void close();

signals:
  void updatePosition(const SkydelRuntimePositionObserver::TimedPosition& p, int64_t usTimeToRfTx);
  void updateRadioTime(const SkydelRuntimeRadioTimeObserver::RadioTimeEstimate& rte);
  void lockConfiguration(bool lock);

private:
  QString toString(const SkydelRuntimePositionObserver::TimedPosition& p, int64_t estimateOfMicrosecondsToRfTx);

  SkydelRuntimeRadioTimeObserver::RadioTimeEstimate m_latestEstimate;
  DelayedBroadcaster m_broadcaster;

  SkydelNotifierInterface* m_skydelNotifierPtr;
  bool m_enableFileLogging;
  bool m_enableNetworkLogging;
  QHostAddress m_address;
  uint16_t m_port;
  QString m_logPath;
  QFile m_file;
};

#endif // RADIO_TIME_LOGGER_H
