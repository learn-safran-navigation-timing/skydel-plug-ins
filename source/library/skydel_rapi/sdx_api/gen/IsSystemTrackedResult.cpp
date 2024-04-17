
#include "gen/IsSystemTrackedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSystemTrackedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSystemTrackedResult::CmdName = "IsSystemTrackedResult";
    const char* const IsSystemTrackedResult::Documentation = "Result of IsSystemTracked.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSystemTrackedResult);


    IsSystemTrackedResult::IsSystemTrackedResult()
      : CommandResult(CmdName)
    {}

    IsSystemTrackedResult::IsSystemTrackedResult(const std::string& system, bool enabled)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    IsSystemTrackedResult::IsSystemTrackedResult(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsSystemTrackedResultPtr IsSystemTrackedResult::create(const std::string& system, bool enabled)
    {
      return std::make_shared<IsSystemTrackedResult>(system, enabled);
    }

    IsSystemTrackedResultPtr IsSystemTrackedResult::create(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
    {
      return std::make_shared<IsSystemTrackedResult>(relatedCommand, system, enabled);
    }

    IsSystemTrackedResultPtr IsSystemTrackedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSystemTrackedResult>(ptr);
    }

    bool IsSystemTrackedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSystemTrackedResult::documentation() const { return Documentation; }


    std::string IsSystemTrackedResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSystemTrackedResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSystemTrackedResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSystemTrackedResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
