#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignal
///
#include "gen/EnableSignal.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignal::CmdName = "EnableSignal";
    const char* const EnableSignal::Documentation = "Please note the command EnableSignal is deprecated since 21.3. You may use EnableSignalForSV.\n\nEnable (or disable) signal for specified satellite. Use PRN 0 to enabled/disable all satellites.\nQZSS uses SVID instead of PRN.\nAllowed signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1M\", \"L2C\", \"L2P\", \"L2M\", \"L5\",\n                     \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\",\n                     \"SBAS\", \"QZSSL1CA\", \"QZSSL1C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\",\n                     \"NAVICL5\"";

    REGISTER_COMMAND_FACTORY(EnableSignal);


    EnableSignal::EnableSignal()
      : CommandBase(CmdName)
    {}

    EnableSignal::EnableSignal(int prn, const std::string& signal, bool enabled)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSignal(signal);
      setEnabled(enabled);
    }


    EnableSignalPtr EnableSignal::create(int prn, const std::string& signal, bool enabled)
    {
      return EnableSignalPtr(new EnableSignal(prn, signal, enabled));
    }

    EnableSignalPtr EnableSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSignal>(ptr);
    }

    bool EnableSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSignal::documentation() const { return Documentation; }


    int EnableSignal::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int EnableSignal::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void EnableSignal::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnableSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSignal::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSignal::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
