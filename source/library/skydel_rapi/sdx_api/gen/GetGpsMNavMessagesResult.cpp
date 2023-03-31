#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsMNavMessagesResult
///
#include "gen/GetGpsMNavMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsMNavMessagesResult::CmdName = "GetGpsMNavMessagesResult";
    const char* const GetGpsMNavMessagesResult::Documentation = "Result of GetGpsMNavMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsMNavMessagesResult);


    GetGpsMNavMessagesResult::GetGpsMNavMessagesResult()
      : CommandResult(CmdName)
    {}

    GetGpsMNavMessagesResult::GetGpsMNavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetGpsMNavMessagesResultPtr GetGpsMNavMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetGpsMNavMessagesResultPtr(new GetGpsMNavMessagesResult(relatedCommand, ids));
    }

    GetGpsMNavMessagesResultPtr GetGpsMNavMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsMNavMessagesResult>(ptr);
    }

    bool GetGpsMNavMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetGpsMNavMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetGpsMNavMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetGpsMNavMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
