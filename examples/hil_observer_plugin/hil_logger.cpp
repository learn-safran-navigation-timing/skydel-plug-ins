#include "hil_logger.h"

#include <QDir>
#include <QTextStream>

#include <stdexcept>

#include "hil_observer_view.h"

HilLogger::HilLogger(const QString& logPath, bool enableFileLogging, SkydelNotifierInterface* skydelNotifier) :
  m_skydelNotifier(skydelNotifier),
  m_enableFileLogging(enableFileLogging),
  m_file(logPath + QDir::separator() + "hil_observer_output.csv"),
  m_displayedPosTimestamp(0)
{
  if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
  {
    throw std::runtime_error("HilLogger - Can't open file.");
  }
}

HilLogger::~HilLogger()
{
  emit lockConfiguration(false);
}

void HilLogger::pushHilInput(const TimedPosition& p)
{
  if (p.time > (m_displayedPosTimestamp + 1000))
  {
    m_displayedPosTimestamp = p.time;
    emit updatePosition(p);
  }

  if (m_enableFileLogging)
  {
    QTextStream stream(&m_file);
    stream << toString(p);
    if (stream.status() == QTextStream::WriteFailed)
    {
      throw std::runtime_error("HilLogger - Failed to write in file.");
    }
  }
}

void HilLogger::connectToView(QWidget* view)
{
  if (auto hilObserverView = dynamic_cast<HilObserverView*>(view))
  {
    hilObserverView->clear();
    hilObserverView->lockConfiguration(true);
    connect(this, &HilLogger::updatePosition, hilObserverView, &HilObserverView::updatePosition);
    connect(this, &HilLogger::lockConfiguration, hilObserverView, &HilObserverView::lockConfiguration);
  }
}

QString HilLogger::toString(const TimedPosition& p)
{
  QString formattedData;
  QTextStream stream(&formattedData);
  stream.setRealNumberPrecision(15);
  stream << p.time << ',' << p.position.x << ',' << p.position.y << ',' << p.position.z << ',' << p.orientation.roll
         << ',' << p.orientation.pitch << ',' << p.orientation.yaw << '\n';

  return formattedData;
}
