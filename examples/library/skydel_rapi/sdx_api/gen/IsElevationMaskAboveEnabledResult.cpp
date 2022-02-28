#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsElevationMaskAboveEnabledResult
///
#include "gen/IsElevationMaskAboveEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsElevationMaskAboveEnabledResult::CmdName = "IsElevationMaskAboveEnabledResult";
    const char* const IsElevationMaskAboveEnabledResult::Documentation = "Result of IsElevationMaskAboveEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsElevationMaskAboveEnabledResult);


    IsElevationMaskAboveEnabledResult::IsElevationMaskAboveEnabledResult()
      : CommandResult(CmdName)
    {}

    IsElevationMaskAboveEnabledResult::IsElevationMaskAboveEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsElevationMaskAboveEnabledResultPtr IsElevationMaskAboveEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return IsElevationMaskAboveEnabledResultPtr(new IsElevationMaskAboveEnabledResult(relatedCommand, enabled));
    }

    IsElevationMaskAboveEnabledResultPtr IsElevationMaskAboveEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsElevationMaskAboveEnabledResult>(ptr);
    }

    bool IsElevationMaskAboveEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsElevationMaskAboveEnabledResult::documentation() const { return Documentation; }


    bool IsElevationMaskAboveEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsElevationMaskAboveEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
