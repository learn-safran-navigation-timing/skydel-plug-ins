#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsMNavMessages
///
#include "gen/GetGpsMNavMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsMNavMessages::CmdName = "GetGpsMNavMessages";
    const char* const GetGpsMNavMessages::Documentation = "Please note the command GetGpsMNavMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the GPS MNav Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetGpsMNavMessages);


    GetGpsMNavMessages::GetGpsMNavMessages()
      : CommandBase(CmdName)
    {}

    GetGpsMNavMessages::GetGpsMNavMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsMNavMessagesPtr GetGpsMNavMessages::create(int prn)
    {
      return GetGpsMNavMessagesPtr(new GetGpsMNavMessages(prn));
    }

    GetGpsMNavMessagesPtr GetGpsMNavMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsMNavMessages>(ptr);
    }

    bool GetGpsMNavMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsMNavMessages::documentation() const { return Documentation; }


    int GetGpsMNavMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsMNavMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsMNavMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
