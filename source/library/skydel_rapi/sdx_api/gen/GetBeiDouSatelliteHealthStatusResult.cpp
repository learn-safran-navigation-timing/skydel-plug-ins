#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouSatelliteHealthStatusResult
///
#include "gen/GetBeiDouSatelliteHealthStatusResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouSatelliteHealthStatusResult::CmdName = "GetBeiDouSatelliteHealthStatusResult";
    const char* const GetBeiDouSatelliteHealthStatusResult::Documentation = "Result of GetBeiDouSatelliteHealthStatus.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouSatelliteHealthStatusResult);


    GetBeiDouSatelliteHealthStatusResult::GetBeiDouSatelliteHealthStatusResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouSatelliteHealthStatusResult::GetBeiDouSatelliteHealthStatusResult(CommandBasePtr relatedCommand, int prn, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetBeiDouSatelliteHealthStatusResultPtr GetBeiDouSatelliteHealthStatusResult::create(CommandBasePtr relatedCommand, int prn, int health)
    {
      return GetBeiDouSatelliteHealthStatusResultPtr(new GetBeiDouSatelliteHealthStatusResult(relatedCommand, prn, health));
    }

    GetBeiDouSatelliteHealthStatusResultPtr GetBeiDouSatelliteHealthStatusResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouSatelliteHealthStatusResult>(ptr);
    }

    bool GetBeiDouSatelliteHealthStatusResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouSatelliteHealthStatusResult::documentation() const { return Documentation; }


    int GetBeiDouSatelliteHealthStatusResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouSatelliteHealthStatusResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouSatelliteHealthStatusResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouSatelliteHealthStatusResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
