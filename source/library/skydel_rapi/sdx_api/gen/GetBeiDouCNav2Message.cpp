#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav2Message
///
#include "gen/GetBeiDouCNav2Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav2Message::CmdName = "GetBeiDouCNav2Message";
    const char* const GetBeiDouCNav2Message::Documentation = "Please note the command GetBeiDouCNav2Message is deprecated since 21.3. You may use GetMessageModificationToBeiDouCNav2.\n\nGet infos about the modifications of CNAV2 Message with this id";

    REGISTER_COMMAND_FACTORY(GetBeiDouCNav2Message);


    GetBeiDouCNav2Message::GetBeiDouCNav2Message()
      : CommandBase(CmdName)
    {}

    GetBeiDouCNav2Message::GetBeiDouCNav2Message(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetBeiDouCNav2MessagePtr GetBeiDouCNav2Message::create(const std::string& id)
    {
      return GetBeiDouCNav2MessagePtr(new GetBeiDouCNav2Message(id));
    }

    GetBeiDouCNav2MessagePtr GetBeiDouCNav2Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav2Message>(ptr);
    }

    bool GetBeiDouCNav2Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetBeiDouCNav2Message::documentation() const { return Documentation; }


    int GetBeiDouCNav2Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouCNav2Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouCNav2Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
