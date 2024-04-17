
#include "gen/IsSignalTrackedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalTrackedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalTrackedResult::CmdName = "IsSignalTrackedResult";
    const char* const IsSignalTrackedResult::Documentation = "Result of IsSignalTracked.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalTrackedResult);


    IsSignalTrackedResult::IsSignalTrackedResult()
      : CommandResult(CmdName)
    {}

    IsSignalTrackedResult::IsSignalTrackedResult(const std::string& signal, bool enabled)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    IsSignalTrackedResult::IsSignalTrackedResult(CommandBasePtr relatedCommand, const std::string& signal, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    IsSignalTrackedResultPtr IsSignalTrackedResult::create(const std::string& signal, bool enabled)
    {
      return std::make_shared<IsSignalTrackedResult>(signal, enabled);
    }

    IsSignalTrackedResultPtr IsSignalTrackedResult::create(CommandBasePtr relatedCommand, const std::string& signal, bool enabled)
    {
      return std::make_shared<IsSignalTrackedResult>(relatedCommand, signal, enabled);
    }

    IsSignalTrackedResultPtr IsSignalTrackedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalTrackedResult>(ptr);
    }

    bool IsSignalTrackedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSignalTrackedResult::documentation() const { return Documentation; }


    std::string IsSignalTrackedResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalTrackedResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSignalTrackedResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSignalTrackedResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
