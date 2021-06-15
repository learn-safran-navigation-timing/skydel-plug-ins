#include "imu_dynamic.h"

#include <QDir>

#include "imu_data_format.h"

ImuDynamic::ImuDynamic(const ImuConfiguration& configuration, const QString& logPath) :
  m_bodyDynamic(static_cast<Iml::GravityModel>(configuration.getValue("gravityModel").toInt()))
{
  if (configuration.getValue("fileLoggingEnabled").toBool())
    m_loggers.push_back(
      std::make_shared<ImuFileLogger>(static_cast<ImuDataFormat>(configuration.getValue("fileLoggingFormat").toInt()),
                                      logPath + QDir::separator() + "imu_dynamic"));

  if (configuration.getValue("networkLoggingEnabled").toBool())
    m_loggers.push_back(std::make_shared<ImuNetworkLogger>(static_cast<ImuDataFormat>(
                                                             configuration.getValue("networkLoggingFormat").toInt()),
                                                           configuration.getValue("networkLoggingAddress").toString(),
                                                           configuration.getValue("networkLoggingPort").toInt()));
}

void ImuDynamic::pushPosition(const TimedPosition& p)
{
  m_bodyDynamic.pushPosition(
    {p.time, {p.position.x, p.position.y, p.position.z}, {p.orientation.roll, p.orientation.pitch, p.orientation.yaw}});

  if (m_bodyDynamic.isReady())
  {
    auto data = m_bodyDynamic.getPosition();
    if (m_bodyDynamic.isReady())
      std::for_each(m_loggers.begin(), m_loggers.end(), [&data](ImuLoggerPtr logger) { logger->log(data); });
  }
}
