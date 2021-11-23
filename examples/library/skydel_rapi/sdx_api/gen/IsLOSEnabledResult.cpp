#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLOSEnabledResult
///
#include "gen/IsLOSEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLOSEnabledResult::CmdName = "IsLOSEnabledResult";
    const char* const IsLOSEnabledResult::Documentation = "Result of IsLOSEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsLOSEnabledResult);


    IsLOSEnabledResult::IsLOSEnabledResult()
      : CommandResult(CmdName)
    {}

    IsLOSEnabledResult::IsLOSEnabledResult(CommandBasePtr relatedCommand, int prn, const std::string& system, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setSystem(system);
      setEnabled(enabled);
    }


    IsLOSEnabledResultPtr IsLOSEnabledResult::create(CommandBasePtr relatedCommand, int prn, const std::string& system, bool enabled)
    {
      return IsLOSEnabledResultPtr(new IsLOSEnabledResult(relatedCommand, prn, system, enabled));
    }

    IsLOSEnabledResultPtr IsLOSEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLOSEnabledResult>(ptr);
    }

    bool IsLOSEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLOSEnabledResult::documentation() const { return Documentation; }


    int IsLOSEnabledResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsLOSEnabledResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsLOSEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLOSEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsLOSEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLOSEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
