#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsCNavAlertFlagToSV
///
#include "gen/SetGpsCNavAlertFlagToSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsCNavAlertFlagToSV::CmdName = "SetGpsCNavAlertFlagToSV";
    const char* const SetGpsCNavAlertFlagToSV::Documentation = "Set GPS CNAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetGpsCNavAlertFlagToSV);


    SetGpsCNavAlertFlagToSV::SetGpsCNavAlertFlagToSV()
      : CommandBase(CmdName)
    {}

    SetGpsCNavAlertFlagToSV::SetGpsCNavAlertFlagToSV(int svId, bool alert)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
    }


    SetGpsCNavAlertFlagToSVPtr SetGpsCNavAlertFlagToSV::create(int svId, bool alert)
    {
      return SetGpsCNavAlertFlagToSVPtr(new SetGpsCNavAlertFlagToSV(svId, alert));
    }

    SetGpsCNavAlertFlagToSVPtr SetGpsCNavAlertFlagToSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsCNavAlertFlagToSV>(ptr);
    }

    bool SetGpsCNavAlertFlagToSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string SetGpsCNavAlertFlagToSV::documentation() const { return Documentation; }


    int SetGpsCNavAlertFlagToSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsCNavAlertFlagToSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsCNavAlertFlagToSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsCNavAlertFlagToSV::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetGpsCNavAlertFlagToSV::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
