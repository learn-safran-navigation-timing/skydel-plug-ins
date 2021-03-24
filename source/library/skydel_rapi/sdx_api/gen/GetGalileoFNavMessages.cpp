#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFNavMessages
///
#include "gen/GetGalileoFNavMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFNavMessages::CmdName = "GetGalileoFNavMessages";
    const char* const GetGalileoFNavMessages::Documentation = "Please note the command GetGalileoFNavMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the GALILEO FNAV Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetGalileoFNavMessages);


    GetGalileoFNavMessages::GetGalileoFNavMessages()
      : CommandBase(CmdName)
    {}

    GetGalileoFNavMessages::GetGalileoFNavMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGalileoFNavMessagesPtr GetGalileoFNavMessages::create(int prn)
    {
      return GetGalileoFNavMessagesPtr(new GetGalileoFNavMessages(prn));
    }

    GetGalileoFNavMessagesPtr GetGalileoFNavMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoFNavMessages>(ptr);
    }

    bool GetGalileoFNavMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGalileoFNavMessages::documentation() const { return Documentation; }


    int GetGalileoFNavMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoFNavMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoFNavMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
