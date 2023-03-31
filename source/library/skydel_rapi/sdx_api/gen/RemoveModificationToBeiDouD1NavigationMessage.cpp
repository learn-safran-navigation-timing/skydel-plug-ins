#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToBeiDouD1NavigationMessage
///
#include "gen/RemoveModificationToBeiDouD1NavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToBeiDouD1NavigationMessage::CmdName = "RemoveModificationToBeiDouD1NavigationMessage";
    const char* const RemoveModificationToBeiDouD1NavigationMessage::Documentation = "Please note the command RemoveModificationToBeiDouD1NavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves an event added with SetModificationToBeiDouNavigationMessage. When adding an event, the simulator\nsets the Id parameter. Use that Id here to remove the associated event.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToBeiDouD1NavigationMessage);


    RemoveModificationToBeiDouD1NavigationMessage::RemoveModificationToBeiDouD1NavigationMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToBeiDouD1NavigationMessage::RemoveModificationToBeiDouD1NavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToBeiDouD1NavigationMessagePtr RemoveModificationToBeiDouD1NavigationMessage::create(const std::string& id)
    {
      return RemoveModificationToBeiDouD1NavigationMessagePtr(new RemoveModificationToBeiDouD1NavigationMessage(id));
    }

    RemoveModificationToBeiDouD1NavigationMessagePtr RemoveModificationToBeiDouD1NavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToBeiDouD1NavigationMessage>(ptr);
    }

    bool RemoveModificationToBeiDouD1NavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToBeiDouD1NavigationMessage::documentation() const { return Documentation; }


    int RemoveModificationToBeiDouD1NavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToBeiDouD1NavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToBeiDouD1NavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
