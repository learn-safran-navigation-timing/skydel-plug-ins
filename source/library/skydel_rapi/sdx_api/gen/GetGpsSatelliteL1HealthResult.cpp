#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL1HealthResult
///
#include "gen/GetGpsSatelliteL1HealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL1HealthResult::CmdName = "GetGpsSatelliteL1HealthResult";
    const char* const GetGpsSatelliteL1HealthResult::Documentation = "Result of GetGpsSatelliteL1Health.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteL1HealthResult);


    GetGpsSatelliteL1HealthResult::GetGpsSatelliteL1HealthResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteL1HealthResult::GetGpsSatelliteL1HealthResult(CommandBasePtr relatedCommand, int prn, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGpsSatelliteL1HealthResultPtr GetGpsSatelliteL1HealthResult::create(CommandBasePtr relatedCommand, int prn, bool health)
    {
      return GetGpsSatelliteL1HealthResultPtr(new GetGpsSatelliteL1HealthResult(relatedCommand, prn, health));
    }

    GetGpsSatelliteL1HealthResultPtr GetGpsSatelliteL1HealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL1HealthResult>(ptr);
    }

    bool GetGpsSatelliteL1HealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsSatelliteL1HealthResult::documentation() const { return Documentation; }


    int GetGpsSatelliteL1HealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL1HealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsSatelliteL1HealthResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsSatelliteL1HealthResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
