
#include "gen/GetTrackingSignalsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTrackingSignalsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTrackingSignalsResult::CmdName = "GetTrackingSignalsResult";
    const char* const GetTrackingSignalsResult::Documentation = "Result of GetTrackingSignals.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTrackingSignalsResult);


    GetTrackingSignalsResult::GetTrackingSignalsResult()
      : CommandResult(CmdName)
    {}

    GetTrackingSignalsResult::GetTrackingSignalsResult(const std::vector<std::string>& signals)
      : CommandResult(CmdName)
    {

      setSignals(signals);
    }

    GetTrackingSignalsResult::GetTrackingSignalsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signals)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignals(signals);
    }


    GetTrackingSignalsResultPtr GetTrackingSignalsResult::create(const std::vector<std::string>& signals)
    {
      return std::make_shared<GetTrackingSignalsResult>(signals);
    }

    GetTrackingSignalsResultPtr GetTrackingSignalsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signals)
    {
      return std::make_shared<GetTrackingSignalsResult>(relatedCommand, signals);
    }

    GetTrackingSignalsResultPtr GetTrackingSignalsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTrackingSignalsResult>(ptr);
    }

    bool GetTrackingSignalsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Signals"])
        ;

    }

    std::string GetTrackingSignalsResult::documentation() const { return Documentation; }


    std::vector<std::string> GetTrackingSignalsResult::signals() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Signals"]);
    }

    void GetTrackingSignalsResult::setSignals(const std::vector<std::string>& signals)
    {
      m_values.AddMember("Signals", parse_json<std::vector<std::string>>::format(signals, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
