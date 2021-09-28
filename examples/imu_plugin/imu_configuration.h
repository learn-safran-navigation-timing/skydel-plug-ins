#ifndef IMU_CONFIGURATION_H
#define IMU_CONFIGURATION_H

#include <QJsonObject>

#include "skydel_plug_ins/skydel_notifier_interface.h"

class ImuConfiguration
{
public:
  ImuConfiguration();

  QJsonObject getConfiguration() const { return m_configuration; }
  void setConfiguration(SkydelNotifierInterface* notifier, const QJsonObject& configuration);

  QJsonValue getValue(const QString& key) const;
  void setValue(SkydelNotifierInterface* notifier, const QString& key, const QJsonValue& value);

private:
  QJsonObject m_configuration;
};

#endif // IMU_CONFIGURATION_H
