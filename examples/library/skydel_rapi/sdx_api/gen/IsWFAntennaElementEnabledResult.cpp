#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsWFAntennaElementEnabledResult
///
#include "gen/IsWFAntennaElementEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsWFAntennaElementEnabledResult::CmdName = "IsWFAntennaElementEnabledResult";
    const char* const IsWFAntennaElementEnabledResult::Documentation = "Result of IsWFAntennaElementEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsWFAntennaElementEnabledResult);


    IsWFAntennaElementEnabledResult::IsWFAntennaElementEnabledResult()
      : CommandResult(CmdName)
    {}

    IsWFAntennaElementEnabledResult::IsWFAntennaElementEnabledResult(CommandBasePtr relatedCommand, int element, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setElement(element);
      setEnabled(enabled);
    }


    IsWFAntennaElementEnabledResultPtr IsWFAntennaElementEnabledResult::create(CommandBasePtr relatedCommand, int element, bool enabled)
    {
      return IsWFAntennaElementEnabledResultPtr(new IsWFAntennaElementEnabledResult(relatedCommand, element, enabled));
    }

    IsWFAntennaElementEnabledResultPtr IsWFAntennaElementEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsWFAntennaElementEnabledResult>(ptr);
    }

    bool IsWFAntennaElementEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsWFAntennaElementEnabledResult::documentation() const { return Documentation; }


    int IsWFAntennaElementEnabledResult::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void IsWFAntennaElementEnabledResult::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsWFAntennaElementEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsWFAntennaElementEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
