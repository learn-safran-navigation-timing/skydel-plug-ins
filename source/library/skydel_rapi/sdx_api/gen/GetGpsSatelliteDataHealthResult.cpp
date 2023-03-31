#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteDataHealthResult
///
#include "gen/GetGpsSatelliteDataHealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteDataHealthResult::CmdName = "GetGpsSatelliteDataHealthResult";
    const char* const GetGpsSatelliteDataHealthResult::Documentation = "Result of GetGpsSatelliteDataHealth.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteDataHealthResult);


    GetGpsSatelliteDataHealthResult::GetGpsSatelliteDataHealthResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteDataHealthResult::GetGpsSatelliteDataHealthResult(CommandBasePtr relatedCommand, int prn, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGpsSatelliteDataHealthResultPtr GetGpsSatelliteDataHealthResult::create(CommandBasePtr relatedCommand, int prn, int health)
    {
      return GetGpsSatelliteDataHealthResultPtr(new GetGpsSatelliteDataHealthResult(relatedCommand, prn, health));
    }

    GetGpsSatelliteDataHealthResultPtr GetGpsSatelliteDataHealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteDataHealthResult>(ptr);
    }

    bool GetGpsSatelliteDataHealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsSatelliteDataHealthResult::documentation() const { return Documentation; }


    int GetGpsSatelliteDataHealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteDataHealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsSatelliteDataHealthResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGpsSatelliteDataHealthResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
