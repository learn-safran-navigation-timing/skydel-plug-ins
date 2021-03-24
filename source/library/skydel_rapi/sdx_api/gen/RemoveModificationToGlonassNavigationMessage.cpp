#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToGlonassNavigationMessage
///
#include "gen/RemoveModificationToGlonassNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToGlonassNavigationMessage::CmdName = "RemoveModificationToGlonassNavigationMessage";
    const char* const RemoveModificationToGlonassNavigationMessage::Documentation = "Please note the command RemoveModificationToGlonassNavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves an event added with SetModificationToGlonassNavigationMessage. When adding an event, the simulator\nsets the Id parameter. Use that Id here to remove the associated event.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToGlonassNavigationMessage);


    RemoveModificationToGlonassNavigationMessage::RemoveModificationToGlonassNavigationMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToGlonassNavigationMessage::RemoveModificationToGlonassNavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToGlonassNavigationMessagePtr RemoveModificationToGlonassNavigationMessage::create(const std::string& id)
    {
      return RemoveModificationToGlonassNavigationMessagePtr(new RemoveModificationToGlonassNavigationMessage(id));
    }

    RemoveModificationToGlonassNavigationMessagePtr RemoveModificationToGlonassNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToGlonassNavigationMessage>(ptr);
    }

    bool RemoveModificationToGlonassNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToGlonassNavigationMessage::documentation() const { return Documentation; }


    int RemoveModificationToGlonassNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToGlonassNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToGlonassNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
