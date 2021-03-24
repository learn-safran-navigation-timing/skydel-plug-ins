#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavMessages
///
#include "gen/GetGpsCNavMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavMessages::CmdName = "GetGpsCNavMessages";
    const char* const GetGpsCNavMessages::Documentation = "Please note the command GetGpsCNavMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the GPS CNav Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetGpsCNavMessages);


    GetGpsCNavMessages::GetGpsCNavMessages()
      : CommandBase(CmdName)
    {}

    GetGpsCNavMessages::GetGpsCNavMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsCNavMessagesPtr GetGpsCNavMessages::create(int prn)
    {
      return GetGpsCNavMessagesPtr(new GetGpsCNavMessages(prn));
    }

    GetGpsCNavMessagesPtr GetGpsCNavMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNavMessages>(ptr);
    }

    bool GetGpsCNavMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsCNavMessages::documentation() const { return Documentation; }


    int GetGpsCNavMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsCNavMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsCNavMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
