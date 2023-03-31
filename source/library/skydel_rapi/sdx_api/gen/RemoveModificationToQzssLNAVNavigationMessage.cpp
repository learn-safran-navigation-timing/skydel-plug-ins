#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToQzssLNAVNavigationMessage
///
#include "gen/RemoveModificationToQzssLNAVNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToQzssLNAVNavigationMessage::CmdName = "RemoveModificationToQzssLNAVNavigationMessage";
    const char* const RemoveModificationToQzssLNAVNavigationMessage::Documentation = "Please note the command RemoveModificationToQzssLNAVNavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves an event added with SetModificationToQzssLNAVNavigationMessage. When adding an event, the simulator\nsets the Id parameter. Use that Id here to remove the associated event.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToQzssLNAVNavigationMessage);


    RemoveModificationToQzssLNAVNavigationMessage::RemoveModificationToQzssLNAVNavigationMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToQzssLNAVNavigationMessage::RemoveModificationToQzssLNAVNavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToQzssLNAVNavigationMessagePtr RemoveModificationToQzssLNAVNavigationMessage::create(const std::string& id)
    {
      return RemoveModificationToQzssLNAVNavigationMessagePtr(new RemoveModificationToQzssLNAVNavigationMessage(id));
    }

    RemoveModificationToQzssLNAVNavigationMessagePtr RemoveModificationToQzssLNAVNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToQzssLNAVNavigationMessage>(ptr);
    }

    bool RemoveModificationToQzssLNAVNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToQzssLNAVNavigationMessage::documentation() const { return Documentation; }


    int RemoveModificationToQzssLNAVNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToQzssLNAVNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToQzssLNAVNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
