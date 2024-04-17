
#include "gen/EnableSignalPVT.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalPVT
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalPVT::CmdName = "EnableSignalPVT";
    const char* const EnableSignalPVT::Documentation = "Use a signal for PVT.";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSignalPVT);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSignalPVT);


    EnableSignalPVT::EnableSignalPVT()
      : CommandBase(CmdName)
    {}

    EnableSignalPVT::EnableSignalPVT(const std::string& signal, bool enabled)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    EnableSignalPVTPtr EnableSignalPVT::create(const std::string& signal, bool enabled)
    {
      return std::make_shared<EnableSignalPVT>(signal, enabled);
    }

    EnableSignalPVTPtr EnableSignalPVT::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSignalPVT>(ptr);
    }

    bool EnableSignalPVT::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSignalPVT::documentation() const { return Documentation; }


    int EnableSignalPVT::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableSignalPVT::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnableSignalPVT::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSignalPVT::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSignalPVT::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
