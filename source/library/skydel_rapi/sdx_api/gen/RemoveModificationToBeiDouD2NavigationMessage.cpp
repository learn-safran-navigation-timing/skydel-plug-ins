#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToBeiDouD2NavigationMessage
///
#include "gen/RemoveModificationToBeiDouD2NavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToBeiDouD2NavigationMessage::CmdName = "RemoveModificationToBeiDouD2NavigationMessage";
    const char* const RemoveModificationToBeiDouD2NavigationMessage::Documentation = "Please note the command RemoveModificationToBeiDouD2NavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves an event added with SetModificationToBeiDouNavigationMessage. When adding an event, the simulator\nsets the Id parameter. Use that Id here to remove the associated event.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToBeiDouD2NavigationMessage);


    RemoveModificationToBeiDouD2NavigationMessage::RemoveModificationToBeiDouD2NavigationMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToBeiDouD2NavigationMessage::RemoveModificationToBeiDouD2NavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToBeiDouD2NavigationMessagePtr RemoveModificationToBeiDouD2NavigationMessage::create(const std::string& id)
    {
      return RemoveModificationToBeiDouD2NavigationMessagePtr(new RemoveModificationToBeiDouD2NavigationMessage(id));
    }

    RemoveModificationToBeiDouD2NavigationMessagePtr RemoveModificationToBeiDouD2NavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToBeiDouD2NavigationMessage>(ptr);
    }

    bool RemoveModificationToBeiDouD2NavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToBeiDouD2NavigationMessage::documentation() const { return Documentation; }


    int RemoveModificationToBeiDouD2NavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToBeiDouD2NavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToBeiDouD2NavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
