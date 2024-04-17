
#include "gen/IsNmeaMessageEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsNmeaMessageEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsNmeaMessageEnabled::CmdName = "IsNmeaMessageEnabled";
    const char* const IsNmeaMessageEnabled::Documentation = "Tells if the specified NMEA message is enabled.";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsNmeaMessageEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsNmeaMessageEnabled);


    IsNmeaMessageEnabled::IsNmeaMessageEnabled()
      : CommandBase(CmdName)
    {}

    IsNmeaMessageEnabled::IsNmeaMessageEnabled(const std::string& message)
      : CommandBase(CmdName)
    {

      setMessage(message);
    }

    IsNmeaMessageEnabledPtr IsNmeaMessageEnabled::create(const std::string& message)
    {
      return std::make_shared<IsNmeaMessageEnabled>(message);
    }

    IsNmeaMessageEnabledPtr IsNmeaMessageEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsNmeaMessageEnabled>(ptr);
    }

    bool IsNmeaMessageEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Message"])
        ;

    }

    std::string IsNmeaMessageEnabled::documentation() const { return Documentation; }


    int IsNmeaMessageEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsNmeaMessageEnabled::message() const
    {
      return parse_json<std::string>::parse(m_values["Message"]);
    }

    void IsNmeaMessageEnabled::setMessage(const std::string& message)
    {
      m_values.AddMember("Message", parse_json<std::string>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
