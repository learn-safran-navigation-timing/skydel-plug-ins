
#include "gen/IsSignalPVTEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalPVTEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalPVTEnabled::CmdName = "IsSignalPVTEnabled";
    const char* const IsSignalPVTEnabled::Documentation = "Tells if the specified signal is used for PVT.";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSignalPVTEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalPVTEnabled);


    IsSignalPVTEnabled::IsSignalPVTEnabled()
      : CommandBase(CmdName)
    {}

    IsSignalPVTEnabled::IsSignalPVTEnabled(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    IsSignalPVTEnabledPtr IsSignalPVTEnabled::create(const std::string& signal)
    {
      return std::make_shared<IsSignalPVTEnabled>(signal);
    }

    IsSignalPVTEnabledPtr IsSignalPVTEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalPVTEnabled>(ptr);
    }

    bool IsSignalPVTEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsSignalPVTEnabled::documentation() const { return Documentation; }


    int IsSignalPVTEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSignalPVTEnabled::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalPVTEnabled::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
