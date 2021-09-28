#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavSatelliteHealthInfoResult
///
#include "gen/GetBeiDouCNavSatelliteHealthInfoResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavSatelliteHealthInfoResult::CmdName = "GetBeiDouCNavSatelliteHealthInfoResult";
    const char* const GetBeiDouCNavSatelliteHealthInfoResult::Documentation = "Result of GetBeiDouCNavSatelliteHealthInfo.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouCNavSatelliteHealthInfoResult);


    GetBeiDouCNavSatelliteHealthInfoResult::GetBeiDouCNavSatelliteHealthInfoResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouCNavSatelliteHealthInfoResult::GetBeiDouCNavSatelliteHealthInfoResult(CommandBasePtr relatedCommand, int prn, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setHealth(health);
    }


    GetBeiDouCNavSatelliteHealthInfoResultPtr GetBeiDouCNavSatelliteHealthInfoResult::create(CommandBasePtr relatedCommand, int prn, int health)
    {
      return GetBeiDouCNavSatelliteHealthInfoResultPtr(new GetBeiDouCNavSatelliteHealthInfoResult(relatedCommand, prn, health));
    }

    GetBeiDouCNavSatelliteHealthInfoResultPtr GetBeiDouCNavSatelliteHealthInfoResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavSatelliteHealthInfoResult>(ptr);
    }

    bool GetBeiDouCNavSatelliteHealthInfoResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouCNavSatelliteHealthInfoResult::documentation() const { return Documentation; }


    int GetBeiDouCNavSatelliteHealthInfoResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouCNavSatelliteHealthInfoResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNavSatelliteHealthInfoResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouCNavSatelliteHealthInfoResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
