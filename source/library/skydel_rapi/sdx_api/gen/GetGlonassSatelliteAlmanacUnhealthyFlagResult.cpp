#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassSatelliteAlmanacUnhealthyFlagResult
///
#include "gen/GetGlonassSatelliteAlmanacUnhealthyFlagResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassSatelliteAlmanacUnhealthyFlagResult::CmdName = "GetGlonassSatelliteAlmanacUnhealthyFlagResult";
    const char* const GetGlonassSatelliteAlmanacUnhealthyFlagResult::Documentation = "Result of GetGlonassSatelliteAlmanacUnhealthyFlag.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGlonassSatelliteAlmanacUnhealthyFlagResult);


    GetGlonassSatelliteAlmanacUnhealthyFlagResult::GetGlonassSatelliteAlmanacUnhealthyFlagResult()
      : CommandResult(CmdName)
    {}

    GetGlonassSatelliteAlmanacUnhealthyFlagResult::GetGlonassSatelliteAlmanacUnhealthyFlagResult(CommandBasePtr relatedCommand, int prn, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGlonassSatelliteAlmanacUnhealthyFlagResultPtr GetGlonassSatelliteAlmanacUnhealthyFlagResult::create(CommandBasePtr relatedCommand, int prn, bool health)
    {
      return GetGlonassSatelliteAlmanacUnhealthyFlagResultPtr(new GetGlonassSatelliteAlmanacUnhealthyFlagResult(relatedCommand, prn, health));
    }

    GetGlonassSatelliteAlmanacUnhealthyFlagResultPtr GetGlonassSatelliteAlmanacUnhealthyFlagResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassSatelliteAlmanacUnhealthyFlagResult>(ptr);
    }

    bool GetGlonassSatelliteAlmanacUnhealthyFlagResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGlonassSatelliteAlmanacUnhealthyFlagResult::documentation() const { return Documentation; }


    int GetGlonassSatelliteAlmanacUnhealthyFlagResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassSatelliteAlmanacUnhealthyFlagResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGlonassSatelliteAlmanacUnhealthyFlagResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGlonassSatelliteAlmanacUnhealthyFlagResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
