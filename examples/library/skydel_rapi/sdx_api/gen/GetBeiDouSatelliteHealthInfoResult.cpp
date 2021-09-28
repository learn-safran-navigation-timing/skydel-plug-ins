#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouSatelliteHealthInfoResult
///
#include "gen/GetBeiDouSatelliteHealthInfoResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouSatelliteHealthInfoResult::CmdName = "GetBeiDouSatelliteHealthInfoResult";
    const char* const GetBeiDouSatelliteHealthInfoResult::Documentation = "Result of GetBeiDouSatelliteHealthInfo.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouSatelliteHealthInfoResult);


    GetBeiDouSatelliteHealthInfoResult::GetBeiDouSatelliteHealthInfoResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouSatelliteHealthInfoResult::GetBeiDouSatelliteHealthInfoResult(CommandBasePtr relatedCommand, int prn, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetBeiDouSatelliteHealthInfoResultPtr GetBeiDouSatelliteHealthInfoResult::create(CommandBasePtr relatedCommand, int prn, int health)
    {
      return GetBeiDouSatelliteHealthInfoResultPtr(new GetBeiDouSatelliteHealthInfoResult(relatedCommand, prn, health));
    }

    GetBeiDouSatelliteHealthInfoResultPtr GetBeiDouSatelliteHealthInfoResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouSatelliteHealthInfoResult>(ptr);
    }

    bool GetBeiDouSatelliteHealthInfoResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouSatelliteHealthInfoResult::documentation() const { return Documentation; }


    int GetBeiDouSatelliteHealthInfoResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouSatelliteHealthInfoResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouSatelliteHealthInfoResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouSatelliteHealthInfoResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
