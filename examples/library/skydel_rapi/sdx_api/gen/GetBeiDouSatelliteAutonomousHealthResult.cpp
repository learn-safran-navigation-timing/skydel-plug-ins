#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouSatelliteAutonomousHealthResult
///
#include "gen/GetBeiDouSatelliteAutonomousHealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouSatelliteAutonomousHealthResult::CmdName = "GetBeiDouSatelliteAutonomousHealthResult";
    const char* const GetBeiDouSatelliteAutonomousHealthResult::Documentation = "Result of GetBeiDouSatelliteAutonomousHealth.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouSatelliteAutonomousHealthResult);


    GetBeiDouSatelliteAutonomousHealthResult::GetBeiDouSatelliteAutonomousHealthResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouSatelliteAutonomousHealthResult::GetBeiDouSatelliteAutonomousHealthResult(CommandBasePtr relatedCommand, int prn, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetBeiDouSatelliteAutonomousHealthResultPtr GetBeiDouSatelliteAutonomousHealthResult::create(CommandBasePtr relatedCommand, int prn, bool health)
    {
      return GetBeiDouSatelliteAutonomousHealthResultPtr(new GetBeiDouSatelliteAutonomousHealthResult(relatedCommand, prn, health));
    }

    GetBeiDouSatelliteAutonomousHealthResultPtr GetBeiDouSatelliteAutonomousHealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouSatelliteAutonomousHealthResult>(ptr);
    }

    bool GetBeiDouSatelliteAutonomousHealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouSatelliteAutonomousHealthResult::documentation() const { return Documentation; }


    int GetBeiDouSatelliteAutonomousHealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouSatelliteAutonomousHealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouSatelliteAutonomousHealthResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetBeiDouSatelliteAutonomousHealthResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
