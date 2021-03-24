#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssNavAlertFlagForSV
///
#include "gen/SetQzssNavAlertFlagForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssNavAlertFlagForSV::CmdName = "SetQzssNavAlertFlagForSV";
    const char* const SetQzssNavAlertFlagForSV::Documentation = "Please note the command SetQzssSatelliteNavAlertFlag is deprecated since 21.3. You may use SetQzssNavAlertFlagForSV.\n\nSet QZSS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetQzssNavAlertFlagForSV);


    SetQzssNavAlertFlagForSV::SetQzssNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    SetQzssNavAlertFlagForSV::SetQzssNavAlertFlagForSV(int svId, bool alert)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
    }


    SetQzssNavAlertFlagForSVPtr SetQzssNavAlertFlagForSV::create(int svId, bool alert)
    {
      return SetQzssNavAlertFlagForSVPtr(new SetQzssNavAlertFlagForSV(svId, alert));
    }

    SetQzssNavAlertFlagForSVPtr SetQzssNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssNavAlertFlagForSV>(ptr);
    }

    bool SetQzssNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string SetQzssNavAlertFlagForSV::documentation() const { return Documentation; }


    int SetQzssNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssNavAlertFlagForSV::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetQzssNavAlertFlagForSV::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
