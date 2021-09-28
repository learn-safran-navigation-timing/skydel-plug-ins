#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassSatelliteEphemerisHealthFlagResult
///
#include "gen/GetGlonassSatelliteEphemerisHealthFlagResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassSatelliteEphemerisHealthFlagResult::CmdName = "GetGlonassSatelliteEphemerisHealthFlagResult";
    const char* const GetGlonassSatelliteEphemerisHealthFlagResult::Documentation = "Result of GetGlonassSatelliteEphemerisHealthFlag.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGlonassSatelliteEphemerisHealthFlagResult);


    GetGlonassSatelliteEphemerisHealthFlagResult::GetGlonassSatelliteEphemerisHealthFlagResult()
      : CommandResult(CmdName)
    {}

    GetGlonassSatelliteEphemerisHealthFlagResult::GetGlonassSatelliteEphemerisHealthFlagResult(CommandBasePtr relatedCommand, int prn, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetGlonassSatelliteEphemerisHealthFlagResultPtr GetGlonassSatelliteEphemerisHealthFlagResult::create(CommandBasePtr relatedCommand, int prn, bool health)
    {
      return GetGlonassSatelliteEphemerisHealthFlagResultPtr(new GetGlonassSatelliteEphemerisHealthFlagResult(relatedCommand, prn, health));
    }

    GetGlonassSatelliteEphemerisHealthFlagResultPtr GetGlonassSatelliteEphemerisHealthFlagResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassSatelliteEphemerisHealthFlagResult>(ptr);
    }

    bool GetGlonassSatelliteEphemerisHealthFlagResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGlonassSatelliteEphemerisHealthFlagResult::documentation() const { return Documentation; }


    int GetGlonassSatelliteEphemerisHealthFlagResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassSatelliteEphemerisHealthFlagResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGlonassSatelliteEphemerisHealthFlagResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGlonassSatelliteEphemerisHealthFlagResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
