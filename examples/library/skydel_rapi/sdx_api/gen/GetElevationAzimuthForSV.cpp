#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationAzimuthForSV
///
#include "gen/GetElevationAzimuthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationAzimuthForSV::CmdName = "GetElevationAzimuthForSV";
    const char* const GetElevationAzimuthForSV::Documentation = "Get elevation and azimuth position angles for satellite.";

    REGISTER_COMMAND_FACTORY(GetElevationAzimuthForSV);


    GetElevationAzimuthForSV::GetElevationAzimuthForSV()
      : CommandBase(CmdName)
    {}

    GetElevationAzimuthForSV::GetElevationAzimuthForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }


    GetElevationAzimuthForSVPtr GetElevationAzimuthForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetElevationAzimuthForSV>(system, svId);
    }

    GetElevationAzimuthForSVPtr GetElevationAzimuthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationAzimuthForSV>(ptr);
    }

    bool GetElevationAzimuthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetElevationAzimuthForSV::documentation() const { return Documentation; }


    int GetElevationAzimuthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string GetElevationAzimuthForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetElevationAzimuthForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetElevationAzimuthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetElevationAzimuthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
