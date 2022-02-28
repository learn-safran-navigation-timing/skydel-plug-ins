#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPropagationDelayEnabledResult
///
#include "gen/IsPropagationDelayEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPropagationDelayEnabledResult::CmdName = "IsPropagationDelayEnabledResult";
    const char* const IsPropagationDelayEnabledResult::Documentation = "Result of IsPropagationDelayEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsPropagationDelayEnabledResult);


    IsPropagationDelayEnabledResult::IsPropagationDelayEnabledResult()
      : CommandResult(CmdName)
    {}

    IsPropagationDelayEnabledResult::IsPropagationDelayEnabledResult(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsPropagationDelayEnabledResultPtr IsPropagationDelayEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
    {
      return IsPropagationDelayEnabledResultPtr(new IsPropagationDelayEnabledResult(relatedCommand, system, enabled));
    }

    IsPropagationDelayEnabledResultPtr IsPropagationDelayEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPropagationDelayEnabledResult>(ptr);
    }

    bool IsPropagationDelayEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPropagationDelayEnabledResult::documentation() const { return Documentation; }


    std::string IsPropagationDelayEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsPropagationDelayEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsPropagationDelayEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsPropagationDelayEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
