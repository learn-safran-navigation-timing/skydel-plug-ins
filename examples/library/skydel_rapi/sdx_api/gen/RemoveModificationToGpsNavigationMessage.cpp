#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToGpsNavigationMessage
///
#include "gen/RemoveModificationToGpsNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToGpsNavigationMessage::CmdName = "RemoveModificationToGpsNavigationMessage";
    const char* const RemoveModificationToGpsNavigationMessage::Documentation = "Please note the command RemoveModificationToGpsNavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves an event added with SetModificationToGpsNavigationMessage. When adding an event, the simulator\nsets the Id parameter. Use that Id here to remove the associated event.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToGpsNavigationMessage);


    RemoveModificationToGpsNavigationMessage::RemoveModificationToGpsNavigationMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToGpsNavigationMessage::RemoveModificationToGpsNavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToGpsNavigationMessagePtr RemoveModificationToGpsNavigationMessage::create(const std::string& id)
    {
      return RemoveModificationToGpsNavigationMessagePtr(new RemoveModificationToGpsNavigationMessage(id));
    }

    RemoveModificationToGpsNavigationMessagePtr RemoveModificationToGpsNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToGpsNavigationMessage>(ptr);
    }

    bool RemoveModificationToGpsNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToGpsNavigationMessage::documentation() const { return Documentation; }


    int RemoveModificationToGpsNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToGpsNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToGpsNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
