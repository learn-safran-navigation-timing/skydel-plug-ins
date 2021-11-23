#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthStatusForSVResult
///
#include "gen/GetBeiDouHealthStatusForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthStatusForSVResult::CmdName = "GetBeiDouHealthStatusForSVResult";
    const char* const GetBeiDouHealthStatusForSVResult::Documentation = "Result of GetBeiDouHealthStatusForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouHealthStatusForSVResult);


    GetBeiDouHealthStatusForSVResult::GetBeiDouHealthStatusForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouHealthStatusForSVResult::GetBeiDouHealthStatusForSVResult(CommandBasePtr relatedCommand, int svId, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetBeiDouHealthStatusForSVResultPtr GetBeiDouHealthStatusForSVResult::create(CommandBasePtr relatedCommand, int svId, int health)
    {
      return GetBeiDouHealthStatusForSVResultPtr(new GetBeiDouHealthStatusForSVResult(relatedCommand, svId, health));
    }

    GetBeiDouHealthStatusForSVResultPtr GetBeiDouHealthStatusForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthStatusForSVResult>(ptr);
    }

    bool GetBeiDouHealthStatusForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouHealthStatusForSVResult::documentation() const { return Documentation; }


    int GetBeiDouHealthStatusForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthStatusForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouHealthStatusForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouHealthStatusForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
