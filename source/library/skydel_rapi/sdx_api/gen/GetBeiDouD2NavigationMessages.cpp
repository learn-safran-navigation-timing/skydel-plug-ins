#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD2NavigationMessages
///
#include "gen/GetBeiDouD2NavigationMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD2NavigationMessages::CmdName = "GetBeiDouD2NavigationMessages";
    const char* const GetBeiDouD2NavigationMessages::Documentation = "Please note the command GetBeiDouD2NavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the BeiDou D2 Navigation Messages for this PRN";

    REGISTER_COMMAND_FACTORY(GetBeiDouD2NavigationMessages);


    GetBeiDouD2NavigationMessages::GetBeiDouD2NavigationMessages()
      : CommandBase(CmdName)
    {}

    GetBeiDouD2NavigationMessages::GetBeiDouD2NavigationMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouD2NavigationMessagesPtr GetBeiDouD2NavigationMessages::create(int prn)
    {
      return GetBeiDouD2NavigationMessagesPtr(new GetBeiDouD2NavigationMessages(prn));
    }

    GetBeiDouD2NavigationMessagesPtr GetBeiDouD2NavigationMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD2NavigationMessages>(ptr);
    }

    bool GetBeiDouD2NavigationMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouD2NavigationMessages::documentation() const { return Documentation; }


    int GetBeiDouD2NavigationMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouD2NavigationMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouD2NavigationMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
