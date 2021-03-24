#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssLNAVNavigationMessages
///
#include "gen/GetQzssLNAVNavigationMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssLNAVNavigationMessages::CmdName = "GetQzssLNAVNavigationMessages";
    const char* const GetQzssLNAVNavigationMessages::Documentation = "Please note the command GetQzssLNAVNavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the QZSS Navigation Message for this SV ID";

    REGISTER_COMMAND_FACTORY(GetQzssLNAVNavigationMessages);


    GetQzssLNAVNavigationMessages::GetQzssLNAVNavigationMessages()
      : CommandBase(CmdName)
    {}

    GetQzssLNAVNavigationMessages::GetQzssLNAVNavigationMessages(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssLNAVNavigationMessagesPtr GetQzssLNAVNavigationMessages::create(int svId)
    {
      return GetQzssLNAVNavigationMessagesPtr(new GetQzssLNAVNavigationMessages(svId));
    }

    GetQzssLNAVNavigationMessagesPtr GetQzssLNAVNavigationMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssLNAVNavigationMessages>(ptr);
    }

    bool GetQzssLNAVNavigationMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssLNAVNavigationMessages::documentation() const { return Documentation; }


    int GetQzssLNAVNavigationMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssLNAVNavigationMessages::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssLNAVNavigationMessages::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
