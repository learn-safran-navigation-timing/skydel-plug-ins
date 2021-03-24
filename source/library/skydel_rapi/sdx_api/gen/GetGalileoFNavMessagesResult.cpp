#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFNavMessagesResult
///
#include "gen/GetGalileoFNavMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFNavMessagesResult::CmdName = "GetGalileoFNavMessagesResult";
    const char* const GetGalileoFNavMessagesResult::Documentation = "Result of GetGalileoFNavMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoFNavMessagesResult);


    GetGalileoFNavMessagesResult::GetGalileoFNavMessagesResult()
      : CommandResult(CmdName)
    {}

    GetGalileoFNavMessagesResult::GetGalileoFNavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetGalileoFNavMessagesResultPtr GetGalileoFNavMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetGalileoFNavMessagesResultPtr(new GetGalileoFNavMessagesResult(relatedCommand, ids));
    }

    GetGalileoFNavMessagesResultPtr GetGalileoFNavMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoFNavMessagesResult>(ptr);
    }

    bool GetGalileoFNavMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetGalileoFNavMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetGalileoFNavMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetGalileoFNavMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
