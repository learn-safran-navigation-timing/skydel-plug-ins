#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNav2MessagesResult
///
#include "gen/GetGpsCNav2MessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNav2MessagesResult::CmdName = "GetGpsCNav2MessagesResult";
    const char* const GetGpsCNav2MessagesResult::Documentation = "Result of GetGpsCNav2Messages";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsCNav2MessagesResult);


    GetGpsCNav2MessagesResult::GetGpsCNav2MessagesResult()
      : CommandResult(CmdName)
    {}

    GetGpsCNav2MessagesResult::GetGpsCNav2MessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetGpsCNav2MessagesResultPtr GetGpsCNav2MessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetGpsCNav2MessagesResultPtr(new GetGpsCNav2MessagesResult(relatedCommand, ids));
    }

    GetGpsCNav2MessagesResultPtr GetGpsCNav2MessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNav2MessagesResult>(ptr);
    }

    bool GetGpsCNav2MessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetGpsCNav2MessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetGpsCNav2MessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetGpsCNav2MessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
