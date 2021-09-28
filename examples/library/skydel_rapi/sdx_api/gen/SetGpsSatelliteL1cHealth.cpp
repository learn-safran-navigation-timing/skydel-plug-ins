#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteL1cHealth
///
#include "gen/SetGpsSatelliteL1cHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteL1cHealth::CmdName = "SetGpsSatelliteL1cHealth";
    const char* const SetGpsSatelliteL1cHealth::Documentation = "Please note the command SetGpsSatelliteL1cHealth is deprecated since 21.3. You may use SetGpsL1cHealthForSV.\n\nSet GPS L1C health (used in CNAV2 only)";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteL1cHealth);


    SetGpsSatelliteL1cHealth::SetGpsSatelliteL1cHealth()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteL1cHealth::SetGpsSatelliteL1cHealth(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGpsSatelliteL1cHealthPtr SetGpsSatelliteL1cHealth::create(int prn, bool health)
    {
      return SetGpsSatelliteL1cHealthPtr(new SetGpsSatelliteL1cHealth(prn, health));
    }

    SetGpsSatelliteL1cHealthPtr SetGpsSatelliteL1cHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteL1cHealth>(ptr);
    }

    bool SetGpsSatelliteL1cHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsSatelliteL1cHealth::documentation() const { return Documentation; }


    int SetGpsSatelliteL1cHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteL1cHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteL1cHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsSatelliteL1cHealth::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsSatelliteL1cHealth::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
