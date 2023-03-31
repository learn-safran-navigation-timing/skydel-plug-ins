#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteNavAlertFlag
///
#include "gen/SetGpsSatelliteNavAlertFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteNavAlertFlag::CmdName = "SetGpsSatelliteNavAlertFlag";
    const char* const SetGpsSatelliteNavAlertFlag::Documentation = "Please note the command SetGpsSatelliteNavAlertFlag is deprecated since 21.3. You may use SetGpsNavAlertFlagForSV.\n\nSet GPS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteNavAlertFlag);


    SetGpsSatelliteNavAlertFlag::SetGpsSatelliteNavAlertFlag()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteNavAlertFlag::SetGpsSatelliteNavAlertFlag(int prn, bool alert)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setAlert(alert);
    }


    SetGpsSatelliteNavAlertFlagPtr SetGpsSatelliteNavAlertFlag::create(int prn, bool alert)
    {
      return SetGpsSatelliteNavAlertFlagPtr(new SetGpsSatelliteNavAlertFlag(prn, alert));
    }

    SetGpsSatelliteNavAlertFlagPtr SetGpsSatelliteNavAlertFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteNavAlertFlag>(ptr);
    }

    bool SetGpsSatelliteNavAlertFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string SetGpsSatelliteNavAlertFlag::documentation() const { return Documentation; }


    int SetGpsSatelliteNavAlertFlag::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteNavAlertFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteNavAlertFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsSatelliteNavAlertFlag::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetGpsSatelliteNavAlertFlag::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
