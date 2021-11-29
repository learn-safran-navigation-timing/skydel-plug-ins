#ifndef DELAYED_BROADCASTER_H
#define DELAYED_BROADCASTER_H

#include <QHostAddress>
#include <QObject>
#include <QQueue>
#include <QThread>

#include <chrono>

/* The DelayedBroadcaster class attempts to delay sending
 * UDP packets until exactly RF transmission.
 *
 * This class is useful when the consumer of these UDP
 * packets is not designed to receive the contents ahead
 * of GPS time/RF transmission.
 *
 * This class manages a separate thread in which the
 * DelayedBroadcastWorker runs. It pushes data to the
 * thread using QT's thread-safe signals/slots.
 *
 * The DelayedBroadcastWorker waits until the given
 * deadline before sending the packet. There is a grace
 * period where the packet may be sent ahead of the deadline.
 *
 * In practice, the usual-case of the DelayedBroadcaster
 * is very good and can send packets within microseconds
 * of matching RF. However, hiccups on the order of a few
 * milliseconds may occur and this class cannot guarantee
 * the broadcast time of any packet.
 *
 * This class will be at the mercy of the operating system
 * scheduler.
 */

class DelayedBroadcasterWorker : public QObject
{
  Q_OBJECT

public:
  DelayedBroadcasterWorker(const QHostAddress& ipAddress, int port);

public slots:
  void process();
  void enqueue(const QByteArray& networkData, const std::chrono::time_point<std::chrono::steady_clock>& deadline);

signals:
  void finished();
  void error(QString message);

private:
  struct FuturePackage
  {
    QByteArray networkData;
    std::chrono::time_point<std::chrono::steady_clock> deadline;
  };

  QQueue<FuturePackage> m_queue;
  QHostAddress m_address;
  uint16_t m_port;
};

class DelayedBroadcaster : public QObject
{
  Q_OBJECT

public:
  explicit DelayedBroadcaster(QObject* parent = nullptr);
  void reset(const QHostAddress& ipAddress, int port);
  void close();

  bool isHalted() const { return m_error; }
  QString getErrorMessage() const { return m_errorMessage; }

signals:
  void enqueue(const QByteArray& networkData, const std::chrono::time_point<std::chrono::steady_clock>& deadline);

private slots:
  void handleWorkerError(QString errorMessage);

private:
  QThread* m_threadPtr;
  bool m_error {false};
  QString m_errorMessage {""};
};

#endif // DELAYED_BROADCASTER_H
