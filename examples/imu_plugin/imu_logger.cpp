#include "imu_logger.h"

#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

#include <stdexcept>

const QString ELASPED_JSON_KEY = "elapsed";
const QString ACCELERATION_JSON_KEY = "acceleration";
const QString ANGULAR_VELOCITY_JSON_KEY = "angularvelocity";

const QString ELAPSED_TIME = "Elapsed Time (ms)";
const QJsonArray ACCELERATION = {"Acceleration X (m/s^2)", "Acceleration Y (m/s^2)", "Acceleration Z (m/s^2)"};
const QJsonArray ANGULAR_VELOCITY = {"Angular Velocity Roll (rad/s)",
                                     "Angular Velocity Pitch (rad/s)",
                                     "Angular Velocity Yaw (rad/s)"};

const QString ImuLogger::csvHeader = ELAPSED_TIME + ',' + ACCELERATION.at(0).toString() + ',' +
                                     ACCELERATION.at(1).toString() + ',' + ACCELERATION.at(2).toString() + ',' +
                                     ANGULAR_VELOCITY.at(0).toString() + ',' + ANGULAR_VELOCITY.at(1).toString() + ',' +
                                     ANGULAR_VELOCITY.at(2).toString() + '\n';

const QString ImuLogger::jsonHeader = QJsonDocument(QJsonObject({{ELASPED_JSON_KEY, ELAPSED_TIME},
                                                                 {ACCELERATION_JSON_KEY, ACCELERATION},
                                                                 {ANGULAR_VELOCITY_JSON_KEY, ANGULAR_VELOCITY}}))
                                        .toJson();

ImuLogger::ImuLogger(ImuDataFormat dataFormat) : m_dataFormat(dataFormat)
{
}

QString ImuLogger::getHeader() const
{
  switch (m_dataFormat)
  {
    case ImuDataFormat::CSV:
      return csvHeader;
    case ImuDataFormat::JSON:
      return jsonHeader;
    default:
      return "INVALID";
  }
}

QString ImuLogger::getFormattedData(const Iml::InertialData& data) const
{
  switch (m_dataFormat)
  {
    case ImuDataFormat::CSV:
      return getFormattedDataInCsvFormat(data);
    case ImuDataFormat::JSON:
      return getFormattedDataInJsonFormat(data);
    default:
      return "INVALID";
  }
}

QString ImuLogger::getFormattedDataInCsvFormat(const Iml::InertialData& data) const
{
  QString formattedData;
  QTextStream stream(&formattedData);
  stream.setRealNumberPrecision(15);
  stream << data.time << ',' << Iml::x(data.acceleration) << ',' << Iml::y(data.acceleration) << ','
         << Iml::z(data.acceleration) << ',' << Iml::roll(data.angularVelocity) << ','
         << Iml::pitch(data.angularVelocity) << ',' << Iml::yaw(data.angularVelocity) << '\n';

  return formattedData;
}

QString ImuLogger::getFormattedDataInJsonFormat(const Iml::InertialData& data) const
{
  QJsonObject formattedData;
  formattedData.insert(ELASPED_JSON_KEY, static_cast<double>(data.time));
  formattedData.insert(ACCELERATION_JSON_KEY,
                       QJsonArray {Iml::x(data.acceleration), Iml::y(data.acceleration), Iml::z(data.acceleration)});
  formattedData.insert(ANGULAR_VELOCITY_JSON_KEY,
                       QJsonArray {Iml::roll(data.angularVelocity),
                                   Iml::pitch(data.angularVelocity),
                                   Iml::yaw(data.angularVelocity)});

  QJsonDocument jsonDocument(formattedData);

  return jsonDocument.toJson();
}

const QString ImuFileLogger::csvFileExtension = ".csv";
const QString ImuFileLogger::jsonFileExtension = ".json";

ImuFileLogger::ImuFileLogger(ImuDataFormat dataFormat, QString logFilePath) :
  ImuLogger(dataFormat),
  m_file(std::move(logFilePath + getFileExtension()))
{
  if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    throw std::runtime_error("ImuFileLogger - Can't open file.");

  writeInFile(getHeader());
}

ImuFileLogger::~ImuFileLogger()
{
  m_file.close();
}

void ImuFileLogger::log(const Iml::InertialData& data)
{
  writeInFile(getFormattedData(data));
}

QString ImuFileLogger::getFileExtension() const
{
  switch (m_dataFormat)
  {
    case ImuDataFormat::CSV:
      return csvFileExtension;
    case ImuDataFormat::JSON:
      return jsonFileExtension;
    default:
      return ".txt";
  }
}

void ImuFileLogger::writeInFile(const QString& string)
{
  QTextStream stream(&m_file);
  stream << string;

  if (stream.status() == QTextStream::WriteFailed)
    throw std::runtime_error("ImuFileLogger - Failed to write in file.");
}

ImuNetworkLogger::ImuNetworkLogger(ImuDataFormat dataFormat, const QString& address, uint16_t port) :
  ImuLogger(dataFormat),
  m_address(address),
  m_port(port)
{
}

void ImuNetworkLogger::log(const Iml::InertialData& data)
{
  QByteArray byteArray;
  byteArray.append(getFormattedData(data).toUtf8());
  if (m_socket.writeDatagram(byteArray, m_address, m_port) == -1)
    throw std::runtime_error(m_socket.errorString().toStdString().c_str());
}
