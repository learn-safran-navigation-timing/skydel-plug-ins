#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIonoOffsetEnabledResult
///
#include "gen/IsIonoOffsetEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIonoOffsetEnabledResult::CmdName = "IsIonoOffsetEnabledResult";
    const char* const IsIonoOffsetEnabledResult::Documentation = "Result of IsIonoOffsetEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsIonoOffsetEnabledResult);


    IsIonoOffsetEnabledResult::IsIonoOffsetEnabledResult()
      : CommandResult(CmdName)
    {}

    IsIonoOffsetEnabledResult::IsIonoOffsetEnabledResult(CommandBasePtr relatedCommand, bool isEnabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setIsEnabled(isEnabled);
    }


    IsIonoOffsetEnabledResultPtr IsIonoOffsetEnabledResult::create(CommandBasePtr relatedCommand, bool isEnabled)
    {
      return std::make_shared<IsIonoOffsetEnabledResult>(relatedCommand, isEnabled);
    }

    IsIonoOffsetEnabledResultPtr IsIonoOffsetEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIonoOffsetEnabledResult>(ptr);
    }

    bool IsIonoOffsetEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string IsIonoOffsetEnabledResult::documentation() const { return Documentation; }


    bool IsIonoOffsetEnabledResult::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void IsIonoOffsetEnabledResult::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
