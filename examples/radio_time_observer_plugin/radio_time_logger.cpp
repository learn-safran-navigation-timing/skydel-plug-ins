#include "radio_time_logger.h"

#include <QDir>
#include <QTextStream>

#include <stdexcept>

#include "radio_time_observer_view.h"

constexpr uint32_t NETWORK_UPDATE_RATE_HZ {1000}; // Use HZ rates that divide nicely into 1000

void RadioTimeLogger::reset(SkydelNotifierInterface* skydelNotifier,
                            const QHostAddress& address,
                            uint16_t port,
                            bool enableNetworkLogging,
                            bool enableFileLogging,
                            const QString& logPath)
{
  m_skydelNotifierPtr = skydelNotifier;
  m_address = address;
  m_port = port;
  m_enableNetworkLogging = enableNetworkLogging;
  m_enableFileLogging = enableFileLogging;
  m_logPath = logPath;

  m_file.close();
  if (m_enableFileLogging)
  {
    m_file.setFileName(m_logPath + QDir::separator() + "radio_time_observer_output.csv");
    if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
      throw std::runtime_error("RadioTimeLogger - Can't open file.");
    }
  }

  m_broadcaster.reset(address, port);
  m_skydelNotifierPtr->notify("RadioTimeLogger initialized");
}

RadioTimeLogger::~RadioTimeLogger()
{
  emit lockConfiguration(false);
}

void RadioTimeLogger::pushRadioTime(const SkydelRuntimeRadioTimeObserver::RadioTimeEstimate& rte)
{
  m_latestEstimate = rte;
  emit updateRadioTime(rte);
}

void RadioTimeLogger::pushPosition(const SkydelRuntimePositionObserver::TimedPosition& p)
{
  // Check if our DelayedBroadcaster has encountered an error. If so, Skydel will gracefully
  // catch a std::exception and print an error message to a status log.
  if (m_broadcaster.isHalted())
  {
    throw std::runtime_error(m_broadcaster.getErrorMessage().toStdString().c_str());
  }

  // The deadline is the steady_clock time that the RF corresponding to the TimedPosition
  // will leave the radio RF port.
  //
  // usUntilRfTransmission is the number of microseconds until that RF transmission from now.
  const auto deadline = SkydelRuntimeRadioTimeObserver::getDeadline(p.time, m_latestEstimate);
  const auto usUntilRfTransmission =
    SkydelRuntimeRadioTimeObserver::microsecondsUntilRadioTransmission(p.time, m_latestEstimate);

  emit updatePosition(p, usUntilRfTransmission);

  if (m_enableNetworkLogging && p.time % (1000 / NETWORK_UPDATE_RATE_HZ) == 0)
  {
    const auto networkData = toString(p, usUntilRfTransmission).toUtf8();
    m_broadcaster.enqueue(networkData, deadline);
  }

  if (m_enableFileLogging)
  {
    const auto formattedRadioTime = toString(p, usUntilRfTransmission);
    QTextStream stream(&m_file);
    stream << formattedRadioTime;

    if (stream.status() == QTextStream::WriteFailed)
    {
      throw std::runtime_error("RadioTimeLogger - Failed to write in file.");
    }
  }
}

void RadioTimeLogger::connectToView(QWidget* view)
{
  if (auto radioTimeObserverView = dynamic_cast<RadioTimeObserverView*>(view))
  {
    radioTimeObserverView->clear();
    radioTimeObserverView->lockConfiguration(true);
    connect(this, &RadioTimeLogger::updateRadioTime, radioTimeObserverView, &RadioTimeObserverView::updateRadioTime);
    connect(this, &RadioTimeLogger::updatePosition, radioTimeObserverView, &RadioTimeObserverView::updatePosition);
    connect(this,
            &RadioTimeLogger::lockConfiguration,
            radioTimeObserverView,
            &RadioTimeObserverView::lockConfiguration);
  }
}

void RadioTimeLogger::close()
{
  m_file.close();
  m_broadcaster.close();
}

QString RadioTimeLogger::toString(const SkydelRuntimePositionObserver::TimedPosition& p,
                                  int64_t estimatedMicrosecondsToRfTx)
{
  QString formattedData;
  QTextStream stream(&formattedData);
  stream.setRealNumberPrecision(15);
  stream << p.time << ',' << estimatedMicrosecondsToRfTx << "," << p.position.x << ',' << p.position.y << ','
         << p.position.z << '\n';

  return formattedData;
}
