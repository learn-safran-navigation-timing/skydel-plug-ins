#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL2HealthResult
///
#include "gen/GetGpsSatelliteL2HealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL2HealthResult::CmdName = "GetGpsSatelliteL2HealthResult";
    const char* const GetGpsSatelliteL2HealthResult::Documentation = "Result of GetGpsSatelliteL2Health.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteL2HealthResult);


    GetGpsSatelliteL2HealthResult::GetGpsSatelliteL2HealthResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteL2HealthResult::GetGpsSatelliteL2HealthResult(CommandBasePtr relatedCommand, int prn, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGpsSatelliteL2HealthResultPtr GetGpsSatelliteL2HealthResult::create(CommandBasePtr relatedCommand, int prn, bool health)
    {
      return GetGpsSatelliteL2HealthResultPtr(new GetGpsSatelliteL2HealthResult(relatedCommand, prn, health));
    }

    GetGpsSatelliteL2HealthResultPtr GetGpsSatelliteL2HealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL2HealthResult>(ptr);
    }

    bool GetGpsSatelliteL2HealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsSatelliteL2HealthResult::documentation() const { return Documentation; }


    int GetGpsSatelliteL2HealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL2HealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsSatelliteL2HealthResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsSatelliteL2HealthResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
