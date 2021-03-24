#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoINavMessagesResult
///
#include "gen/GetGalileoINavMessagesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoINavMessagesResult::CmdName = "GetGalileoINavMessagesResult";
    const char* const GetGalileoINavMessagesResult::Documentation = "Result of GetGalileoINavMessages";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoINavMessagesResult);


    GetGalileoINavMessagesResult::GetGalileoINavMessagesResult()
      : CommandResult(CmdName)
    {}

    GetGalileoINavMessagesResult::GetGalileoINavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetGalileoINavMessagesResultPtr GetGalileoINavMessagesResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetGalileoINavMessagesResultPtr(new GetGalileoINavMessagesResult(relatedCommand, ids));
    }

    GetGalileoINavMessagesResultPtr GetGalileoINavMessagesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoINavMessagesResult>(ptr);
    }

    bool GetGalileoINavMessagesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetGalileoINavMessagesResult::documentation() const { return Documentation; }


    std::vector<std::string> GetGalileoINavMessagesResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetGalileoINavMessagesResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
