#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteNavAlertFlagResult
///
#include "gen/GetGpsSatelliteNavAlertFlagResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteNavAlertFlagResult::CmdName = "GetGpsSatelliteNavAlertFlagResult";
    const char* const GetGpsSatelliteNavAlertFlagResult::Documentation = "Result of GetGpsSatelliteNavAlertFlag.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteNavAlertFlagResult);


    GetGpsSatelliteNavAlertFlagResult::GetGpsSatelliteNavAlertFlagResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteNavAlertFlagResult::GetGpsSatelliteNavAlertFlagResult(CommandBasePtr relatedCommand, int prn, bool alert)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setAlert(alert);
    }


    GetGpsSatelliteNavAlertFlagResultPtr GetGpsSatelliteNavAlertFlagResult::create(CommandBasePtr relatedCommand, int prn, bool alert)
    {
      return GetGpsSatelliteNavAlertFlagResultPtr(new GetGpsSatelliteNavAlertFlagResult(relatedCommand, prn, alert));
    }

    GetGpsSatelliteNavAlertFlagResultPtr GetGpsSatelliteNavAlertFlagResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteNavAlertFlagResult>(ptr);
    }

    bool GetGpsSatelliteNavAlertFlagResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Alert"])
        ;

    }

    std::string GetGpsSatelliteNavAlertFlagResult::documentation() const { return Documentation; }


    int GetGpsSatelliteNavAlertFlagResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteNavAlertFlagResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsSatelliteNavAlertFlagResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetGpsSatelliteNavAlertFlagResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
