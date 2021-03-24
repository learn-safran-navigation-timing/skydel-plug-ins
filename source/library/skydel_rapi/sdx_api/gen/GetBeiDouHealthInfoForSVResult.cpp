#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthInfoForSVResult
///
#include "gen/GetBeiDouHealthInfoForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthInfoForSVResult::CmdName = "GetBeiDouHealthInfoForSVResult";
    const char* const GetBeiDouHealthInfoForSVResult::Documentation = "Result of GetBeiDouHealthInfoForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouHealthInfoForSVResult);


    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::create(CommandBasePtr relatedCommand, int svId, int health)
    {
      return GetBeiDouHealthInfoForSVResultPtr(new GetBeiDouHealthInfoForSVResult(relatedCommand, svId, health));
    }

    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthInfoForSVResult>(ptr);
    }

    bool GetBeiDouHealthInfoForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouHealthInfoForSVResult::documentation() const { return Documentation; }


    int GetBeiDouHealthInfoForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthInfoForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouHealthInfoForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouHealthInfoForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
