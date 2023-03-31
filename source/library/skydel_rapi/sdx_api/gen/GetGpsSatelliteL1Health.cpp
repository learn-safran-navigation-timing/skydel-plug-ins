#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL1Health
///
#include "gen/GetGpsSatelliteL1Health.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL1Health::CmdName = "GetGpsSatelliteL1Health";
    const char* const GetGpsSatelliteL1Health::Documentation = "Please note the command GetGpsSatelliteL1Health is deprecated since 21.3. You may use GetGpsL1HealthForSV.\n\nGet GPS L1 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteL1Health);


    GetGpsSatelliteL1Health::GetGpsSatelliteL1Health()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteL1Health::GetGpsSatelliteL1Health(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteL1HealthPtr GetGpsSatelliteL1Health::create(int prn)
    {
      return GetGpsSatelliteL1HealthPtr(new GetGpsSatelliteL1Health(prn));
    }

    GetGpsSatelliteL1HealthPtr GetGpsSatelliteL1Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL1Health>(ptr);
    }

    bool GetGpsSatelliteL1Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteL1Health::documentation() const { return Documentation; }


    int GetGpsSatelliteL1Health::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteL1Health::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL1Health::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
