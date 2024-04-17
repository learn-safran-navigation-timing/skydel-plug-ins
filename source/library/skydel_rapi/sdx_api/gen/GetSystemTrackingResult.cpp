
#include "gen/GetSystemTrackingResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSystemTrackingResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSystemTrackingResult::CmdName = "GetSystemTrackingResult";
    const char* const GetSystemTrackingResult::Documentation = "Result of GetSystemTracking.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSystemTrackingResult);


    GetSystemTrackingResult::GetSystemTrackingResult()
      : CommandResult(CmdName)
    {}

    GetSystemTrackingResult::GetSystemTrackingResult(const std::vector<std::string>& systems)
      : CommandResult(CmdName)
    {

      setSystems(systems);
    }

    GetSystemTrackingResult::GetSystemTrackingResult(CommandBasePtr relatedCommand, const std::vector<std::string>& systems)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystems(systems);
    }


    GetSystemTrackingResultPtr GetSystemTrackingResult::create(const std::vector<std::string>& systems)
    {
      return std::make_shared<GetSystemTrackingResult>(systems);
    }

    GetSystemTrackingResultPtr GetSystemTrackingResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& systems)
    {
      return std::make_shared<GetSystemTrackingResult>(relatedCommand, systems);
    }

    GetSystemTrackingResultPtr GetSystemTrackingResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSystemTrackingResult>(ptr);
    }

    bool GetSystemTrackingResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Systems"])
        ;

    }

    std::string GetSystemTrackingResult::documentation() const { return Documentation; }


    std::vector<std::string> GetSystemTrackingResult::systems() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Systems"]);
    }

    void GetSystemTrackingResult::setSystems(const std::vector<std::string>& systems)
    {
      m_values.AddMember("Systems", parse_json<std::vector<std::string>>::format(systems, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
