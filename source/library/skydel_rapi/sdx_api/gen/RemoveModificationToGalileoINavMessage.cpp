#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToGalileoINavMessage
///
#include "gen/RemoveModificationToGalileoINavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToGalileoINavMessage::CmdName = "RemoveModificationToGalileoINavMessage";
    const char* const RemoveModificationToGalileoINavMessage::Documentation = "Please note the command RemoveModificationToGalileoINavMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves a modification.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToGalileoINavMessage);


    RemoveModificationToGalileoINavMessage::RemoveModificationToGalileoINavMessage()
      : CommandBase(CmdName)
    {}

    RemoveModificationToGalileoINavMessage::RemoveModificationToGalileoINavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToGalileoINavMessagePtr RemoveModificationToGalileoINavMessage::create(const std::string& id)
    {
      return RemoveModificationToGalileoINavMessagePtr(new RemoveModificationToGalileoINavMessage(id));
    }

    RemoveModificationToGalileoINavMessagePtr RemoveModificationToGalileoINavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToGalileoINavMessage>(ptr);
    }

    bool RemoveModificationToGalileoINavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToGalileoINavMessage::documentation() const { return Documentation; }


    int RemoveModificationToGalileoINavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToGalileoINavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToGalileoINavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
