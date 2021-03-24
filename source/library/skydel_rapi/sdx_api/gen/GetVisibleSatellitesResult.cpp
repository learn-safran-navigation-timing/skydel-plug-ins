#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVisibleSatellitesResult
///
#include "gen/GetVisibleSatellitesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVisibleSatellitesResult::CmdName = "GetVisibleSatellitesResult";
    const char* const GetVisibleSatellitesResult::Documentation = "Result of GetVisibleSatellites";

    REGISTER_COMMAND_RESULT_FACTORY(GetVisibleSatellitesResult);


    GetVisibleSatellitesResult::GetVisibleSatellitesResult()
      : CommandResult(CmdName)
    {}

    GetVisibleSatellitesResult::GetVisibleSatellitesResult(CommandBasePtr relatedCommand, const std::vector<int>& prns)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrns(prns);
    }


    GetVisibleSatellitesResultPtr GetVisibleSatellitesResult::create(CommandBasePtr relatedCommand, const std::vector<int>& prns)
    {
      return GetVisibleSatellitesResultPtr(new GetVisibleSatellitesResult(relatedCommand, prns));
    }

    GetVisibleSatellitesResultPtr GetVisibleSatellitesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVisibleSatellitesResult>(ptr);
    }

    bool GetVisibleSatellitesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["Prns"])
        ;

    }

    std::string GetVisibleSatellitesResult::documentation() const { return Documentation; }


    std::vector<int> GetVisibleSatellitesResult::prns() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Prns"]);
    }

    void GetVisibleSatellitesResult::setPrns(const std::vector<int>& prns)
    {
      m_values.AddMember("Prns", parse_json<std::vector<int>>::format(prns, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
