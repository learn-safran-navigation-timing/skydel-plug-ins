#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabled
///
#include "gen/IsSignalEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabled::CmdName = "IsSignalEnabled";
    const char* const IsSignalEnabled::Documentation = "Please note the command IsSignalEnabled is deprecated since 21.3. You may use IsSignalEnabledForSV.\n\nTells if the signal is enabled or disabled. See IsSignalEnabled description for allowed signals.";

    REGISTER_COMMAND_FACTORY(IsSignalEnabled);


    IsSignalEnabled::IsSignalEnabled()
      : CommandBase(CmdName)
    {}

    IsSignalEnabled::IsSignalEnabled(int prn, const std::string& signal)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSignal(signal);
    }


    IsSignalEnabledPtr IsSignalEnabled::create(int prn, const std::string& signal)
    {
      return IsSignalEnabledPtr(new IsSignalEnabled(prn, signal));
    }

    IsSignalEnabledPtr IsSignalEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabled>(ptr);
    }

    bool IsSignalEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsSignalEnabled::documentation() const { return Documentation; }


    int IsSignalEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsSignalEnabled::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsSignalEnabled::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsSignalEnabled::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabled::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
