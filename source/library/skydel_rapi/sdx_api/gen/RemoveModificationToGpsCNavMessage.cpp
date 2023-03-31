#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToGpsCNavMessage
///
#include "gen/RemoveModificationToGpsCNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToGpsCNavMessage::CmdName = "RemoveModificationToGpsCNavMessage";
    const char* const RemoveModificationToGpsCNavMessage::Documentation = "Please note the command RemoveModificationToGpsCNavMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves a modification.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToGpsCNavMessage);


    RemoveModificationToGpsCNavMessage::RemoveModificationToGpsCNavMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToGpsCNavMessage::RemoveModificationToGpsCNavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToGpsCNavMessagePtr RemoveModificationToGpsCNavMessage::create(const std::string& id)
    {
      return RemoveModificationToGpsCNavMessagePtr(new RemoveModificationToGpsCNavMessage(id));
    }

    RemoveModificationToGpsCNavMessagePtr RemoveModificationToGpsCNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToGpsCNavMessage>(ptr);
    }

    bool RemoveModificationToGpsCNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToGpsCNavMessage::documentation() const { return Documentation; }


    int RemoveModificationToGpsCNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToGpsCNavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToGpsCNavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
