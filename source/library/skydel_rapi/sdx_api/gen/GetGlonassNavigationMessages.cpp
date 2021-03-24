#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassNavigationMessages
///
#include "gen/GetGlonassNavigationMessages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassNavigationMessages::CmdName = "GetGlonassNavigationMessages";
    const char* const GetGlonassNavigationMessages::Documentation = "Please note the command GetGlonassNavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the Glonass Navigation Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetGlonassNavigationMessages);


    GetGlonassNavigationMessages::GetGlonassNavigationMessages()
      : CommandBase(CmdName)
    {}

    GetGlonassNavigationMessages::GetGlonassNavigationMessages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGlonassNavigationMessagesPtr GetGlonassNavigationMessages::create(int prn)
    {
      return GetGlonassNavigationMessagesPtr(new GetGlonassNavigationMessages(prn));
    }

    GetGlonassNavigationMessagesPtr GetGlonassNavigationMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassNavigationMessages>(ptr);
    }

    bool GetGlonassNavigationMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGlonassNavigationMessages::documentation() const { return Documentation; }


    int GetGlonassNavigationMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGlonassNavigationMessages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassNavigationMessages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
