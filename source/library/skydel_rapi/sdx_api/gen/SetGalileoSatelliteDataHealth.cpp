#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSatelliteDataHealth
///
#include "gen/SetGalileoSatelliteDataHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSatelliteDataHealth::CmdName = "SetGalileoSatelliteDataHealth";
    const char* const SetGalileoSatelliteDataHealth::Documentation = "Please note the command SetGalileoSatelliteDataHealth is deprecated since 21.3. You may use SetGalileoDataHealthForSV.\n\nSet Galileo data health for I/NAV and F/NAV message";

    REGISTER_COMMAND_FACTORY(SetGalileoSatelliteDataHealth);


    SetGalileoSatelliteDataHealth::SetGalileoSatelliteDataHealth()
      : CommandBase(CmdName)
    {}

    SetGalileoSatelliteDataHealth::SetGalileoSatelliteDataHealth(int prn, const std::string& component, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setComponent(component);
      setHealth(health);
    }


    SetGalileoSatelliteDataHealthPtr SetGalileoSatelliteDataHealth::create(int prn, const std::string& component, bool health)
    {
      return SetGalileoSatelliteDataHealthPtr(new SetGalileoSatelliteDataHealth(prn, component, health));
    }

    SetGalileoSatelliteDataHealthPtr SetGalileoSatelliteDataHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSatelliteDataHealth>(ptr);
    }

    bool SetGalileoSatelliteDataHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGalileoSatelliteDataHealth::documentation() const { return Documentation; }


    int SetGalileoSatelliteDataHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGalileoSatelliteDataHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoSatelliteDataHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGalileoSatelliteDataHealth::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void SetGalileoSatelliteDataHealth::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGalileoSatelliteDataHealth::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGalileoSatelliteDataHealth::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
