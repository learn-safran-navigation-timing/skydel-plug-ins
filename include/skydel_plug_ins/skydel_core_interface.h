#pragma once

#include <QJsonObject>
#include <QString>
#include <QWidget>

#include <cstdint>

#include "skydel_notifier_interface.h"

const QString SKYDEL_WIDGET_SETTINGS_KEY = "Settings";
const QString SKYDEL_WIDGET_DOCK_KEY = "Dock";
const QString SKYDEL_WIDGET_PLUGINS_KEY = "Plug-ins";
const QString SKYDEL_WIDGET_DEFAULT_PATH = "/" + SKYDEL_WIDGET_SETTINGS_KEY + "/" + SKYDEL_WIDGET_PLUGINS_KEY;

struct SkydelWidget
{
  QWidget* widget {nullptr};
  QString path {SKYDEL_WIDGET_DEFAULT_PATH};
  QString name {};
};

struct SkydelWidgets
{
  SkydelWidgets() {}
  SkydelWidgets(QWidget* widget) : widgets({{widget}}) {}
  SkydelWidgets(SkydelWidget widget) : widgets({widget}) {}
  SkydelWidgets(std::vector<SkydelWidget> widgets_) : widgets(widgets_) {}

  std::vector<SkydelWidget> widgets;
};

class SkydelCoreInterface
{
public:
  virtual ~SkydelCoreInterface() = default;

  virtual void setLogPath(const QString& path) = 0;
  virtual void setInstanceIdentifier(uint32_t identifier) = 0;
  virtual void setNotifier(SkydelNotifierInterface* notifier) = 0;
  virtual void setConfiguration(const QString& version, const QJsonObject& configuration) = 0;
  virtual QJsonObject getConfiguration() const = 0;
  virtual SkydelWidgets createUI() = 0;
  virtual void initialize() = 0;

  static constexpr auto ID = "SkydelCore";
  static constexpr auto VERSION = 5;
};
