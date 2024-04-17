
#include "gen/EnableSignalTracking.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalTracking
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalTracking::CmdName = "EnableSignalTracking";
    const char* const EnableSignalTracking::Documentation = "Enable (or disable) the signal tracked by the receiver.";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSignalTracking);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSignalTracking);


    EnableSignalTracking::EnableSignalTracking()
      : CommandBase(CmdName)
    {}

    EnableSignalTracking::EnableSignalTracking(const std::string& signal, bool enabled)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    EnableSignalTrackingPtr EnableSignalTracking::create(const std::string& signal, bool enabled)
    {
      return std::make_shared<EnableSignalTracking>(signal, enabled);
    }

    EnableSignalTrackingPtr EnableSignalTracking::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSignalTracking>(ptr);
    }

    bool EnableSignalTracking::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSignalTracking::documentation() const { return Documentation; }


    int EnableSignalTracking::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableSignalTracking::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnableSignalTracking::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSignalTracking::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSignalTracking::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
