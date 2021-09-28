#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLOSEnabledForEachPrnResult
///
#include "gen/IsLOSEnabledForEachPrnResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLOSEnabledForEachPrnResult::CmdName = "IsLOSEnabledForEachPrnResult";
    const char* const IsLOSEnabledForEachPrnResult::Documentation = "Result of IsLOSEnabledForEachPrn.";

    REGISTER_COMMAND_RESULT_FACTORY(IsLOSEnabledForEachPrnResult);


    IsLOSEnabledForEachPrnResult::IsLOSEnabledForEachPrnResult()
      : CommandResult(CmdName)
    {}

    IsLOSEnabledForEachPrnResult::IsLOSEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsLOSEnabledForEachPrnResultPtr IsLOSEnabledForEachPrnResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
    {
      return IsLOSEnabledForEachPrnResultPtr(new IsLOSEnabledForEachPrnResult(relatedCommand, system, enabled));
    }

    IsLOSEnabledForEachPrnResultPtr IsLOSEnabledForEachPrnResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLOSEnabledForEachPrnResult>(ptr);
    }

    bool IsLOSEnabledForEachPrnResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLOSEnabledForEachPrnResult::documentation() const { return Documentation; }


    std::string IsLOSEnabledForEachPrnResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLOSEnabledForEachPrnResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> IsLOSEnabledForEachPrnResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsLOSEnabledForEachPrnResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
