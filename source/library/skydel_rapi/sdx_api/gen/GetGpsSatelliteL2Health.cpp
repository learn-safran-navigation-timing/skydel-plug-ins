#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL2Health
///
#include "gen/GetGpsSatelliteL2Health.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL2Health::CmdName = "GetGpsSatelliteL2Health";
    const char* const GetGpsSatelliteL2Health::Documentation = "Please note the command GetGpsSatelliteL2Health is deprecated since 21.3. You may use GetGpsL2HealthForSV.\n\nGet GPS L2 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteL2Health);


    GetGpsSatelliteL2Health::GetGpsSatelliteL2Health()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteL2Health::GetGpsSatelliteL2Health(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteL2HealthPtr GetGpsSatelliteL2Health::create(int prn)
    {
      return GetGpsSatelliteL2HealthPtr(new GetGpsSatelliteL2Health(prn));
    }

    GetGpsSatelliteL2HealthPtr GetGpsSatelliteL2Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL2Health>(ptr);
    }

    bool GetGpsSatelliteL2Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteL2Health::documentation() const { return Documentation; }


    int GetGpsSatelliteL2Health::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteL2Health::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL2Health::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
