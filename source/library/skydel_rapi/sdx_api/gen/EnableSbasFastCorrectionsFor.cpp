#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSbasFastCorrectionsFor
///
#include "gen/EnableSbasFastCorrectionsFor.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSbasFastCorrectionsFor::CmdName = "EnableSbasFastCorrectionsFor";
    const char* const EnableSbasFastCorrectionsFor::Documentation = "Set whether pseudorange errors for this constellation should be compensated in SBAS fast corrections";

    REGISTER_COMMAND_FACTORY(EnableSbasFastCorrectionsFor);


    EnableSbasFastCorrectionsFor::EnableSbasFastCorrectionsFor()
      : CommandBase(CmdName)
    {}

    EnableSbasFastCorrectionsFor::EnableSbasFastCorrectionsFor(const std::string& system, bool isEnabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
    }


    EnableSbasFastCorrectionsForPtr EnableSbasFastCorrectionsFor::create(const std::string& system, bool isEnabled)
    {
      return EnableSbasFastCorrectionsForPtr(new EnableSbasFastCorrectionsFor(system, isEnabled));
    }

    EnableSbasFastCorrectionsForPtr EnableSbasFastCorrectionsFor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSbasFastCorrectionsFor>(ptr);
    }

    bool EnableSbasFastCorrectionsFor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string EnableSbasFastCorrectionsFor::documentation() const { return Documentation; }


    int EnableSbasFastCorrectionsFor::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableSbasFastCorrectionsFor::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableSbasFastCorrectionsFor::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSbasFastCorrectionsFor::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void EnableSbasFastCorrectionsFor::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
