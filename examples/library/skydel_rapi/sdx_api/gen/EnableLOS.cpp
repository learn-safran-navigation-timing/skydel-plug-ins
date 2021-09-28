#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLOS
///
#include "gen/EnableLOS.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLOS::CmdName = "EnableLOS";
    const char* const EnableLOS::Documentation = "Please note the command EnableLOS is deprecated since 21.3. You may use EnableLosForSV.\n\nSet Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(EnableLOS);


    EnableLOS::EnableLOS()
      : CommandBase(CmdName)
    {}

    EnableLOS::EnableLOS(int prn, const std::string& system, bool enabled)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSystem(system);
      setEnabled(enabled);
    }


    EnableLOSPtr EnableLOS::create(int prn, const std::string& system, bool enabled)
    {
      return EnableLOSPtr(new EnableLOS(prn, system, enabled));
    }

    EnableLOSPtr EnableLOS::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLOS>(ptr);
    }

    bool EnableLOS::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLOS::documentation() const { return Documentation; }


    int EnableLOS::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int EnableLOS::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void EnableLOS::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableLOS::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableLOS::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableLOS::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLOS::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
