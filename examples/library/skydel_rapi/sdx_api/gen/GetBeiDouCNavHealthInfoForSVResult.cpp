#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavHealthInfoForSVResult
///
#include "gen/GetBeiDouCNavHealthInfoForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavHealthInfoForSVResult::CmdName = "GetBeiDouCNavHealthInfoForSVResult";
    const char* const GetBeiDouCNavHealthInfoForSVResult::Documentation = "Result of GetBeiDouCNavHealthInfoForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouCNavHealthInfoForSVResult);


    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::create(CommandBasePtr relatedCommand, int svId, int health)
    {
      return GetBeiDouCNavHealthInfoForSVResultPtr(new GetBeiDouCNavHealthInfoForSVResult(relatedCommand, svId, health));
    }

    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavHealthInfoForSVResult>(ptr);
    }

    bool GetBeiDouCNavHealthInfoForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouCNavHealthInfoForSVResult::documentation() const { return Documentation; }


    int GetBeiDouCNavHealthInfoForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNavHealthInfoForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
