#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL5HealthResult
///
#include "gen/GetGpsSatelliteL5HealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL5HealthResult::CmdName = "GetGpsSatelliteL5HealthResult";
    const char* const GetGpsSatelliteL5HealthResult::Documentation = "Result of GetGpsSatelliteL5Health.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteL5HealthResult);


    GetGpsSatelliteL5HealthResult::GetGpsSatelliteL5HealthResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteL5HealthResult::GetGpsSatelliteL5HealthResult(CommandBasePtr relatedCommand, int prn, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGpsSatelliteL5HealthResultPtr GetGpsSatelliteL5HealthResult::create(CommandBasePtr relatedCommand, int prn, bool health)
    {
      return GetGpsSatelliteL5HealthResultPtr(new GetGpsSatelliteL5HealthResult(relatedCommand, prn, health));
    }

    GetGpsSatelliteL5HealthResultPtr GetGpsSatelliteL5HealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL5HealthResult>(ptr);
    }

    bool GetGpsSatelliteL5HealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsSatelliteL5HealthResult::documentation() const { return Documentation; }


    int GetGpsSatelliteL5HealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL5HealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsSatelliteL5HealthResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsSatelliteL5HealthResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
