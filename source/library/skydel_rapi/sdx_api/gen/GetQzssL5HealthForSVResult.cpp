#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL5HealthForSVResult
///
#include "gen/GetQzssL5HealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL5HealthForSVResult::CmdName = "GetQzssL5HealthForSVResult";
    const char* const GetQzssL5HealthForSVResult::Documentation = "Result of GetQzssL5HealthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssL5HealthForSVResult);


    GetQzssL5HealthForSVResult::GetQzssL5HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssL5HealthForSVResult::GetQzssL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetQzssL5HealthForSVResultPtr GetQzssL5HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health)
    {
      return GetQzssL5HealthForSVResultPtr(new GetQzssL5HealthForSVResult(relatedCommand, svId, health));
    }

    GetQzssL5HealthForSVResultPtr GetQzssL5HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL5HealthForSVResult>(ptr);
    }

    bool GetQzssL5HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetQzssL5HealthForSVResult::documentation() const { return Documentation; }


    int GetQzssL5HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL5HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL5HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetQzssL5HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
