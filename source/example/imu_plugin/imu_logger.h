#ifndef IMU_LOGGER_H
#define IMU_LOGGER_H

#include <QFile>
#include <QString>
#include <QUdpSocket>

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

#include "dynamic.h"
#include "imu_data_format.h"

class ImuLogger
{
public:
  explicit ImuLogger(ImuDataFormat dataFormat);
  virtual ~ImuLogger() = default;
  virtual void log(const Iml::InertialData& data) = 0;

protected:
  QString getHeader();
  QString getFormattedData(const Iml::InertialData& data);

private:
  QString getFormattedDataInCsvFormat(const Iml::InertialData& data);
  QString getFormattedDataInJsonFormat(const Iml::InertialData& data);

  static const QString csvHeader;
  static const QString jsonHeader;

  ImuDataFormat m_dataFormat;
};

typedef std::shared_ptr<ImuLogger> ImuLoggerPtr;

class ImuFileLogger : public ImuLogger
{
public:
  explicit ImuFileLogger(ImuDataFormat dataFormat, QString logFilePath);
  ~ImuFileLogger() override;

  void log(const Iml::InertialData& data) override;

private:
  void writeInFile(const QString& string);

  QFile m_file;
};

class ImuNetworkLogger : public ImuLogger
{
public:
  explicit ImuNetworkLogger(ImuDataFormat dataFormat, const QString& address, uint16_t port);

  void log(const Iml::InertialData& data) override;

private:
  QHostAddress m_address;
  uint16_t m_port;
  QUdpSocket m_socket;
};

#endif // IMU_LOGGER_H
