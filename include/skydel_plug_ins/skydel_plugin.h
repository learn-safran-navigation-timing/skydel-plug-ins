#pragma once

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

#include "custom_signal/skydel_custom_signal_factory_interface.h"
#include "internal/skydel_command_handler_interface.h"
#include "internal/skydel_rapi_interface.h"
#include "skydel_core_interface.h"
#include "skydel_hil_observer_interface.h"
#include "skydel_position_observer_interface.h"
#include "skydel_radio_time_observer_interface.h"
#include "skydel_raw_data_observer_interface.h"
#include "skydel_simulator_state_observer_interface.h"
#include "skydel_transmitter_observer_interface.h"

template<typename T>
class SkydelPlugin : public SkydelPluginBase
{
public:
  explicit SkydelPlugin()
  {
    skydelPluginRole<SkydelCoreInterface>();
    skydelPluginRole<SkydelPositionObserverInterface>();
    skydelPluginRole<SkydelRadioTimeObserverInterface>();
    skydelPluginRole<SkydelRapiInterface>();
    skydelPluginRole<SkydelRawDataObserverInterface>();
    skydelPluginRole<SkydelTransmitterObserverInterface>();
    skydelPluginRole<SkydelHilObserverInterface>();
    skydelPluginRole<SkydelCommandHandlerInterface>();
    skydelPluginRole<SkydelSimulatorStateObserverInterface>();
    skydelPluginRole<SkydelCustomSignalFactoryInterface>();
  }

  QObject* createInstance() override { return new T {}; }
  std::vector<Interface> implementedInterfaces() override { return m_implementedInterfaces; }

protected:
  template<typename Interface>
  void skydelPluginRole()
  {
    if constexpr (std::is_base_of_v<Interface, T>)
    {
      m_implementedInterfaces.push_back(
        {Interface::ID, Interface::VERSION, [](QObject* base) -> void* { return dynamic_cast<Interface*>(base); }});
    }
  }

private:
  std::vector<Interface> m_implementedInterfaces;
};

#define REGISTER_SKYDEL_PLUGIN(PLUGIN)                                    \
  class SkydelPluginFactory : public QObject, public SkydelPlugin<PLUGIN> \
  {                                                                       \
    Q_OBJECT                                                              \
    Q_PLUGIN_METADATA(IID PLUGIN_IID FILE PLUGIN_FILE)                    \
    Q_INTERFACES(SkydelPluginBase)                                        \
  };
