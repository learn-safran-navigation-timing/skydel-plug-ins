#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoSatelliteSignalHealth
///
#include "gen/GetGalileoSatelliteSignalHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoSatelliteSignalHealth::CmdName = "GetGalileoSatelliteSignalHealth";
    const char* const GetGalileoSatelliteSignalHealth::Documentation = "Please note the command GetGalileoSatelliteSignalHealth is deprecated since 21.3. You may use GetGalileoSignalHealthForSV.\n\nGet Galileo signal health for I/NAV and F/NAV message";

    REGISTER_COMMAND_FACTORY(GetGalileoSatelliteSignalHealth);


    GetGalileoSatelliteSignalHealth::GetGalileoSatelliteSignalHealth()
      : CommandBase(CmdName)
    {}

    GetGalileoSatelliteSignalHealth::GetGalileoSatelliteSignalHealth(int prn, const std::string& component)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setComponent(component);
    }


    GetGalileoSatelliteSignalHealthPtr GetGalileoSatelliteSignalHealth::create(int prn, const std::string& component)
    {
      return GetGalileoSatelliteSignalHealthPtr(new GetGalileoSatelliteSignalHealth(prn, component));
    }

    GetGalileoSatelliteSignalHealthPtr GetGalileoSatelliteSignalHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoSatelliteSignalHealth>(ptr);
    }

    bool GetGalileoSatelliteSignalHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Component"])
        ;

    }

    std::string GetGalileoSatelliteSignalHealth::documentation() const { return Documentation; }


    int GetGalileoSatelliteSignalHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoSatelliteSignalHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoSatelliteSignalHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoSatelliteSignalHealth::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoSatelliteSignalHealth::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
