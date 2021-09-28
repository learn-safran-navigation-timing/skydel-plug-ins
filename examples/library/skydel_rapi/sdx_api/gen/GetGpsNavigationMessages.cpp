#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavigationMessages
///
#include "gen/GetGpsNavigationMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavigationMessages::CmdName = "GetGpsNavigationMessages";
    const char* const GetGpsNavigationMessages::Documentation = "Please note the command GetGpsNavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the GPS Navigation Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetGpsNavigationMessages);


    GetGpsNavigationMessages::GetGpsNavigationMessages()
      : CommandBase(CmdName)
    {}

    GetGpsNavigationMessages::GetGpsNavigationMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsNavigationMessagesPtr GetGpsNavigationMessages::create(int prn)
    {
      return GetGpsNavigationMessagesPtr(new GetGpsNavigationMessages(prn));
    }

    GetGpsNavigationMessagesPtr GetGpsNavigationMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavigationMessages>(ptr);
    }

    bool GetGpsNavigationMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsNavigationMessages::documentation() const { return Documentation; }


    int GetGpsNavigationMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsNavigationMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsNavigationMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
