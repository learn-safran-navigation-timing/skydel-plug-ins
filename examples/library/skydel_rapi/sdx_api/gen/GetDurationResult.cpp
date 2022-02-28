#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDurationResult
///
#include "gen/GetDurationResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDurationResult::CmdName = "GetDurationResult";
    const char* const GetDurationResult::Documentation = "Result of GetDuration.";

    REGISTER_COMMAND_RESULT_FACTORY(GetDurationResult);


    GetDurationResult::GetDurationResult()
      : CommandResult(CmdName)
    {}

    GetDurationResult::GetDurationResult(CommandBasePtr relatedCommand, int second)
      : CommandResult(CmdName, relatedCommand)
    {

      setSecond(second);
    }


    GetDurationResultPtr GetDurationResult::create(CommandBasePtr relatedCommand, int second)
    {
      return GetDurationResultPtr(new GetDurationResult(relatedCommand, second));
    }

    GetDurationResultPtr GetDurationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDurationResult>(ptr);
    }

    bool GetDurationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Second"])
        ;

    }

    std::string GetDurationResult::documentation() const { return Documentation; }


    int GetDurationResult::second() const
    {
      return parse_json<int>::parse(m_values["Second"]);
    }

    void GetDurationResult::setSecond(int second)
    {
      m_values.AddMember("Second", parse_json<int>::format(second, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
