#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL1cHealthResult
///
#include "gen/GetGpsSatelliteL1cHealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL1cHealthResult::CmdName = "GetGpsSatelliteL1cHealthResult";
    const char* const GetGpsSatelliteL1cHealthResult::Documentation = "Result of GetGpsSatelliteL1cHealth.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteL1cHealthResult);


    GetGpsSatelliteL1cHealthResult::GetGpsSatelliteL1cHealthResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteL1cHealthResult::GetGpsSatelliteL1cHealthResult(CommandBasePtr relatedCommand, int prn, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGpsSatelliteL1cHealthResultPtr GetGpsSatelliteL1cHealthResult::create(CommandBasePtr relatedCommand, int prn, bool health)
    {
      return GetGpsSatelliteL1cHealthResultPtr(new GetGpsSatelliteL1cHealthResult(relatedCommand, prn, health));
    }

    GetGpsSatelliteL1cHealthResultPtr GetGpsSatelliteL1cHealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL1cHealthResult>(ptr);
    }

    bool GetGpsSatelliteL1cHealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsSatelliteL1cHealthResult::documentation() const { return Documentation; }


    int GetGpsSatelliteL1cHealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL1cHealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsSatelliteL1cHealthResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsSatelliteL1cHealthResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
