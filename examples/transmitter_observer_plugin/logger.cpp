#include "logger.h"

#include <QDir>
#include <QTextStream>

#include <cmath>
#include <stdexcept>

namespace
{
constexpr double SKYDEL_GPS_CA_DEFAULT_POWER_DBM = -131.5 + 3.0;
}

void Logger::reset(const QHostAddress& address,
                   uint16_t port,
                   bool enableNetworkLogging,
                   bool enableFileLogging,
                   const QString& logPath)
{
  m_address = address;
  m_port = port;
  m_enableFileLogging = enableFileLogging;
  m_enableNetworkLogging = enableNetworkLogging;
  m_logPath = logPath;

  if (m_file.isOpen())
  {
    m_file.close();
  }

  m_file.setFileName(m_logPath + QDir::separator() + "transmitter_observer_output.csv");

  if (m_enableFileLogging)
  {
    if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
      throw std::runtime_error("TransmitterLogger - Can't open file.");
    }
  }
}

void Logger::pushTransmitters(const SkydelRuntimeTransmitterObserver::TimedTransmitters& txs)
{
  m_currentTransmitters = txs;

  if (m_currentTransmitters.elapsedTimeMs == m_currentPosition.time)
  {
    processMs();
  }
}

void Logger::pushPosition(const SkydelRuntimePositionObserver::TimedPosition& p)
{
  m_currentPosition = p;

  if (m_currentTransmitters.elapsedTimeMs == m_currentPosition.time)
  {
    processMs();
  }
}

void Logger::close()
{
  m_file.close();
}

QString toString(const SkydelRuntimeTransmitterObserver::TimedTransmitters& txs)
{
  QString formattedData;
  QTextStream stream(&formattedData);
  stream.setRealNumberPrecision(5);

  for (const auto& interference : txs.interferences)
  {
    for (const auto& signal : interference.interferenceSignals)
    {
      auto signalPower = signal.gainAtVehicle - signal.propagationLoss;
      if (!std::isnan(signal.signalPower))
      {
        signalPower += signal.signalPower;
      }

      const auto totalPowerAtRx = interference.referencePower + signal.gainAtTransmitter + signalPower;
      const auto js = totalPowerAtRx - SKYDEL_GPS_CA_DEFAULT_POWER_DBM;

      stream << txs.elapsedTimeMs << ","
             << "Interference"
             << "," << interference.name << "," << signal.id << "," << signal.propagationLoss << "," << js << "\n";
    }
  }

  for (const auto& spoofer : txs.spoofers)
  {
    for (const auto& signal : spoofer.interferenceSignals)
    {
      const auto signalPower = signal.gainAtVehicle - signal.propagationLoss;
      const auto totalPowerAtRx = spoofer.referencePower + signal.gainAtTransmitter + signalPower;
      const auto js = totalPowerAtRx - SKYDEL_GPS_CA_DEFAULT_POWER_DBM;
      stream << txs.elapsedTimeMs << ","
             << "Spoofer"
             << "," << spoofer.name << "," << signal.id << "," << signal.propagationLoss << "," << js << "\n";
    }
  }

  return formattedData;
}

void Logger::processMs()
{
  m_lastProcessedMs = m_currentTransmitters.elapsedTimeMs;

  const auto formattedTransmitter = toString(m_currentTransmitters);

  if (m_enableNetworkLogging)
  {
    QByteArray byteArray;
    byteArray.append(formattedTransmitter);
    if (m_socket.writeDatagram(byteArray, m_address, m_port) == -1)
    {
      throw std::runtime_error(m_socket.errorString().toStdString().c_str());
    }
  }

  if (m_enableFileLogging)
  {
    QTextStream stream(&m_file);
    stream << formattedTransmitter;

    if (stream.status() == QTextStream::WriteFailed)
    {
      throw std::runtime_error("TransmitterLogger - Failed to write in file.");
    }
  }
}
