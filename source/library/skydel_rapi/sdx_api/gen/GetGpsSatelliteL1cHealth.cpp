#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteL1cHealth
///
#include "gen/GetGpsSatelliteL1cHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteL1cHealth::CmdName = "GetGpsSatelliteL1cHealth";
    const char* const GetGpsSatelliteL1cHealth::Documentation = "Please note the command GetGpsSatelliteL1cHealth is deprecated since 21.3. You may use GetGpsL1cHealthForSV.\n\nGet GPS L1C health (used in CNAV2 only)";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteL1cHealth);


    GetGpsSatelliteL1cHealth::GetGpsSatelliteL1cHealth()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteL1cHealth::GetGpsSatelliteL1cHealth(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteL1cHealthPtr GetGpsSatelliteL1cHealth::create(int prn)
    {
      return GetGpsSatelliteL1cHealthPtr(new GetGpsSatelliteL1cHealth(prn));
    }

    GetGpsSatelliteL1cHealthPtr GetGpsSatelliteL1cHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteL1cHealth>(ptr);
    }

    bool GetGpsSatelliteL1cHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteL1cHealth::documentation() const { return Documentation; }


    int GetGpsSatelliteL1cHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteL1cHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteL1cHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
