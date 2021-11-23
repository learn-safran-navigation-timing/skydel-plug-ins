#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteDataHealth
///
#include "gen/GetGpsSatelliteDataHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteDataHealth::CmdName = "GetGpsSatelliteDataHealth";
    const char* const GetGpsSatelliteDataHealth::Documentation = "Please note the command GetGpsSatelliteDataHealth is deprecated since 21.3. You may use GetGpsDataHealthForSV.\n\nGet GPS nav data health";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteDataHealth);


    GetGpsSatelliteDataHealth::GetGpsSatelliteDataHealth()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteDataHealth::GetGpsSatelliteDataHealth(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteDataHealthPtr GetGpsSatelliteDataHealth::create(int prn)
    {
      return GetGpsSatelliteDataHealthPtr(new GetGpsSatelliteDataHealth(prn));
    }

    GetGpsSatelliteDataHealthPtr GetGpsSatelliteDataHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteDataHealth>(ptr);
    }

    bool GetGpsSatelliteDataHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteDataHealth::documentation() const { return Documentation; }


    int GetGpsSatelliteDataHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteDataHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteDataHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
