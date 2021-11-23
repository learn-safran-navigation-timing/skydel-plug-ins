#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteSignalHealth
///
#include "gen/SetGpsSatelliteSignalHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteSignalHealth::CmdName = "SetGpsSatelliteSignalHealth";
    const char* const SetGpsSatelliteSignalHealth::Documentation = "Please note the command SetGpsSatelliteSignalHealth is deprecated since 21.3. You may use SetGpsSignalHealthForSV.\n\nSet GPS signal health";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteSignalHealth);


    SetGpsSatelliteSignalHealth::SetGpsSatelliteSignalHealth()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteSignalHealth::SetGpsSatelliteSignalHealth(int prn, int health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGpsSatelliteSignalHealthPtr SetGpsSatelliteSignalHealth::create(int prn, int health)
    {
      return SetGpsSatelliteSignalHealthPtr(new SetGpsSatelliteSignalHealth(prn, health));
    }

    SetGpsSatelliteSignalHealthPtr SetGpsSatelliteSignalHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteSignalHealth>(ptr);
    }

    bool SetGpsSatelliteSignalHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsSatelliteSignalHealth::documentation() const { return Documentation; }


    int SetGpsSatelliteSignalHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteSignalHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteSignalHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsSatelliteSignalHealth::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGpsSatelliteSignalHealth::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
