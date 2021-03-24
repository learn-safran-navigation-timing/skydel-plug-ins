#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavigationMessagesResult
///
#include "gen/GetGpsNavigationMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavigationMessagesResult::CmdName = "GetGpsNavigationMessagesResult";
    const char* const GetGpsNavigationMessagesResult::Documentation = "Result of GetGpsNavigationMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsNavigationMessagesResult);


    GetGpsNavigationMessagesResult::GetGpsNavigationMessagesResult()
      : CommandResult(CmdName)
    {}

    GetGpsNavigationMessagesResult::GetGpsNavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetGpsNavigationMessagesResultPtr GetGpsNavigationMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetGpsNavigationMessagesResultPtr(new GetGpsNavigationMessagesResult(relatedCommand, ids));
    }

    GetGpsNavigationMessagesResultPtr GetGpsNavigationMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavigationMessagesResult>(ptr);
    }

    bool GetGpsNavigationMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetGpsNavigationMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetGpsNavigationMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetGpsNavigationMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
