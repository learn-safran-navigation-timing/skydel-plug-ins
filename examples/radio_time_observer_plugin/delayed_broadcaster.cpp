#include "delayed_broadcaster.h"

#include <QCoreApplication>
#include <QQueue>
#include <QUdpSocket>

#include <thread>

constexpr std::chrono::microseconds GRACE_PERIOD {100}; // Period in microseconds to send a packet ahead of the deadline

DelayedBroadcaster::DelayedBroadcaster(QObject* parent) : QObject(parent)
{
}

void DelayedBroadcaster::reset(const QHostAddress& ipAddress, int port)
{
  // Create a worker and connect our signals for thread-safe queueing
  auto* workerPtr = new DelayedBroadcasterWorker(ipAddress, port);
  connect(this, &DelayedBroadcaster::enqueue, workerPtr, &DelayedBroadcasterWorker::enqueue);
  m_threadPtr = new QThread;

  // Set up the worker in our member thread and start it
  workerPtr->moveToThread(m_threadPtr);
  connect(workerPtr, &DelayedBroadcasterWorker::error, this, &DelayedBroadcaster::handleWorkerError);
  connect(m_threadPtr, &QThread::started, workerPtr, &DelayedBroadcasterWorker::process);
  connect(workerPtr, &DelayedBroadcasterWorker::finished, m_threadPtr, &QThread::quit);
  connect(workerPtr, &DelayedBroadcasterWorker::finished, workerPtr, &DelayedBroadcasterWorker::deleteLater);
  connect(m_threadPtr, &QThread::finished, m_threadPtr, &QThread::deleteLater);
  m_threadPtr->setObjectName("DelayedBroadcasterWorker");
  m_threadPtr->start(QThread::Priority::TimeCriticalPriority);
}

void DelayedBroadcaster::close()
{
  m_threadPtr->requestInterruption(); // m_thread_p will delete itself after QThread::finished
}

void DelayedBroadcaster::handleWorkerError(QString errorMessage)
{
  m_error = true;
  m_errorMessage = errorMessage;
}

DelayedBroadcasterWorker::DelayedBroadcasterWorker(const QHostAddress& ipAddress, int port) :
  QObject(),
  m_address(ipAddress),
  m_port(port)
{
}

/* The main loop of this worker is implemented with the goal of acheiving high accuracy
 * regarding the transmission of UDP packets relative to RF transmission. It expects not
 * to be required to send UDP packets more often than once every 100 microseconds. This
 * implementation of a loop will not permit the QThread to process Qt events, such as
 * Enqueue, unless QCoreApplication::processEvents() is called. This is called after the
 * primary sleep encountered if the processing queue is found to be empty.
 *
 * std::this_thread::sleep_for can only guarantee a minimum sleep time, so this loop uses
 * sleeps that are shorter than what is necessary.
 */
void DelayedBroadcasterWorker::process()
{
  QUdpSocket socket;
  while (!QThread::currentThread()->isInterruptionRequested())
  {
    if (!m_queue.empty())
    {
      const auto& nextPackage = m_queue.head();
      const auto now = std::chrono::steady_clock::now();
      const auto durationToDeadline = nextPackage.deadline - now;

      // Send if we are within GRACE_PERIOD of the deadline or after the deadline (zero or negative usToDeadline)
      if (durationToDeadline > GRACE_PERIOD)
      {
        std::this_thread::sleep_for(durationToDeadline / 2);
      }
      else
      {
        // Send packet
        if (socket.writeDatagram(nextPackage.networkData, m_address, m_port) == -1)
        {
          emit error(socket.errorString());
          QThread::currentThread()->requestInterruption();
        }

        m_queue.dequeue();
      }
    }
    else
    {
      std::this_thread::sleep_for(std::chrono::microseconds(100));
      QCoreApplication::processEvents();
    }
  }

  emit finished();
}

void DelayedBroadcasterWorker::enqueue(const QByteArray& networkData,
                                       const std::chrono::time_point<std::chrono::steady_clock>& deadline)
{
  FuturePackage fp {networkData, deadline};
  m_queue.push_back(fp); // This is thread safe if enqueue is called via signals/slots
}
