#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasFastCorrectionsEnabledForResult
///
#include "gen/IsSbasFastCorrectionsEnabledForResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasFastCorrectionsEnabledForResult::CmdName = "IsSbasFastCorrectionsEnabledForResult";
    const char* const IsSbasFastCorrectionsEnabledForResult::Documentation = "Result of IsSbasFastCorrectionsEnabledFor.";

    REGISTER_COMMAND_RESULT_FACTORY(IsSbasFastCorrectionsEnabledForResult);


    IsSbasFastCorrectionsEnabledForResult::IsSbasFastCorrectionsEnabledForResult()
      : CommandResult(CmdName)
    {}

    IsSbasFastCorrectionsEnabledForResult::IsSbasFastCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
    }


    IsSbasFastCorrectionsEnabledForResultPtr IsSbasFastCorrectionsEnabledForResult::create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled)
    {
      return IsSbasFastCorrectionsEnabledForResultPtr(new IsSbasFastCorrectionsEnabledForResult(relatedCommand, system, isEnabled));
    }

    IsSbasFastCorrectionsEnabledForResultPtr IsSbasFastCorrectionsEnabledForResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasFastCorrectionsEnabledForResult>(ptr);
    }

    bool IsSbasFastCorrectionsEnabledForResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string IsSbasFastCorrectionsEnabledForResult::documentation() const { return Documentation; }


    std::string IsSbasFastCorrectionsEnabledForResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSbasFastCorrectionsEnabledForResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSbasFastCorrectionsEnabledForResult::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void IsSbasFastCorrectionsEnabledForResult::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
