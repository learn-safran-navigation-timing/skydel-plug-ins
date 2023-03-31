#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteSignalHealthResult
///
#include "gen/GetGpsSatelliteSignalHealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteSignalHealthResult::CmdName = "GetGpsSatelliteSignalHealthResult";
    const char* const GetGpsSatelliteSignalHealthResult::Documentation = "Result of GetGpsSatelliteSignalHealth.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteSignalHealthResult);


    GetGpsSatelliteSignalHealthResult::GetGpsSatelliteSignalHealthResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteSignalHealthResult::GetGpsSatelliteSignalHealthResult(CommandBasePtr relatedCommand, int prn, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGpsSatelliteSignalHealthResultPtr GetGpsSatelliteSignalHealthResult::create(CommandBasePtr relatedCommand, int prn, int health)
    {
      return GetGpsSatelliteSignalHealthResultPtr(new GetGpsSatelliteSignalHealthResult(relatedCommand, prn, health));
    }

    GetGpsSatelliteSignalHealthResultPtr GetGpsSatelliteSignalHealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteSignalHealthResult>(ptr);
    }

    bool GetGpsSatelliteSignalHealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsSatelliteSignalHealthResult::documentation() const { return Documentation; }


    int GetGpsSatelliteSignalHealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteSignalHealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsSatelliteSignalHealthResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGpsSatelliteSignalHealthResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
