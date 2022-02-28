#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsDelayAppliedInSbasResult
///
#include "gen/IsDelayAppliedInSbasResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsDelayAppliedInSbasResult::CmdName = "IsDelayAppliedInSbasResult";
    const char* const IsDelayAppliedInSbasResult::Documentation = "Result of IsDelayAppliedInSbas.";

    REGISTER_COMMAND_RESULT_FACTORY(IsDelayAppliedInSbasResult);


    IsDelayAppliedInSbasResult::IsDelayAppliedInSbasResult()
      : CommandResult(CmdName)
    {}

    IsDelayAppliedInSbasResult::IsDelayAppliedInSbasResult(CommandBasePtr relatedCommand, bool isEnabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setIsEnabled(isEnabled);
    }


    IsDelayAppliedInSbasResultPtr IsDelayAppliedInSbasResult::create(CommandBasePtr relatedCommand, bool isEnabled)
    {
      return IsDelayAppliedInSbasResultPtr(new IsDelayAppliedInSbasResult(relatedCommand, isEnabled));
    }

    IsDelayAppliedInSbasResultPtr IsDelayAppliedInSbasResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsDelayAppliedInSbasResult>(ptr);
    }

    bool IsDelayAppliedInSbasResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string IsDelayAppliedInSbasResult::documentation() const { return Documentation; }


    bool IsDelayAppliedInSbasResult::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void IsDelayAppliedInSbasResult::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
