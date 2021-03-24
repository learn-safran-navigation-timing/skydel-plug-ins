#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavAlertFlagForSVResult
///
#include "gen/GetGpsNavAlertFlagForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavAlertFlagForSVResult::CmdName = "GetGpsNavAlertFlagForSVResult";
    const char* const GetGpsNavAlertFlagForSVResult::Documentation = "Result of GetGpsNavAlertFlagForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsNavAlertFlagForSVResult);


    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setAlert(alert);
    }


    GetGpsNavAlertFlagForSVResultPtr GetGpsNavAlertFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool alert)
    {
      return GetGpsNavAlertFlagForSVResultPtr(new GetGpsNavAlertFlagForSVResult(relatedCommand, svId, alert));
    }

    GetGpsNavAlertFlagForSVResultPtr GetGpsNavAlertFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavAlertFlagForSVResult>(ptr);
    }

    bool GetGpsNavAlertFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string GetGpsNavAlertFlagForSVResult::documentation() const { return Documentation; }


    int GetGpsNavAlertFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsNavAlertFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsNavAlertFlagForSVResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetGpsNavAlertFlagForSVResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
