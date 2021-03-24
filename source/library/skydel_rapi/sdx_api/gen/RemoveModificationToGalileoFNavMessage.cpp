#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToGalileoFNavMessage
///
#include "gen/RemoveModificationToGalileoFNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToGalileoFNavMessage::CmdName = "RemoveModificationToGalileoFNavMessage";
    const char* const RemoveModificationToGalileoFNavMessage::Documentation = "Please note the command RemoveModificationToGalileoFNavMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves a modification.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToGalileoFNavMessage);


    RemoveModificationToGalileoFNavMessage::RemoveModificationToGalileoFNavMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToGalileoFNavMessage::RemoveModificationToGalileoFNavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToGalileoFNavMessagePtr RemoveModificationToGalileoFNavMessage::create(const std::string& id)
    {
      return RemoveModificationToGalileoFNavMessagePtr(new RemoveModificationToGalileoFNavMessage(id));
    }

    RemoveModificationToGalileoFNavMessagePtr RemoveModificationToGalileoFNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToGalileoFNavMessage>(ptr);
    }

    bool RemoveModificationToGalileoFNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToGalileoFNavMessage::documentation() const { return Documentation; }


    int RemoveModificationToGalileoFNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToGalileoFNavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToGalileoFNavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
