#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToGpsMNavMessage
///
#include "gen/RemoveModificationToGpsMNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToGpsMNavMessage::CmdName = "RemoveModificationToGpsMNavMessage";
    const char* const RemoveModificationToGpsMNavMessage::Documentation = "Please note the command RemoveModificationToGpsMNavMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves a modification.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToGpsMNavMessage);


    RemoveModificationToGpsMNavMessage::RemoveModificationToGpsMNavMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToGpsMNavMessage::RemoveModificationToGpsMNavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToGpsMNavMessagePtr RemoveModificationToGpsMNavMessage::create(const std::string& id)
    {
      return RemoveModificationToGpsMNavMessagePtr(new RemoveModificationToGpsMNavMessage(id));
    }

    RemoveModificationToGpsMNavMessagePtr RemoveModificationToGpsMNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToGpsMNavMessage>(ptr);
    }

    bool RemoveModificationToGpsMNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToGpsMNavMessage::documentation() const { return Documentation; }


    int RemoveModificationToGpsMNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToGpsMNavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToGpsMNavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
