#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpectrumVisibleResult
///
#include "gen/IsSpectrumVisibleResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpectrumVisibleResult::CmdName = "IsSpectrumVisibleResult";
    const char* const IsSpectrumVisibleResult::Documentation = "Result of IsSpectrumVisible.";

    REGISTER_COMMAND_RESULT_FACTORY(IsSpectrumVisibleResult);


    IsSpectrumVisibleResult::IsSpectrumVisibleResult()
      : CommandResult(CmdName)
    {}

    IsSpectrumVisibleResult::IsSpectrumVisibleResult(CommandBasePtr relatedCommand, bool visible)
      : CommandResult(CmdName, relatedCommand)
    {

      setVisible(visible);
    }


    IsSpectrumVisibleResultPtr IsSpectrumVisibleResult::create(CommandBasePtr relatedCommand, bool visible)
    {
      return IsSpectrumVisibleResultPtr(new IsSpectrumVisibleResult(relatedCommand, visible));
    }

    IsSpectrumVisibleResultPtr IsSpectrumVisibleResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpectrumVisibleResult>(ptr);
    }

    bool IsSpectrumVisibleResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Visible"])
        ;

    }

    std::string IsSpectrumVisibleResult::documentation() const { return Documentation; }


    bool IsSpectrumVisibleResult::visible() const
    {
      return parse_json<bool>::parse(m_values["Visible"]);
    }

    void IsSpectrumVisibleResult::setVisible(bool visible)
    {
      m_values.AddMember("Visible", parse_json<bool>::format(visible, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
