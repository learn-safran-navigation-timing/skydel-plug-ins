
#include "IsLogNmeaEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogNmeaEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogNmeaEnabledResult::CmdName = "IsLogNmeaEnabledResult";
    const char* const IsLogNmeaEnabledResult::Documentation = "Result of IsLogNmeaEnabled.\n"
      "\n"
      "Name              Type          Description\n"
      "----------------- ------------- -----------------------------------------------------------------------------\n"
      "Enabled           bool          If true, file(s) will be created during simulation\n"
      "SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.";
    const char* const IsLogNmeaEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogNmeaEnabledResult);


    IsLogNmeaEnabledResult::IsLogNmeaEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsLogNmeaEnabledResult::IsLogNmeaEnabledResult(bool enabled, const Sdx::optional<bool>& serialPortEnabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setSerialPortEnabled(serialPortEnabled);
    }

    IsLogNmeaEnabledResult::IsLogNmeaEnabledResult(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& serialPortEnabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setSerialPortEnabled(serialPortEnabled);
    }


    IsLogNmeaEnabledResultPtr IsLogNmeaEnabledResult::create(bool enabled, const Sdx::optional<bool>& serialPortEnabled)
    {
      return std::make_shared<IsLogNmeaEnabledResult>(enabled, serialPortEnabled);
    }

    IsLogNmeaEnabledResultPtr IsLogNmeaEnabledResult::create(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& serialPortEnabled)
    {
      return std::make_shared<IsLogNmeaEnabledResult>(relatedCommand, enabled, serialPortEnabled);
    }

    IsLogNmeaEnabledResultPtr IsLogNmeaEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogNmeaEnabledResult>(ptr);
    }

    bool IsLogNmeaEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["SerialPortEnabled"])
        ;

    }

    std::string IsLogNmeaEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsLogNmeaEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "SerialPortEnabled"}; 
      return names; 
    }


    bool IsLogNmeaEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLogNmeaEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> IsLogNmeaEnabledResult::serialPortEnabled() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["SerialPortEnabled"]);
    }

    void IsLogNmeaEnabledResult::setSerialPortEnabled(const Sdx::optional<bool>& serialPortEnabled)
    {
      m_values.AddMember("SerialPortEnabled", parse_json<Sdx::optional<bool>>::format(serialPortEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
