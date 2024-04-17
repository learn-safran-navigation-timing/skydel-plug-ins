
#include "gen/OverridePVTSignals.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of OverridePVTSignals
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const OverridePVTSignals::CmdName = "OverridePVTSignals";
    const char* const OverridePVTSignals::Documentation = "Overrides the signals currently used for PVT.";

    REGISTER_COMMAND_TO_FACTORY_DECL(OverridePVTSignals);
    REGISTER_COMMAND_TO_FACTORY_IMPL(OverridePVTSignals);


    OverridePVTSignals::OverridePVTSignals()
      : CommandBase(CmdName)
    {}

    OverridePVTSignals::OverridePVTSignals(const std::vector<std::string>& signals)
      : CommandBase(CmdName)
    {

      setSignals(signals);
    }

    OverridePVTSignalsPtr OverridePVTSignals::create(const std::vector<std::string>& signals)
    {
      return std::make_shared<OverridePVTSignals>(signals);
    }

    OverridePVTSignalsPtr OverridePVTSignals::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<OverridePVTSignals>(ptr);
    }

    bool OverridePVTSignals::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Signals"])
        ;

    }

    std::string OverridePVTSignals::documentation() const { return Documentation; }


    int OverridePVTSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::string> OverridePVTSignals::signals() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Signals"]);
    }

    void OverridePVTSignals::setSignals(const std::vector<std::string>& signals)
    {
      m_values.AddMember("Signals", parse_json<std::vector<std::string>>::format(signals, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
