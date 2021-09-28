#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouAutonomousHealthForSVResult
///
#include "gen/GetBeiDouAutonomousHealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouAutonomousHealthForSVResult::CmdName = "GetBeiDouAutonomousHealthForSVResult";
    const char* const GetBeiDouAutonomousHealthForSVResult::Documentation = "Result of GetBeiDouAutonomousHealthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouAutonomousHealthForSVResult);


    GetBeiDouAutonomousHealthForSVResult::GetBeiDouAutonomousHealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouAutonomousHealthForSVResult::GetBeiDouAutonomousHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetBeiDouAutonomousHealthForSVResultPtr GetBeiDouAutonomousHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health)
    {
      return GetBeiDouAutonomousHealthForSVResultPtr(new GetBeiDouAutonomousHealthForSVResult(relatedCommand, svId, health));
    }

    GetBeiDouAutonomousHealthForSVResultPtr GetBeiDouAutonomousHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouAutonomousHealthForSVResult>(ptr);
    }

    bool GetBeiDouAutonomousHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetBeiDouAutonomousHealthForSVResult::documentation() const { return Documentation; }


    int GetBeiDouAutonomousHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouAutonomousHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouAutonomousHealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetBeiDouAutonomousHealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
