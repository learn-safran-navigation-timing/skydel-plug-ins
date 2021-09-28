#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav2Messages
///
#include "gen/GetBeiDouCNav2Messages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav2Messages::CmdName = "GetBeiDouCNav2Messages";
    const char* const GetBeiDouCNav2Messages::Documentation = "Please note the command GetBeiDouCNav2Messages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the BeiDou CNAV2 Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetBeiDouCNav2Messages);


    GetBeiDouCNav2Messages::GetBeiDouCNav2Messages()
      : CommandBase(CmdName)
    {}

    GetBeiDouCNav2Messages::GetBeiDouCNav2Messages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouCNav2MessagesPtr GetBeiDouCNav2Messages::create(int prn)
    {
      return GetBeiDouCNav2MessagesPtr(new GetBeiDouCNav2Messages(prn));
    }

    GetBeiDouCNav2MessagesPtr GetBeiDouCNav2Messages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav2Messages>(ptr);
    }

    bool GetBeiDouCNav2Messages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouCNav2Messages::documentation() const { return Documentation; }


    int GetBeiDouCNav2Messages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouCNav2Messages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouCNav2Messages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
