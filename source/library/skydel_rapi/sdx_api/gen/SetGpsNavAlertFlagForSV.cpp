#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsNavAlertFlagForSV
///
#include "gen/SetGpsNavAlertFlagForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsNavAlertFlagForSV::CmdName = "SetGpsNavAlertFlagForSV";
    const char* const SetGpsNavAlertFlagForSV::Documentation = "Set GPS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetGpsNavAlertFlagForSV);


    SetGpsNavAlertFlagForSV::SetGpsNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    SetGpsNavAlertFlagForSV::SetGpsNavAlertFlagForSV(int svId, bool alert)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
    }


    SetGpsNavAlertFlagForSVPtr SetGpsNavAlertFlagForSV::create(int svId, bool alert)
    {
      return SetGpsNavAlertFlagForSVPtr(new SetGpsNavAlertFlagForSV(svId, alert));
    }

    SetGpsNavAlertFlagForSVPtr SetGpsNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsNavAlertFlagForSV>(ptr);
    }

    bool SetGpsNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string SetGpsNavAlertFlagForSV::documentation() const { return Documentation; }


    int SetGpsNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsNavAlertFlagForSV::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetGpsNavAlertFlagForSV::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
