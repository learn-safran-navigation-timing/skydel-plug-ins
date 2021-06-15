#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteDataHealth
///
#include "gen/SetGpsSatelliteDataHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteDataHealth::CmdName = "SetGpsSatelliteDataHealth";
    const char* const SetGpsSatelliteDataHealth::Documentation = "Please note the command SetGpsSatelliteDataHealth is deprecated since 21.3. You may use SetGpsDataHealthForSV.\n\nSet GPS nav data health";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteDataHealth);


    SetGpsSatelliteDataHealth::SetGpsSatelliteDataHealth()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteDataHealth::SetGpsSatelliteDataHealth(int prn, int health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGpsSatelliteDataHealthPtr SetGpsSatelliteDataHealth::create(int prn, int health)
    {
      return SetGpsSatelliteDataHealthPtr(new SetGpsSatelliteDataHealth(prn, health));
    }

    SetGpsSatelliteDataHealthPtr SetGpsSatelliteDataHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteDataHealth>(ptr);
    }

    bool SetGpsSatelliteDataHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsSatelliteDataHealth::documentation() const { return Documentation; }


    int SetGpsSatelliteDataHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteDataHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteDataHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsSatelliteDataHealth::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGpsSatelliteDataHealth::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
