
#include "IsSignalStrengthModelEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalStrengthModelEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalStrengthModelEnabledResult::CmdName = "IsSignalStrengthModelEnabledResult";
    const char* const IsSignalStrengthModelEnabledResult::Documentation = "Result of IsSignalStrengthModelEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------------------\n"
      "Enabled bool If true, signal strengh model is enabled for all satellites";
    const char* const IsSignalStrengthModelEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalStrengthModelEnabledResult);


    IsSignalStrengthModelEnabledResult::IsSignalStrengthModelEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSignalStrengthModelEnabledResult::IsSignalStrengthModelEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsSignalStrengthModelEnabledResult::IsSignalStrengthModelEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsSignalStrengthModelEnabledResultPtr IsSignalStrengthModelEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsSignalStrengthModelEnabledResult>(enabled);
    }

    IsSignalStrengthModelEnabledResultPtr IsSignalStrengthModelEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsSignalStrengthModelEnabledResult>(relatedCommand, enabled);
    }

    IsSignalStrengthModelEnabledResultPtr IsSignalStrengthModelEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalStrengthModelEnabledResult>(ptr);
    }

    bool IsSignalStrengthModelEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSignalStrengthModelEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSignalStrengthModelEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsSignalStrengthModelEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSignalStrengthModelEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
