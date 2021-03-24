#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssNavAlertFlagForSVResult
///
#include "gen/GetQzssNavAlertFlagForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssNavAlertFlagForSVResult::CmdName = "GetQzssNavAlertFlagForSVResult";
    const char* const GetQzssNavAlertFlagForSVResult::Documentation = "Result of GetQzssNavAlertFlagForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssNavAlertFlagForSVResult);


    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setAlert(alert);
    }


    GetQzssNavAlertFlagForSVResultPtr GetQzssNavAlertFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool alert)
    {
      return GetQzssNavAlertFlagForSVResultPtr(new GetQzssNavAlertFlagForSVResult(relatedCommand, svId, alert));
    }

    GetQzssNavAlertFlagForSVResultPtr GetQzssNavAlertFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssNavAlertFlagForSVResult>(ptr);
    }

    bool GetQzssNavAlertFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string GetQzssNavAlertFlagForSVResult::documentation() const { return Documentation; }


    int GetQzssNavAlertFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssNavAlertFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssNavAlertFlagForSVResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetQzssNavAlertFlagForSVResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
