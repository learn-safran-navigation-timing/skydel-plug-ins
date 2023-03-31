#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledResult
///
#include "gen/IsSignalEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledResult::CmdName = "IsSignalEnabledResult";
    const char* const IsSignalEnabledResult::Documentation = "Result of IsSignalEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsSignalEnabledResult);


    IsSignalEnabledResult::IsSignalEnabledResult()
      : CommandResult(CmdName)
    {}

    IsSignalEnabledResult::IsSignalEnabledResult(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setSignal(signal);
      setEnabled(enabled);
    }


    IsSignalEnabledResultPtr IsSignalEnabledResult::create(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled)
    {
      return IsSignalEnabledResultPtr(new IsSignalEnabledResult(relatedCommand, prn, signal, enabled));
    }

    IsSignalEnabledResultPtr IsSignalEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabledResult>(ptr);
    }

    bool IsSignalEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSignalEnabledResult::documentation() const { return Documentation; }


    int IsSignalEnabledResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsSignalEnabledResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsSignalEnabledResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabledResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSignalEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSignalEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
