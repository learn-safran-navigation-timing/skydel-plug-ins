#ifndef SKYDEL_CORE_INTERFACE_H
#define SKYDEL_CORE_INTERFACE_H

#include <QJsonObject>
#include <QString>
#include <QWidget>

#include "skydel_notifier_interface.h"

class SkydelCoreInterface
{
public:
  virtual ~SkydelCoreInterface() = default;

  virtual void setLogPath(const QString& path) = 0;
  virtual void setNotifier(SkydelNotifierInterface* notifier) = 0;
  virtual void setConfiguration(const QString& version, const QJsonObject& configuration) = 0;
  virtual QJsonObject getConfiguration() const = 0;
  virtual QWidget* createUI() = 0;
  virtual void initialize() = 0;
  virtual void setInstanceName(const QString&) {};

  static constexpr auto ID = "SkydelCore";
  static constexpr auto VERSION = 3;
};

#endif // SKYDEL_CORE_INTERFACE_H
