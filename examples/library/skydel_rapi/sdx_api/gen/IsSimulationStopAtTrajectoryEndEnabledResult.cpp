#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSimulationStopAtTrajectoryEndEnabledResult
///
#include "gen/IsSimulationStopAtTrajectoryEndEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSimulationStopAtTrajectoryEndEnabledResult::CmdName = "IsSimulationStopAtTrajectoryEndEnabledResult";
    const char* const IsSimulationStopAtTrajectoryEndEnabledResult::Documentation = "Result of IsSimulationStopAtTrajectoryEndEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsSimulationStopAtTrajectoryEndEnabledResult);


    IsSimulationStopAtTrajectoryEndEnabledResult::IsSimulationStopAtTrajectoryEndEnabledResult()
      : CommandResult(CmdName)
    {}

    IsSimulationStopAtTrajectoryEndEnabledResult::IsSimulationStopAtTrajectoryEndEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsSimulationStopAtTrajectoryEndEnabledResultPtr IsSimulationStopAtTrajectoryEndEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return IsSimulationStopAtTrajectoryEndEnabledResultPtr(new IsSimulationStopAtTrajectoryEndEnabledResult(relatedCommand, enabled));
    }

    IsSimulationStopAtTrajectoryEndEnabledResultPtr IsSimulationStopAtTrajectoryEndEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSimulationStopAtTrajectoryEndEnabledResult>(ptr);
    }

    bool IsSimulationStopAtTrajectoryEndEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSimulationStopAtTrajectoryEndEnabledResult::documentation() const { return Documentation; }


    bool IsSimulationStopAtTrajectoryEndEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSimulationStopAtTrajectoryEndEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
