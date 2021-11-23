#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD1NavigationMessagesResult
///
#include "gen/GetBeiDouD1NavigationMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD1NavigationMessagesResult::CmdName = "GetBeiDouD1NavigationMessagesResult";
    const char* const GetBeiDouD1NavigationMessagesResult::Documentation = "Result of GetBeiDouD1NavigationMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouD1NavigationMessagesResult);


    GetBeiDouD1NavigationMessagesResult::GetBeiDouD1NavigationMessagesResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouD1NavigationMessagesResult::GetBeiDouD1NavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetBeiDouD1NavigationMessagesResultPtr GetBeiDouD1NavigationMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetBeiDouD1NavigationMessagesResultPtr(new GetBeiDouD1NavigationMessagesResult(relatedCommand, ids));
    }

    GetBeiDouD1NavigationMessagesResultPtr GetBeiDouD1NavigationMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD1NavigationMessagesResult>(ptr);
    }

    bool GetBeiDouD1NavigationMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetBeiDouD1NavigationMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetBeiDouD1NavigationMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetBeiDouD1NavigationMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
