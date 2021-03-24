#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalForEachPrn
///
#include "gen/EnableSignalForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalForEachPrn::CmdName = "EnableSignalForEachPrn";
    const char* const EnableSignalForEachPrn::Documentation = "Please note the command EnableSignalForEachPrn is deprecated since 21.3. You may use EnableSignalForEachSV.\n\nEnable (or disable) signal for each satellite individually.\nAllowed signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1M\", \"L2C\", \"L2P\", \"L2M\", \"L5\",\n                     \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\",\n                     \"SBASL1\", \"QZSSL1CA\", \"QZSSL1C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\",\n                     \"NAVICL5\"";

    REGISTER_COMMAND_FACTORY(EnableSignalForEachPrn);


    EnableSignalForEachPrn::EnableSignalForEachPrn()
      : CommandBase(CmdName)
    {}

    EnableSignalForEachPrn::EnableSignalForEachPrn(const std::string& signal, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    EnableSignalForEachPrnPtr EnableSignalForEachPrn::create(const std::string& signal, const std::vector<bool>& enabled)
    {
      return EnableSignalForEachPrnPtr(new EnableSignalForEachPrn(signal, enabled));
    }

    EnableSignalForEachPrnPtr EnableSignalForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSignalForEachPrn>(ptr);
    }

    bool EnableSignalForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSignalForEachPrn::documentation() const { return Documentation; }


    int EnableSignalForEachPrn::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableSignalForEachPrn::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnableSignalForEachPrn::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnableSignalForEachPrn::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableSignalForEachPrn::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
