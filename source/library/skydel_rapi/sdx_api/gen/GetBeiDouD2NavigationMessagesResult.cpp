#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD2NavigationMessagesResult
///
#include "gen/GetBeiDouD2NavigationMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD2NavigationMessagesResult::CmdName = "GetBeiDouD2NavigationMessagesResult";
    const char* const GetBeiDouD2NavigationMessagesResult::Documentation = "Result of GetBeiDouD2NavigationMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouD2NavigationMessagesResult);


    GetBeiDouD2NavigationMessagesResult::GetBeiDouD2NavigationMessagesResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouD2NavigationMessagesResult::GetBeiDouD2NavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetBeiDouD2NavigationMessagesResultPtr GetBeiDouD2NavigationMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetBeiDouD2NavigationMessagesResultPtr(new GetBeiDouD2NavigationMessagesResult(relatedCommand, ids));
    }

    GetBeiDouD2NavigationMessagesResultPtr GetBeiDouD2NavigationMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD2NavigationMessagesResult>(ptr);
    }

    bool GetBeiDouD2NavigationMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetBeiDouD2NavigationMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetBeiDouD2NavigationMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetBeiDouD2NavigationMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
