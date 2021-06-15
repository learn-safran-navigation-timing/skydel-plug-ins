#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL2HealthForSVResult
///
#include "gen/GetQzssL2HealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL2HealthForSVResult::CmdName = "GetQzssL2HealthForSVResult";
    const char* const GetQzssL2HealthForSVResult::Documentation = "Result of GetQzssL2HealthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssL2HealthForSVResult);


    GetQzssL2HealthForSVResult::GetQzssL2HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssL2HealthForSVResult::GetQzssL2HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetQzssL2HealthForSVResultPtr GetQzssL2HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health)
    {
      return GetQzssL2HealthForSVResultPtr(new GetQzssL2HealthForSVResult(relatedCommand, svId, health));
    }

    GetQzssL2HealthForSVResultPtr GetQzssL2HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL2HealthForSVResult>(ptr);
    }

    bool GetQzssL2HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetQzssL2HealthForSVResult::documentation() const { return Documentation; }


    int GetQzssL2HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL2HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL2HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetQzssL2HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
