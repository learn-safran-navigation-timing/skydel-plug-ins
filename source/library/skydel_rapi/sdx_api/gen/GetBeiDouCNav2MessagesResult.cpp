#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav2MessagesResult
///
#include "gen/GetBeiDouCNav2MessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav2MessagesResult::CmdName = "GetBeiDouCNav2MessagesResult";
    const char* const GetBeiDouCNav2MessagesResult::Documentation = "Result of GetBeiDouCNav2Messages";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouCNav2MessagesResult);


    GetBeiDouCNav2MessagesResult::GetBeiDouCNav2MessagesResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouCNav2MessagesResult::GetBeiDouCNav2MessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetBeiDouCNav2MessagesResultPtr GetBeiDouCNav2MessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetBeiDouCNav2MessagesResultPtr(new GetBeiDouCNav2MessagesResult(relatedCommand, ids));
    }

    GetBeiDouCNav2MessagesResultPtr GetBeiDouCNav2MessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav2MessagesResult>(ptr);
    }

    bool GetBeiDouCNav2MessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetBeiDouCNav2MessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetBeiDouCNav2MessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetBeiDouCNav2MessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
