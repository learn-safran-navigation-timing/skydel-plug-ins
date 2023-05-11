#ifndef SKYDEL_PLUGIN_H
#define SKYDEL_PLUGIN_H

#include <QObject>
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
    void* (*convertFunction)(QObject*);
  };

  virtual QObject* createInstance() = 0;
  virtual std::vector<Interface> implementedInterfaces() = 0;
};

Q_DECLARE_INTERFACE(SkydelPluginBase, "SkydelPluginBase/1.0")

#include "internal/skydel_command_handler_interface.h"
#include "internal/skydel_rapi_interface.h"
#include "skydel_core_interface.h"
#include "skydel_hil_observer_interface.h"
#include "skydel_licensing_interface.h"
#include "skydel_position_observer_interface.h"
#include "skydel_radio_time_observer_interface.h"
#include "skydel_raw_data_observer_interface.h"
#include "skydel_transmitter_observer_interface.h"

#define SKYDEL_PLUGIN_ROLE(interface)            \
  if constexpr (std::is_base_of_v<interface, T>) \
    m_implementedInterfaces.push_back(           \
      {interface::ID, interface::VERSION, [](QObject* base) -> void* { return dynamic_cast<interface*>(base); }});

template<typename T>
class SkydelPlugin : public SkydelPluginBase
{
public:
  explicit SkydelPlugin()
  {
    SKYDEL_PLUGIN_ROLE(SkydelCoreInterface);
    SKYDEL_PLUGIN_ROLE(SkydelPositionObserverInterface);
    SKYDEL_PLUGIN_ROLE(SkydelRadioTimeObserverInterface);
    SKYDEL_PLUGIN_ROLE(SkydelLicensingInterface);
    SKYDEL_PLUGIN_ROLE(SkydelRapiInterface);
    SKYDEL_PLUGIN_ROLE(SkydelRawDataObserverInterface);
    SKYDEL_PLUGIN_ROLE(SkydelTransmitterObserverInterface);
    SKYDEL_PLUGIN_ROLE(SkydelHilObserverInterface);
    SKYDEL_PLUGIN_ROLE(SkydelCommandHandlerInterface);
  }

  QObject* createInstance() override { return new T {}; }
  std::vector<Interface> implementedInterfaces() override { return m_implementedInterfaces; }

private:
  std::vector<Interface> m_implementedInterfaces;
};

#endif // SKYDEL_PLUGIN_H
