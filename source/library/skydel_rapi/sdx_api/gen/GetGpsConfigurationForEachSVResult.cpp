#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationForEachSVResult
///
#include "gen/GetGpsConfigurationForEachSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationForEachSVResult::CmdName = "GetGpsConfigurationForEachSVResult";
    const char* const GetGpsConfigurationForEachSVResult::Documentation = "Result of GetGpsConfigurationForEachSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsConfigurationForEachSVResult);


    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsConfigurationForEachSVResult::GetGpsConfigurationForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvConfigs(svConfigs);
    }


    GetGpsConfigurationForEachSVResultPtr GetGpsConfigurationForEachSVResult::create(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs)
    {
      return GetGpsConfigurationForEachSVResultPtr(new GetGpsConfigurationForEachSVResult(relatedCommand, svConfigs));
    }

    GetGpsConfigurationForEachSVResultPtr GetGpsConfigurationForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationForEachSVResult>(ptr);
    }

    bool GetGpsConfigurationForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["SvConfigs"])
        ;

    }

    std::string GetGpsConfigurationForEachSVResult::documentation() const { return Documentation; }


    std::vector<int> GetGpsConfigurationForEachSVResult::svConfigs() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvConfigs"]);
    }

    void GetGpsConfigurationForEachSVResult::setSvConfigs(const std::vector<int>& svConfigs)
    {
      m_values.AddMember("SvConfigs", parse_json<std::vector<int>>::format(svConfigs, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
