#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav1Messages
///
#include "gen/GetBeiDouCNav1Messages.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav1Messages::CmdName = "GetBeiDouCNav1Messages";
    const char* const GetBeiDouCNav1Messages::Documentation = "Please note the command GetBeiDouCNav1Messages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.\n\nGet all events' IDs whose will modify the BeiDou CNav1 Message for this PRN";

    REGISTER_COMMAND_FACTORY(GetBeiDouCNav1Messages);


    GetBeiDouCNav1Messages::GetBeiDouCNav1Messages()
      : CommandBase(CmdName)
    {}

    GetBeiDouCNav1Messages::GetBeiDouCNav1Messages(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouCNav1MessagesPtr GetBeiDouCNav1Messages::create(int prn)
    {
      return GetBeiDouCNav1MessagesPtr(new GetBeiDouCNav1Messages(prn));
    }

    GetBeiDouCNav1MessagesPtr GetBeiDouCNav1Messages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav1Messages>(ptr);
    }

    bool GetBeiDouCNav1Messages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouCNav1Messages::documentation() const { return Documentation; }


    int GetBeiDouCNav1Messages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouCNav1Messages::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouCNav1Messages::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
