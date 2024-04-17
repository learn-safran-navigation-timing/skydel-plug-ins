
#include "gen/IsNmeaMessageEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsNmeaMessageEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsNmeaMessageEnabledResult::CmdName = "IsNmeaMessageEnabledResult";
    const char* const IsNmeaMessageEnabledResult::Documentation = "Result of IsNmeaMessageEnabled.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsNmeaMessageEnabledResult);


    IsNmeaMessageEnabledResult::IsNmeaMessageEnabledResult()
      : CommandResult(CmdName)
    {}

    IsNmeaMessageEnabledResult::IsNmeaMessageEnabledResult(const std::string& message, bool enabled)
      : CommandResult(CmdName)
    {

      setMessage(message);
      setEnabled(enabled);
    }

    IsNmeaMessageEnabledResult::IsNmeaMessageEnabledResult(CommandBasePtr relatedCommand, const std::string& message, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setMessage(message);
      setEnabled(enabled);
    }


    IsNmeaMessageEnabledResultPtr IsNmeaMessageEnabledResult::create(const std::string& message, bool enabled)
    {
      return std::make_shared<IsNmeaMessageEnabledResult>(message, enabled);
    }

    IsNmeaMessageEnabledResultPtr IsNmeaMessageEnabledResult::create(CommandBasePtr relatedCommand, const std::string& message, bool enabled)
    {
      return std::make_shared<IsNmeaMessageEnabledResult>(relatedCommand, message, enabled);
    }

    IsNmeaMessageEnabledResultPtr IsNmeaMessageEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsNmeaMessageEnabledResult>(ptr);
    }

    bool IsNmeaMessageEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Message"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsNmeaMessageEnabledResult::documentation() const { return Documentation; }


    std::string IsNmeaMessageEnabledResult::message() const
    {
      return parse_json<std::string>::parse(m_values["Message"]);
    }

    void IsNmeaMessageEnabledResult::setMessage(const std::string& message)
    {
      m_values.AddMember("Message", parse_json<std::string>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsNmeaMessageEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsNmeaMessageEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
