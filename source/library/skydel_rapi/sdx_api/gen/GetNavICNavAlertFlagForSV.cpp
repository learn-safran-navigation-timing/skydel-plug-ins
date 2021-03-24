#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICNavAlertFlagForSV
///
#include "gen/GetNavICNavAlertFlagForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICNavAlertFlagForSV::CmdName = "GetNavICNavAlertFlagForSV";
    const char* const GetNavICNavAlertFlagForSV::Documentation = "Please note the command GetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use GetNavICNavAlertFlagForSV.\n\nGet NavIC NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetNavICNavAlertFlagForSV);


    GetNavICNavAlertFlagForSV::GetNavICNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    GetNavICNavAlertFlagForSV::GetNavICNavAlertFlagForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetNavICNavAlertFlagForSVPtr GetNavICNavAlertFlagForSV::create(int svId)
    {
      return GetNavICNavAlertFlagForSVPtr(new GetNavICNavAlertFlagForSV(svId));
    }

    GetNavICNavAlertFlagForSVPtr GetNavICNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICNavAlertFlagForSV>(ptr);
    }

    bool GetNavICNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetNavICNavAlertFlagForSV::documentation() const { return Documentation; }


    int GetNavICNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
