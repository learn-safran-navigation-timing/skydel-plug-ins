
#include "gen/EnableNmeaMessage.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableNmeaMessage
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableNmeaMessage::CmdName = "EnableNmeaMessage";
    const char* const EnableNmeaMessage::Documentation = "Enable (or disable) the NMEA message.";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableNmeaMessage);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableNmeaMessage);


    EnableNmeaMessage::EnableNmeaMessage()
      : CommandBase(CmdName)
    {}

    EnableNmeaMessage::EnableNmeaMessage(const std::string& message, bool enabled)
      : CommandBase(CmdName)
    {

      setMessage(message);
      setEnabled(enabled);
    }

    EnableNmeaMessagePtr EnableNmeaMessage::create(const std::string& message, bool enabled)
    {
      return std::make_shared<EnableNmeaMessage>(message, enabled);
    }

    EnableNmeaMessagePtr EnableNmeaMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableNmeaMessage>(ptr);
    }

    bool EnableNmeaMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Message"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableNmeaMessage::documentation() const { return Documentation; }


    int EnableNmeaMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableNmeaMessage::message() const
    {
      return parse_json<std::string>::parse(m_values["Message"]);
    }

    void EnableNmeaMessage::setMessage(const std::string& message)
    {
      m_values.AddMember("Message", parse_json<std::string>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableNmeaMessage::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableNmeaMessage::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
