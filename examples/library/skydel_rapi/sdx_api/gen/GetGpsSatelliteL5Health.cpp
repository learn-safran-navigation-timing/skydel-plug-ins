#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL5Health
///
#include "gen/GetGpsSatelliteL5Health.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL5Health::CmdName = "GetGpsSatelliteL5Health";
    const char* const GetGpsSatelliteL5Health::Documentation = "Please note the command GetGpsSatelliteL5Health is deprecated since 21.3. You may use GetGpsL5HealthForSV.\n\nGet GPS L5 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteL5Health);


    GetGpsSatelliteL5Health::GetGpsSatelliteL5Health()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteL5Health::GetGpsSatelliteL5Health(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteL5HealthPtr GetGpsSatelliteL5Health::create(int prn)
    {
      return GetGpsSatelliteL5HealthPtr(new GetGpsSatelliteL5Health(prn));
    }

    GetGpsSatelliteL5HealthPtr GetGpsSatelliteL5Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL5Health>(ptr);
    }

    bool GetGpsSatelliteL5Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteL5Health::documentation() const { return Documentation; }


    int GetGpsSatelliteL5Health::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteL5Health::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL5Health::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
