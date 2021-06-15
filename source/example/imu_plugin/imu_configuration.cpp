#include "imu_configuration.h"

#include <QHostAddress>

#include <stdexcept>

#include "gravity.h"
#include "imu_data_format.h"

ImuConfiguration::ImuConfiguration()
{
  m_configuration.insert("fileLoggingEnabled", true);
  m_configuration.insert("fileLoggingFormat", ImuDataFormat::CSV);

  m_configuration.insert("networkLoggingEnabled", false);
  m_configuration.insert("networkLoggingFormat", ImuDataFormat::JSON);
  m_configuration.insert("networkLoggingAddress", QHostAddress(QHostAddress::LocalHost).toString());
  m_configuration.insert("networkLoggingPort", 161);

  m_configuration.insert("gravityModel", Iml::GravityModel::WGS84);
}

void ImuConfiguration::setConfiguration(SkydelNotifierInterface* notifier, const QJsonObject& configuration)
{
  for (auto key : m_configuration.keys())
  {
    if (!configuration.contains(key))
    {
      notifier->notify("During configuration transfer from Skydel to plug-in, the key " + key.toStdString() +
                         " is expected by missing",
                       SkydelNotifierInterface::Type::WARNING);
      continue;
    }

    if (m_configuration.value(key).type() != configuration.value(key).type())
    {
      notifier->notify(
        "During configuration transfer from Skydel to plug-in, the expected type for configuration key " +
          key.toStdString() + " mismatch the expected type",
        SkydelNotifierInterface::Type::WARNING);
      continue;
    }

    m_configuration.insert(key, configuration.value(key));
  }
}

QJsonValue ImuConfiguration::getValue(const QString& key) const
{
  auto value = m_configuration.value(key);

  if (value.type() == QJsonValue::Undefined)
    throw std::runtime_error("ImuConfiguration::getValue - Key " + key.toStdString() + " does not exist");

  return value;
}

void ImuConfiguration::setValue(SkydelNotifierInterface* notifier, const QString& key, const QJsonValue& value)
{
  if (!m_configuration.contains(key))
    throw std::runtime_error("ImuConfiguration::setValue - Key " + key.toStdString() + " does not exist");

  m_configuration.insert(key, value);
  notifier->setDirty();
}
