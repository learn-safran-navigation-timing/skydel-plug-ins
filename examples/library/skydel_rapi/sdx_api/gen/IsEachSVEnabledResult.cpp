#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEachSVEnabledResult
///
#include "gen/IsEachSVEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEachSVEnabledResult::CmdName = "IsEachSVEnabledResult";
    const char* const IsEachSVEnabledResult::Documentation = "Result of IsEachSVEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsEachSVEnabledResult);


    IsEachSVEnabledResult::IsEachSVEnabledResult()
      : CommandResult(CmdName)
    {}

    IsEachSVEnabledResult::IsEachSVEnabledResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsEachSVEnabledResultPtr IsEachSVEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsEachSVEnabledResult>(relatedCommand, system, enabled);
    }

    IsEachSVEnabledResultPtr IsEachSVEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsEachSVEnabledResult>(ptr);
    }

    bool IsEachSVEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsEachSVEnabledResult::documentation() const { return Documentation; }


    std::string IsEachSVEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsEachSVEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> IsEachSVEnabledResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsEachSVEnabledResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
