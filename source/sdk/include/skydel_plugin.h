#ifndef SKYDEL_PLUGIN_H
#define SKYDEL_PLUGIN_H

#include <QString>

#include <vector>

class SkydelPluginBase
{
public:
  virtual ~SkydelPluginBase() = default;

  struct Interface
  {
    QString id;
    int version;
    void *(*convertFunction)(QObject *);
  };

  virtual QObject* createInstance() = 0;
  virtual std::vector<Interface> implementedInterfaces() = 0;
};

Q_DECLARE_INTERFACE(SkydelPluginBase, "SkydelPluginBase/1.0")

#include "skydel_core_interface.h"
#include "skydel_licensing_interface.h"
#include "skydel_position_observer_interface.h"

#define SKYDEL_PLUGIN_ROLE(interface) if constexpr (std::is_base_of_v<interface, T>) m_implementedInterfaces.push_back({ interface::ID, interface::VERSION, [](QObject* base) -> void* { return dynamic_cast<interface*>(base); }});

template<typename T>
class SkydelPlugin : public SkydelPluginBase
{
public:
  explicit SkydelPlugin()
  {
    SKYDEL_PLUGIN_ROLE(SkydelCoreInterface);
    SKYDEL_PLUGIN_ROLE(SkydelPositionObserverInterface);
    SKYDEL_PLUGIN_ROLE(SkydelLicensingInterface);
  }

  QObject* createInstance() override { return new T{}; }
  virtual std::vector<Interface> implementedInterfaces() { return m_implementedInterfaces; }

private:
  std::vector<Interface> m_implementedInterfaces;
};

#endif // SKYDEL_PLUGIN_H
