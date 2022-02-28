#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsRFOutputEnabledResult
///
#include "gen/IsRFOutputEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsRFOutputEnabledResult::CmdName = "IsRFOutputEnabledResult";
    const char* const IsRFOutputEnabledResult::Documentation = "Result of IsRFOutputEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsRFOutputEnabledResult);


    IsRFOutputEnabledResult::IsRFOutputEnabledResult()
      : CommandResult(CmdName)
    {}

    IsRFOutputEnabledResult::IsRFOutputEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }


    IsRFOutputEnabledResultPtr IsRFOutputEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
    {
      return IsRFOutputEnabledResultPtr(new IsRFOutputEnabledResult(relatedCommand, system, svId, enabled));
    }

    IsRFOutputEnabledResultPtr IsRFOutputEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsRFOutputEnabledResult>(ptr);
    }

    bool IsRFOutputEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsRFOutputEnabledResult::documentation() const { return Documentation; }


    std::string IsRFOutputEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsRFOutputEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsRFOutputEnabledResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsRFOutputEnabledResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsRFOutputEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsRFOutputEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
