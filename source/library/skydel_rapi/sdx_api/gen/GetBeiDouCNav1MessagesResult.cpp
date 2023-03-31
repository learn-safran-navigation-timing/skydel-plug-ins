#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav1MessagesResult
///
#include "gen/GetBeiDouCNav1MessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav1MessagesResult::CmdName = "GetBeiDouCNav1MessagesResult";
    const char* const GetBeiDouCNav1MessagesResult::Documentation = "Result of GetBeiDouCNav1Messages";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouCNav1MessagesResult);


    GetBeiDouCNav1MessagesResult::GetBeiDouCNav1MessagesResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouCNav1MessagesResult::GetBeiDouCNav1MessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetBeiDouCNav1MessagesResultPtr GetBeiDouCNav1MessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetBeiDouCNav1MessagesResultPtr(new GetBeiDouCNav1MessagesResult(relatedCommand, ids));
    }

    GetBeiDouCNav1MessagesResultPtr GetBeiDouCNav1MessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav1MessagesResult>(ptr);
    }

    bool GetBeiDouCNav1MessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetBeiDouCNav1MessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetBeiDouCNav1MessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetBeiDouCNav1MessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
