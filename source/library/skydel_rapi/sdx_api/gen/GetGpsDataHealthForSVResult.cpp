#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsDataHealthForSVResult
///
#include "gen/GetGpsDataHealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsDataHealthForSVResult::CmdName = "GetGpsDataHealthForSVResult";
    const char* const GetGpsDataHealthForSVResult::Documentation = "Result of GetGpsDataHealthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsDataHealthForSVResult);


    GetGpsDataHealthForSVResult::GetGpsDataHealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsDataHealthForSVResult::GetGpsDataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetGpsDataHealthForSVResultPtr GetGpsDataHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, int health)
    {
      return GetGpsDataHealthForSVResultPtr(new GetGpsDataHealthForSVResult(relatedCommand, svId, health));
    }

    GetGpsDataHealthForSVResultPtr GetGpsDataHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsDataHealthForSVResult>(ptr);
    }

    bool GetGpsDataHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsDataHealthForSVResult::documentation() const { return Documentation; }


    int GetGpsDataHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsDataHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsDataHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGpsDataHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
