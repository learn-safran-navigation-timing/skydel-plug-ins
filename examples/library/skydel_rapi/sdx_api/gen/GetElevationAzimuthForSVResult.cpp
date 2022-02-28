#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationAzimuthForSVResult
///
#include "gen/GetElevationAzimuthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationAzimuthForSVResult::CmdName = "GetElevationAzimuthForSVResult";
    const char* const GetElevationAzimuthForSVResult::Documentation = "Result of GetElevationAzimuthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetElevationAzimuthForSVResult);


    GetElevationAzimuthForSVResult::GetElevationAzimuthForSVResult()
      : CommandResult(CmdName)
    {}

    GetElevationAzimuthForSVResult::GetElevationAzimuthForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setElevationAzimuth(elevationAzimuth);
    }


    GetElevationAzimuthForSVResultPtr GetElevationAzimuthForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
    {
      return GetElevationAzimuthForSVResultPtr(new GetElevationAzimuthForSVResult(relatedCommand, system, svId, elevationAzimuth));
    }

    GetElevationAzimuthForSVResultPtr GetElevationAzimuthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationAzimuthForSVResult>(ptr);
    }

    bool GetElevationAzimuthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<Sdx::ElevationAzimuth>>::is_valid(m_values["ElevationAzimuth"])
        ;

    }

    std::string GetElevationAzimuthForSVResult::documentation() const { return Documentation; }


    std::string GetElevationAzimuthForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetElevationAzimuthForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetElevationAzimuthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetElevationAzimuthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<Sdx::ElevationAzimuth> GetElevationAzimuthForSVResult::elevationAzimuth() const
    {
      return parse_json<Sdx::optional<Sdx::ElevationAzimuth>>::parse(m_values["ElevationAzimuth"]);
    }

    void GetElevationAzimuthForSVResult::setElevationAzimuth(const Sdx::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
    {
      m_values.AddMember("ElevationAzimuth", parse_json<Sdx::optional<Sdx::ElevationAzimuth>>::format(elevationAzimuth, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
