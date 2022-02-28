#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCnav2PagesEnabledResult
///
#include "gen/GetCnav2PagesEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCnav2PagesEnabledResult::CmdName = "GetCnav2PagesEnabledResult";
    const char* const GetCnav2PagesEnabledResult::Documentation = "Result of GetCnav2PagesEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(GetCnav2PagesEnabledResult);


    GetCnav2PagesEnabledResult::GetCnav2PagesEnabledResult()
      : CommandResult(CmdName)
    {}

    GetCnav2PagesEnabledResult::GetCnav2PagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages)
      : CommandResult(CmdName, relatedCommand)
    {

      setMessages(messages);
    }


    GetCnav2PagesEnabledResultPtr GetCnav2PagesEnabledResult::create(CommandBasePtr relatedCommand, const std::vector<int>& messages)
    {
      return GetCnav2PagesEnabledResultPtr(new GetCnav2PagesEnabledResult(relatedCommand, messages));
    }

    GetCnav2PagesEnabledResultPtr GetCnav2PagesEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCnav2PagesEnabledResult>(ptr);
    }

    bool GetCnav2PagesEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["Messages"])
        ;

    }

    std::string GetCnav2PagesEnabledResult::documentation() const { return Documentation; }


    std::vector<int> GetCnav2PagesEnabledResult::messages() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Messages"]);
    }

    void GetCnav2PagesEnabledResult::setMessages(const std::vector<int>& messages)
    {
      m_values.AddMember("Messages", parse_json<std::vector<int>>::format(messages, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
