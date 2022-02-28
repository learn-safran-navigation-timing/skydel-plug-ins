#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsElevationMaskBelowEnabledResult
///
#include "gen/IsElevationMaskBelowEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsElevationMaskBelowEnabledResult::CmdName = "IsElevationMaskBelowEnabledResult";
    const char* const IsElevationMaskBelowEnabledResult::Documentation = "Result of IsElevationMaskBelowEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsElevationMaskBelowEnabledResult);


    IsElevationMaskBelowEnabledResult::IsElevationMaskBelowEnabledResult()
      : CommandResult(CmdName)
    {}

    IsElevationMaskBelowEnabledResult::IsElevationMaskBelowEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsElevationMaskBelowEnabledResultPtr IsElevationMaskBelowEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsElevationMaskBelowEnabledResult>(relatedCommand, enabled);
    }

    IsElevationMaskBelowEnabledResultPtr IsElevationMaskBelowEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsElevationMaskBelowEnabledResult>(ptr);
    }

    bool IsElevationMaskBelowEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsElevationMaskBelowEnabledResult::documentation() const { return Documentation; }


    bool IsElevationMaskBelowEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsElevationMaskBelowEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
