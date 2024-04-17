
#include "gen/GetPVTSignalsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPVTSignalsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPVTSignalsResult::CmdName = "GetPVTSignalsResult";
    const char* const GetPVTSignalsResult::Documentation = "Result of GetPVTSignals.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPVTSignalsResult);


    GetPVTSignalsResult::GetPVTSignalsResult()
      : CommandResult(CmdName)
    {}

    GetPVTSignalsResult::GetPVTSignalsResult(const std::vector<std::string>& signals)
      : CommandResult(CmdName)
    {

      setSignals(signals);
    }

    GetPVTSignalsResult::GetPVTSignalsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signals)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignals(signals);
    }


    GetPVTSignalsResultPtr GetPVTSignalsResult::create(const std::vector<std::string>& signals)
    {
      return std::make_shared<GetPVTSignalsResult>(signals);
    }

    GetPVTSignalsResultPtr GetPVTSignalsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signals)
    {
      return std::make_shared<GetPVTSignalsResult>(relatedCommand, signals);
    }

    GetPVTSignalsResultPtr GetPVTSignalsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPVTSignalsResult>(ptr);
    }

    bool GetPVTSignalsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Signals"])
        ;

    }

    std::string GetPVTSignalsResult::documentation() const { return Documentation; }


    std::vector<std::string> GetPVTSignalsResult::signals() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Signals"]);
    }

    void GetPVTSignalsResult::setSignals(const std::vector<std::string>& signals)
    {
      m_values.AddMember("Signals", parse_json<std::vector<std::string>>::format(signals, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
