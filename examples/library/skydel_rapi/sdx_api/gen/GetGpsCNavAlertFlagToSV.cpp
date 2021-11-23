#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavAlertFlagToSV
///
#include "gen/GetGpsCNavAlertFlagToSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavAlertFlagToSV::CmdName = "GetGpsCNavAlertFlagToSV";
    const char* const GetGpsCNavAlertFlagToSV::Documentation = "Get GPS CNAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetGpsCNavAlertFlagToSV);


    GetGpsCNavAlertFlagToSV::GetGpsCNavAlertFlagToSV()
      : CommandBase(CmdName)
    {}

    GetGpsCNavAlertFlagToSV::GetGpsCNavAlertFlagToSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsCNavAlertFlagToSVPtr GetGpsCNavAlertFlagToSV::create(int svId)
    {
      return GetGpsCNavAlertFlagToSVPtr(new GetGpsCNavAlertFlagToSV(svId));
    }

    GetGpsCNavAlertFlagToSVPtr GetGpsCNavAlertFlagToSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNavAlertFlagToSV>(ptr);
    }

    bool GetGpsCNavAlertFlagToSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsCNavAlertFlagToSV::documentation() const { return Documentation; }


    int GetGpsCNavAlertFlagToSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsCNavAlertFlagToSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsCNavAlertFlagToSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
