#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSatelliteSignalHealth
///
#include "gen/SetGalileoSatelliteSignalHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSatelliteSignalHealth::CmdName = "SetGalileoSatelliteSignalHealth";
    const char* const SetGalileoSatelliteSignalHealth::Documentation = "Please note the command SetGalileoSatelliteSignalHealth is deprecated since 21.3. You may use SetGalileoSignalHealthForSV.\n\nSet Galileo signal health for I/NAV and F/NAV message";

    REGISTER_COMMAND_FACTORY(SetGalileoSatelliteSignalHealth);


    SetGalileoSatelliteSignalHealth::SetGalileoSatelliteSignalHealth()
      : CommandBase(CmdName)
    {}

    SetGalileoSatelliteSignalHealth::SetGalileoSatelliteSignalHealth(int prn, const std::string& component, int health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setComponent(component);
      setHealth(health);
    }


    SetGalileoSatelliteSignalHealthPtr SetGalileoSatelliteSignalHealth::create(int prn, const std::string& component, int health)
    {
      return SetGalileoSatelliteSignalHealthPtr(new SetGalileoSatelliteSignalHealth(prn, component, health));
    }

    SetGalileoSatelliteSignalHealthPtr SetGalileoSatelliteSignalHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSatelliteSignalHealth>(ptr);
    }

    bool SetGalileoSatelliteSignalHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGalileoSatelliteSignalHealth::documentation() const { return Documentation; }


    int SetGalileoSatelliteSignalHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGalileoSatelliteSignalHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoSatelliteSignalHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGalileoSatelliteSignalHealth::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void SetGalileoSatelliteSignalHealth::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoSatelliteSignalHealth::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGalileoSatelliteSignalHealth::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
