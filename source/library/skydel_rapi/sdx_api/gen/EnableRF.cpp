#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableRF
///
#include "gen/EnableRF.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableRF::CmdName = "EnableRF";
    const char* const EnableRF::Documentation = "Please note the command EnableRF is deprecated since 21.3. You may use EnableRFOutputForSV.\n\nEnable (or disable) RF output for specified satellite PRN. Use PRN 0 to enabled/disable all satellites.";

    REGISTER_COMMAND_FACTORY(EnableRF);


    EnableRF::EnableRF()
      : CommandBase(CmdName)
    {}

    EnableRF::EnableRF(const std::string& system, int prn, bool enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setEnabled(enabled);
    }


    EnableRFPtr EnableRF::create(const std::string& system, int prn, bool enabled)
    {
      return EnableRFPtr(new EnableRF(system, prn, enabled));
    }

    EnableRFPtr EnableRF::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableRF>(ptr);
    }

    bool EnableRF::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableRF::documentation() const { return Documentation; }


    int EnableRF::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableRF::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableRF::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnableRF::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void EnableRF::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableRF::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableRF::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
