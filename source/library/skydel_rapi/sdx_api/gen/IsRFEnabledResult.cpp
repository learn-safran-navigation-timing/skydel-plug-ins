#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsRFEnabledResult
///
#include "gen/IsRFEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsRFEnabledResult::CmdName = "IsRFEnabledResult";
    const char* const IsRFEnabledResult::Documentation = "Result of IsRFEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsRFEnabledResult);


    IsRFEnabledResult::IsRFEnabledResult()
      : CommandResult(CmdName)
    {}

    IsRFEnabledResult::IsRFEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setEnabled(enabled);
    }


    IsRFEnabledResultPtr IsRFEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled)
    {
      return IsRFEnabledResultPtr(new IsRFEnabledResult(relatedCommand, system, prn, enabled));
    }

    IsRFEnabledResultPtr IsRFEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsRFEnabledResult>(ptr);
    }

    bool IsRFEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsRFEnabledResult::documentation() const { return Documentation; }


    std::string IsRFEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsRFEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsRFEnabledResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsRFEnabledResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsRFEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsRFEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
