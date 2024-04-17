
#include "gen/IsSignalPVTEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalPVTEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalPVTEnabledResult::CmdName = "IsSignalPVTEnabledResult";
    const char* const IsSignalPVTEnabledResult::Documentation = "Result of IsSignalPVTEnabled.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalPVTEnabledResult);


    IsSignalPVTEnabledResult::IsSignalPVTEnabledResult()
      : CommandResult(CmdName)
    {}

    IsSignalPVTEnabledResult::IsSignalPVTEnabledResult(const std::string& signal, bool enabled)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    IsSignalPVTEnabledResult::IsSignalPVTEnabledResult(CommandBasePtr relatedCommand, const std::string& signal, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    IsSignalPVTEnabledResultPtr IsSignalPVTEnabledResult::create(const std::string& signal, bool enabled)
    {
      return std::make_shared<IsSignalPVTEnabledResult>(signal, enabled);
    }

    IsSignalPVTEnabledResultPtr IsSignalPVTEnabledResult::create(CommandBasePtr relatedCommand, const std::string& signal, bool enabled)
    {
      return std::make_shared<IsSignalPVTEnabledResult>(relatedCommand, signal, enabled);
    }

    IsSignalPVTEnabledResultPtr IsSignalPVTEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalPVTEnabledResult>(ptr);
    }

    bool IsSignalPVTEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSignalPVTEnabledResult::documentation() const { return Documentation; }


    std::string IsSignalPVTEnabledResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalPVTEnabledResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSignalPVTEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSignalPVTEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
