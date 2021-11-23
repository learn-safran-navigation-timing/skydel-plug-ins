#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassNavigationMessagesResult
///
#include "gen/GetGlonassNavigationMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassNavigationMessagesResult::CmdName = "GetGlonassNavigationMessagesResult";
    const char* const GetGlonassNavigationMessagesResult::Documentation = "Result of GetGlonassNavigationMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetGlonassNavigationMessagesResult);


    GetGlonassNavigationMessagesResult::GetGlonassNavigationMessagesResult()
      : CommandResult(CmdName)
    {}

    GetGlonassNavigationMessagesResult::GetGlonassNavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetGlonassNavigationMessagesResultPtr GetGlonassNavigationMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetGlonassNavigationMessagesResultPtr(new GetGlonassNavigationMessagesResult(relatedCommand, ids));
    }

    GetGlonassNavigationMessagesResultPtr GetGlonassNavigationMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassNavigationMessagesResult>(ptr);
    }

    bool GetGlonassNavigationMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetGlonassNavigationMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetGlonassNavigationMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetGlonassNavigationMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
