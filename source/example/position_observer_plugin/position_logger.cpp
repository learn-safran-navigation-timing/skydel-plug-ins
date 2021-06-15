#include "position_logger.h"

#include <QDir>
#include <QTextStream>

#include <stdexcept>

#include "position_observer_view.h"

PositionLogger::PositionLogger(SkydelNotifierInterface* skydelNotifier,
                               const QHostAddress& address,
                               uint16_t port,
                               bool enableNetworkLogging,
                               bool enableFileLogging,
                               const QString& logPath) :
  m_skydelNotifier(skydelNotifier),
  m_enableFileLogging(enableFileLogging),
  m_enableNetworkLogging(enableNetworkLogging),
  m_address(address),
  m_port(port),
  m_logPath(logPath),
  m_file(m_logPath + QDir::separator() + "position_observer_output.csv")
{
  if (m_enableFileLogging)
  {
    if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
      throw std::runtime_error("PositionLogger - Can't open file.");
    }
  }

  m_skydelNotifier->notify("PositionLogger initialized");
}

PositionLogger::~PositionLogger()
{
  emit lockConfiguration(false);
}

void PositionLogger::pushPosition(const TimedPosition& p)
{
  QString formatedPosition = toString(p);

  if ((p.time % 1000) == 0)
  {
    emit updatePosition(p);
  }

  if (m_enableNetworkLogging)
  {
    QByteArray byteArray;
    byteArray.append(formatedPosition);
    if (m_socket.writeDatagram(byteArray, m_address, m_port) == -1)
    {
      throw std::runtime_error(m_socket.errorString().toStdString().c_str());
    }
  }

  if (m_enableFileLogging)
  {
    QTextStream stream(&m_file);
    stream << formatedPosition;

    if (stream.status() == QTextStream::WriteFailed)
    {
      throw std::runtime_error("PositionLogger - Failed to write in file.");
    }
  }
}

void PositionLogger::connectToView(QWidget* view)
{
  if (auto positionObserverView = dynamic_cast<PositionObserverView*>(view))
  {
    positionObserverView->clear();
    positionObserverView->lockConfiguration(true);
    connect(this, &PositionLogger::updatePosition, positionObserverView, &PositionObserverView::updatePosition);
    connect(this, &PositionLogger::lockConfiguration, positionObserverView, &PositionObserverView::lockConfiguration);
  }
}

QString PositionLogger::toString(const SkydelRuntimePositionObserver::TimedPosition& p)
{
  QString formattedData;
  QTextStream stream(&formattedData);
  stream.setRealNumberPrecision(15);
  stream << p.time << ',' << p.position.x << ',' << p.position.y << ',' << p.position.z << ',' << p.orientation.roll
         << ',' << p.orientation.pitch << ',' << p.orientation.yaw << '\n';

  return formattedData;
}
