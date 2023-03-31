#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveModificationToGpsCNav2Message
///
#include "gen/RemoveModificationToGpsCNav2Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveModificationToGpsCNav2Message::CmdName = "RemoveModificationToGpsCNav2Message";
    const char* const RemoveModificationToGpsCNav2Message::Documentation = "Please note the command RemoveModificationToGpsCNav2Message is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.\n\nRemoves a modification.";

    REGISTER_COMMAND_FACTORY(RemoveModificationToGpsCNav2Message);


    RemoveModificationToGpsCNav2Message::RemoveModificationToGpsCNav2Message()
      : CommandBase(CmdName)
    {}

    RemoveModificationToGpsCNav2Message::RemoveModificationToGpsCNav2Message(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    RemoveModificationToGpsCNav2MessagePtr RemoveModificationToGpsCNav2Message::create(const std::string& id)
    {
      return RemoveModificationToGpsCNav2MessagePtr(new RemoveModificationToGpsCNav2Message(id));
    }

    RemoveModificationToGpsCNav2MessagePtr RemoveModificationToGpsCNav2Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveModificationToGpsCNav2Message>(ptr);
    }

    bool RemoveModificationToGpsCNav2Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveModificationToGpsCNav2Message::documentation() const { return Documentation; }


    int RemoveModificationToGpsCNav2Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveModificationToGpsCNav2Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveModificationToGpsCNav2Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
