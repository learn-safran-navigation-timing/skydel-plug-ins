#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteCNavAlertFlag
///
#include "gen/SetGpsSatelliteCNavAlertFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteCNavAlertFlag::CmdName = "SetGpsSatelliteCNavAlertFlag";
    const char* const SetGpsSatelliteCNavAlertFlag::Documentation = "Please note the command SetGpsSatelliteCNavAlertFlag is deprecated since 21.3. You may use SetGpsCNavAlertFlagToSV.\n\nSet GPS CNAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteCNavAlertFlag);


    SetGpsSatelliteCNavAlertFlag::SetGpsSatelliteCNavAlertFlag()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteCNavAlertFlag::SetGpsSatelliteCNavAlertFlag(int prn, bool alert)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setAlert(alert);
    }


    SetGpsSatelliteCNavAlertFlagPtr SetGpsSatelliteCNavAlertFlag::create(int prn, bool alert)
    {
      return SetGpsSatelliteCNavAlertFlagPtr(new SetGpsSatelliteCNavAlertFlag(prn, alert));
    }

    SetGpsSatelliteCNavAlertFlagPtr SetGpsSatelliteCNavAlertFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteCNavAlertFlag>(ptr);
    }

    bool SetGpsSatelliteCNavAlertFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string SetGpsSatelliteCNavAlertFlag::documentation() const { return Documentation; }


    int SetGpsSatelliteCNavAlertFlag::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteCNavAlertFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteCNavAlertFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsSatelliteCNavAlertFlag::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetGpsSatelliteCNavAlertFlag::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
