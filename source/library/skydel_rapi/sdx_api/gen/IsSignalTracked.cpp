
#include "gen/IsSignalTracked.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalTracked
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalTracked::CmdName = "IsSignalTracked";
    const char* const IsSignalTracked::Documentation = "Tells if the specified signal is tracked.";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSignalTracked);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalTracked);


    IsSignalTracked::IsSignalTracked()
      : CommandBase(CmdName)
    {}

    IsSignalTracked::IsSignalTracked(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    IsSignalTrackedPtr IsSignalTracked::create(const std::string& signal)
    {
      return std::make_shared<IsSignalTracked>(signal);
    }

    IsSignalTrackedPtr IsSignalTracked::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalTracked>(ptr);
    }

    bool IsSignalTracked::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsSignalTracked::documentation() const { return Documentation; }


    int IsSignalTracked::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSignalTracked::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalTracked::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
