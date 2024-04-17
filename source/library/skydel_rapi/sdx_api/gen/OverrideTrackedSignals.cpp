
#include "gen/OverrideTrackedSignals.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of OverrideTrackedSignals
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const OverrideTrackedSignals::CmdName = "OverrideTrackedSignals";
    const char* const OverrideTrackedSignals::Documentation = "Overrides the currently tracked signals.";

    REGISTER_COMMAND_TO_FACTORY_DECL(OverrideTrackedSignals);
    REGISTER_COMMAND_TO_FACTORY_IMPL(OverrideTrackedSignals);


    OverrideTrackedSignals::OverrideTrackedSignals()
      : CommandBase(CmdName)
    {}

    OverrideTrackedSignals::OverrideTrackedSignals(const std::vector<std::string>& signals)
      : CommandBase(CmdName)
    {

      setSignals(signals);
    }

    OverrideTrackedSignalsPtr OverrideTrackedSignals::create(const std::vector<std::string>& signals)
    {
      return std::make_shared<OverrideTrackedSignals>(signals);
    }

    OverrideTrackedSignalsPtr OverrideTrackedSignals::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<OverrideTrackedSignals>(ptr);
    }

    bool OverrideTrackedSignals::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Signals"])
        ;

    }

    std::string OverrideTrackedSignals::documentation() const { return Documentation; }


    int OverrideTrackedSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::string> OverrideTrackedSignals::signals() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Signals"]);
    }

    void OverrideTrackedSignals::setSignals(const std::vector<std::string>& signals)
    {
      m_values.AddMember("Signals", parse_json<std::vector<std::string>>::format(signals, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
