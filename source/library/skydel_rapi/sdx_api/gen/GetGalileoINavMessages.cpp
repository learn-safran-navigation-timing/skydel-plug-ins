#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoINavMessages
///
#include "gen/GetGalileoINavMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoINavMessages::CmdName = "GetGalileoINavMessages";
    const char* const GetGalileoINavMessages::Documentation = "Please note the command GetGalileoINavMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the GALILEO INAV Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetGalileoINavMessages);


    GetGalileoINavMessages::GetGalileoINavMessages()
      : CommandBase(CmdName)
    {}

    GetGalileoINavMessages::GetGalileoINavMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGalileoINavMessagesPtr GetGalileoINavMessages::create(int prn)
    {
      return GetGalileoINavMessagesPtr(new GetGalileoINavMessages(prn));
    }

    GetGalileoINavMessagesPtr GetGalileoINavMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoINavMessages>(ptr);
    }

    bool GetGalileoINavMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGalileoINavMessages::documentation() const { return Documentation; }


    int GetGalileoINavMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoINavMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoINavMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
