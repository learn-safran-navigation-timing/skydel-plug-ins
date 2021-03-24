#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD1NavigationMessages
///
#include "gen/GetBeiDouD1NavigationMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD1NavigationMessages::CmdName = "GetBeiDouD1NavigationMessages";
    const char* const GetBeiDouD1NavigationMessages::Documentation = "Please note the command GetBeiDouD1NavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the BeiDou D1 Navigation Messages for this PRN";

    REGISTER_COMMAND_FACTORY(GetBeiDouD1NavigationMessages);


    GetBeiDouD1NavigationMessages::GetBeiDouD1NavigationMessages()
      : CommandBase(CmdName)
    {}

    GetBeiDouD1NavigationMessages::GetBeiDouD1NavigationMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouD1NavigationMessagesPtr GetBeiDouD1NavigationMessages::create(int prn)
    {
      return GetBeiDouD1NavigationMessagesPtr(new GetBeiDouD1NavigationMessages(prn));
    }

    GetBeiDouD1NavigationMessagesPtr GetBeiDouD1NavigationMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD1NavigationMessages>(ptr);
    }

    bool GetBeiDouD1NavigationMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouD1NavigationMessages::documentation() const { return Documentation; }


    int GetBeiDouD1NavigationMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouD1NavigationMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouD1NavigationMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
