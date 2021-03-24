#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssNavAlertFlagForSV
///
#include "gen/GetQzssNavAlertFlagForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssNavAlertFlagForSV::CmdName = "GetQzssNavAlertFlagForSV";
    const char* const GetQzssNavAlertFlagForSV::Documentation = "Please note the command GetQzssSatelliteNavAlertFlag is deprecated since 21.3. You may use GetQzssNavAlertFlagForSV.\n\nGet QZSS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetQzssNavAlertFlagForSV);


    GetQzssNavAlertFlagForSV::GetQzssNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    GetQzssNavAlertFlagForSV::GetQzssNavAlertFlagForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssNavAlertFlagForSVPtr GetQzssNavAlertFlagForSV::create(int svId)
    {
      return GetQzssNavAlertFlagForSVPtr(new GetQzssNavAlertFlagForSV(svId));
    }

    GetQzssNavAlertFlagForSVPtr GetQzssNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssNavAlertFlagForSV>(ptr);
    }

    bool GetQzssNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssNavAlertFlagForSV::documentation() const { return Documentation; }


    int GetQzssNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
