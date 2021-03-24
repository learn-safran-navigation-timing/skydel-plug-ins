#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavAlertFlagForSV
///
#include "gen/GetGpsNavAlertFlagForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavAlertFlagForSV::CmdName = "GetGpsNavAlertFlagForSV";
    const char* const GetGpsNavAlertFlagForSV::Documentation = "Get GPS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetGpsNavAlertFlagForSV);


    GetGpsNavAlertFlagForSV::GetGpsNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    GetGpsNavAlertFlagForSV::GetGpsNavAlertFlagForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsNavAlertFlagForSVPtr GetGpsNavAlertFlagForSV::create(int svId)
    {
      return GetGpsNavAlertFlagForSVPtr(new GetGpsNavAlertFlagForSV(svId));
    }

    GetGpsNavAlertFlagForSVPtr GetGpsNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavAlertFlagForSV>(ptr);
    }

    bool GetGpsNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsNavAlertFlagForSV::documentation() const { return Documentation; }


    int GetGpsNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
