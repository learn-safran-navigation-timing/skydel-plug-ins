
#include "gen/GetNmeaOutputsResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNmeaOutputsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNmeaOutputsResult::CmdName = "GetNmeaOutputsResult";
    const char* const GetNmeaOutputsResult::Documentation = "Result of GetNmeaOutputs.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNmeaOutputsResult);


    GetNmeaOutputsResult::GetNmeaOutputsResult()
      : CommandResult(CmdName)
    {}

    GetNmeaOutputsResult::GetNmeaOutputsResult(const std::vector<std::string>& nmeaOutps)
      : CommandResult(CmdName)
    {

      setNmeaOutps(nmeaOutps);
    }

    GetNmeaOutputsResult::GetNmeaOutputsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& nmeaOutps)
      : CommandResult(CmdName, relatedCommand)
    {

      setNmeaOutps(nmeaOutps);
    }


    GetNmeaOutputsResultPtr GetNmeaOutputsResult::create(const std::vector<std::string>& nmeaOutps)
    {
      return std::make_shared<GetNmeaOutputsResult>(nmeaOutps);
    }

    GetNmeaOutputsResultPtr GetNmeaOutputsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& nmeaOutps)
    {
      return std::make_shared<GetNmeaOutputsResult>(relatedCommand, nmeaOutps);
    }

    GetNmeaOutputsResultPtr GetNmeaOutputsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNmeaOutputsResult>(ptr);
    }

    bool GetNmeaOutputsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["NmeaOutps"])
        ;

    }

    std::string GetNmeaOutputsResult::documentation() const { return Documentation; }


    std::vector<std::string> GetNmeaOutputsResult::nmeaOutps() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["NmeaOutps"]);
    }

    void GetNmeaOutputsResult::setNmeaOutps(const std::vector<std::string>& nmeaOutps)
    {
      m_values.AddMember("NmeaOutps", parse_json<std::vector<std::string>>::format(nmeaOutps, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
