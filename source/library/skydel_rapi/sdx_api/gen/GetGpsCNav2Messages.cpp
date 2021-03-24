#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNav2Messages
///
#include "gen/GetGpsCNav2Messages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNav2Messages::CmdName = "GetGpsCNav2Messages";
    const char* const GetGpsCNav2Messages::Documentation = "Please note the command GetGpsCNav2Messages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the GPS CNav2 Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetGpsCNav2Messages);


    GetGpsCNav2Messages::GetGpsCNav2Messages()
      : CommandBase(CmdName)
    {}

    GetGpsCNav2Messages::GetGpsCNav2Messages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsCNav2MessagesPtr GetGpsCNav2Messages::create(int prn)
    {
      return GetGpsCNav2MessagesPtr(new GetGpsCNav2Messages(prn));
    }

    GetGpsCNav2MessagesPtr GetGpsCNav2Messages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNav2Messages>(ptr);
    }

    bool GetGpsCNav2Messages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsCNav2Messages::documentation() const { return Documentation; }


    int GetGpsCNav2Messages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsCNav2Messages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsCNav2Messages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
