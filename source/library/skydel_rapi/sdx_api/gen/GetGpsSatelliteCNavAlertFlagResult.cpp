#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteCNavAlertFlagResult
///
#include "gen/GetGpsSatelliteCNavAlertFlagResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteCNavAlertFlagResult::CmdName = "GetGpsSatelliteCNavAlertFlagResult";
    const char* const GetGpsSatelliteCNavAlertFlagResult::Documentation = "Result of GetGpsSatelliteCNavAlertFlag.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteCNavAlertFlagResult);


    GetGpsSatelliteCNavAlertFlagResult::GetGpsSatelliteCNavAlertFlagResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteCNavAlertFlagResult::GetGpsSatelliteCNavAlertFlagResult(CommandBasePtr relatedCommand, int prn, bool alert)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setAlert(alert);
    }


    GetGpsSatelliteCNavAlertFlagResultPtr GetGpsSatelliteCNavAlertFlagResult::create(CommandBasePtr relatedCommand, int prn, bool alert)
    {
      return GetGpsSatelliteCNavAlertFlagResultPtr(new GetGpsSatelliteCNavAlertFlagResult(relatedCommand, prn, alert));
    }

    GetGpsSatelliteCNavAlertFlagResultPtr GetGpsSatelliteCNavAlertFlagResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteCNavAlertFlagResult>(ptr);
    }

    bool GetGpsSatelliteCNavAlertFlagResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string GetGpsSatelliteCNavAlertFlagResult::documentation() const { return Documentation; }


    int GetGpsSatelliteCNavAlertFlagResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteCNavAlertFlagResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsSatelliteCNavAlertFlagResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetGpsSatelliteCNavAlertFlagResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
