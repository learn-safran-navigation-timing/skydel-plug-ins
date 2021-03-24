#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasFastCorrectionsEnabledFor
///
#include "gen/IsSbasFastCorrectionsEnabledFor.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasFastCorrectionsEnabledFor::CmdName = "IsSbasFastCorrectionsEnabledFor";
    const char* const IsSbasFastCorrectionsEnabledFor::Documentation = "Get whether pseudorange errors for this constellation should be compensated in SBAS fast corrections";

    REGISTER_COMMAND_FACTORY(IsSbasFastCorrectionsEnabledFor);


    IsSbasFastCorrectionsEnabledFor::IsSbasFastCorrectionsEnabledFor()
      : CommandBase(CmdName)
    {}

    IsSbasFastCorrectionsEnabledFor::IsSbasFastCorrectionsEnabledFor(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }


    IsSbasFastCorrectionsEnabledForPtr IsSbasFastCorrectionsEnabledFor::create(const std::string& system)
    {
      return IsSbasFastCorrectionsEnabledForPtr(new IsSbasFastCorrectionsEnabledFor(system));
    }

    IsSbasFastCorrectionsEnabledForPtr IsSbasFastCorrectionsEnabledFor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasFastCorrectionsEnabledFor>(ptr);
    }

    bool IsSbasFastCorrectionsEnabledFor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsSbasFastCorrectionsEnabledFor::documentation() const { return Documentation; }


    int IsSbasFastCorrectionsEnabledFor::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSbasFastCorrectionsEnabledFor::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSbasFastCorrectionsEnabledFor::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
