#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssLNAVNavigationMessagesResult
///
#include "gen/GetQzssLNAVNavigationMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssLNAVNavigationMessagesResult::CmdName = "GetQzssLNAVNavigationMessagesResult";
    const char* const GetQzssLNAVNavigationMessagesResult::Documentation = "Result of GetQzssLNAVNavigationMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssLNAVNavigationMessagesResult);


    GetQzssLNAVNavigationMessagesResult::GetQzssLNAVNavigationMessagesResult()
      : CommandResult(CmdName)
    {}

    GetQzssLNAVNavigationMessagesResult::GetQzssLNAVNavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetQzssLNAVNavigationMessagesResultPtr GetQzssLNAVNavigationMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetQzssLNAVNavigationMessagesResultPtr(new GetQzssLNAVNavigationMessagesResult(relatedCommand, ids));
    }

    GetQzssLNAVNavigationMessagesResultPtr GetQzssLNAVNavigationMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssLNAVNavigationMessagesResult>(ptr);
    }

    bool GetQzssLNAVNavigationMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetQzssLNAVNavigationMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetQzssLNAVNavigationMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetQzssLNAVNavigationMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
