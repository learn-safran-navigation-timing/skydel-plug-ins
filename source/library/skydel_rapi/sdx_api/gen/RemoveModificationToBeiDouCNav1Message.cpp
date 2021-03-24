#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToBeiDouCNav1Message
///
#include "gen/RemoveModificationToBeiDouCNav1Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToBeiDouCNav1Message::CmdName = "RemoveModificationToBeiDouCNav1Message";
    const char* const RemoveModificationToBeiDouCNav1Message::Documentation = "Please note the command RemoveModificationToBeiDouCNav1Message is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves a modification.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToBeiDouCNav1Message);


    RemoveModificationToBeiDouCNav1Message::RemoveModificationToBeiDouCNav1Message()
      : CommandBase(CmdName)
    {}

    RemoveModificationToBeiDouCNav1Message::RemoveModificationToBeiDouCNav1Message(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToBeiDouCNav1MessagePtr RemoveModificationToBeiDouCNav1Message::create(const std::string& id)
    {
      return RemoveModificationToBeiDouCNav1MessagePtr(new RemoveModificationToBeiDouCNav1Message(id));
    }

    RemoveModificationToBeiDouCNav1MessagePtr RemoveModificationToBeiDouCNav1Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToBeiDouCNav1Message>(ptr);
    }

    bool RemoveModificationToBeiDouCNav1Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToBeiDouCNav1Message::documentation() const { return Documentation; }


    int RemoveModificationToBeiDouCNav1Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToBeiDouCNav1Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToBeiDouCNav1Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
