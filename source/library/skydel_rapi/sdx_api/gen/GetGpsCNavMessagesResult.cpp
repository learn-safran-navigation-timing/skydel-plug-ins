#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavMessagesResult
///
#include "gen/GetGpsCNavMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavMessagesResult::CmdName = "GetGpsCNavMessagesResult";
    const char* const GetGpsCNavMessagesResult::Documentation = "Result of GetGpsCNavMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsCNavMessagesResult);


    GetGpsCNavMessagesResult::GetGpsCNavMessagesResult()
      : CommandResult(CmdName)
    {}

    GetGpsCNavMessagesResult::GetGpsCNavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetGpsCNavMessagesResultPtr GetGpsCNavMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetGpsCNavMessagesResultPtr(new GetGpsCNavMessagesResult(relatedCommand, ids));
    }

    GetGpsCNavMessagesResultPtr GetGpsCNavMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNavMessagesResult>(ptr);
    }

    bool GetGpsCNavMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetGpsCNavMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetGpsCNavMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetGpsCNavMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
