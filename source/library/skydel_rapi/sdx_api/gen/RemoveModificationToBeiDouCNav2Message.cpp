#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToBeiDouCNav2Message
///
#include "gen/RemoveModificationToBeiDouCNav2Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToBeiDouCNav2Message::CmdName = "RemoveModificationToBeiDouCNav2Message";
    const char* const RemoveModificationToBeiDouCNav2Message::Documentation = "Please note the command RemoveModificationToBeiDouCNav2Message is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves a BeiDou CNAV2 modification.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToBeiDouCNav2Message);


    RemoveModificationToBeiDouCNav2Message::RemoveModificationToBeiDouCNav2Message()
      : CommandBase(CmdName)
    {}

    RemoveModificationToBeiDouCNav2Message::RemoveModificationToBeiDouCNav2Message(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToBeiDouCNav2MessagePtr RemoveModificationToBeiDouCNav2Message::create(const std::string& id)
    {
      return RemoveModificationToBeiDouCNav2MessagePtr(new RemoveModificationToBeiDouCNav2Message(id));
    }

    RemoveModificationToBeiDouCNav2MessagePtr RemoveModificationToBeiDouCNav2Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToBeiDouCNav2Message>(ptr);
    }

    bool RemoveModificationToBeiDouCNav2Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToBeiDouCNav2Message::documentation() const { return Documentation; }


    int RemoveModificationToBeiDouCNav2Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToBeiDouCNav2Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToBeiDouCNav2Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
