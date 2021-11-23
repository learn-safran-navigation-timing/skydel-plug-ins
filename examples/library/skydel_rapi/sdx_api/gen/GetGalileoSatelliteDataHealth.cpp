#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoSatelliteDataHealth
///
#include "gen/GetGalileoSatelliteDataHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoSatelliteDataHealth::CmdName = "GetGalileoSatelliteDataHealth";
    const char* const GetGalileoSatelliteDataHealth::Documentation = "Please note the command GetGalileoSatelliteDataHealth is deprecated since 21.3. You may use GetGalileoDataHealthForSV.\n\nGet Galileo data health for I/NAV and F/NAV message";

    REGISTER_COMMAND_FACTORY(GetGalileoSatelliteDataHealth);


    GetGalileoSatelliteDataHealth::GetGalileoSatelliteDataHealth()
      : CommandBase(CmdName)
    {}

    GetGalileoSatelliteDataHealth::GetGalileoSatelliteDataHealth(int prn, const std::string& component)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setComponent(component);
    }


    GetGalileoSatelliteDataHealthPtr GetGalileoSatelliteDataHealth::create(int prn, const std::string& component)
    {
      return GetGalileoSatelliteDataHealthPtr(new GetGalileoSatelliteDataHealth(prn, component));
    }

    GetGalileoSatelliteDataHealthPtr GetGalileoSatelliteDataHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoSatelliteDataHealth>(ptr);
    }

    bool GetGalileoSatelliteDataHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Component"])
        ;

    }

    std::string GetGalileoSatelliteDataHealth::documentation() const { return Documentation; }


    int GetGalileoSatelliteDataHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoSatelliteDataHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoSatelliteDataHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoSatelliteDataHealth::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoSatelliteDataHealth::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
