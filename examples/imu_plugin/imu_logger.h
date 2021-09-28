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
  QString getHeader() const;
  QString getFormattedData(const Iml::InertialData& data) const;

  ImuDataFormat m_dataFormat;

private:
  QString getFormattedDataInCsvFormat(const Iml::InertialData& data) const;
  QString getFormattedDataInJsonFormat(const Iml::InertialData& data) const;

  static const QString csvHeader;
  static const QString jsonHeader;
};

typedef std::shared_ptr<ImuLogger> ImuLoggerPtr;

class ImuFileLogger : public ImuLogger
{
public:
  explicit ImuFileLogger(ImuDataFormat dataFormat, QString logFilePath);
  ~ImuFileLogger() override;

  void log(const Iml::InertialData& data) override;

private:
  QString getFileExtension() const;
  void writeInFile(const QString& string);

  static const QString csvFileExtension;
  static const QString jsonFileExtension;

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
