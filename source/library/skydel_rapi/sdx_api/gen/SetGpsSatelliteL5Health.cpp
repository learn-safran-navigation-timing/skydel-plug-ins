#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteL5Health
///
#include "gen/SetGpsSatelliteL5Health.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteL5Health::CmdName = "SetGpsSatelliteL5Health";
    const char* const SetGpsSatelliteL5Health::Documentation = "Please note the command SetGpsSatelliteL5Health is deprecated since 21.3. You may use SetGpsL5HealthForSV.\n\nSet GPS L5 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteL5Health);


    SetGpsSatelliteL5Health::SetGpsSatelliteL5Health()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteL5Health::SetGpsSatelliteL5Health(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGpsSatelliteL5HealthPtr SetGpsSatelliteL5Health::create(int prn, bool health)
    {
      return SetGpsSatelliteL5HealthPtr(new SetGpsSatelliteL5Health(prn, health));
    }

    SetGpsSatelliteL5HealthPtr SetGpsSatelliteL5Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteL5Health>(ptr);
    }

    bool SetGpsSatelliteL5Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsSatelliteL5Health::documentation() const { return Documentation; }


    int SetGpsSatelliteL5Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteL5Health::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteL5Health::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsSatelliteL5Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsSatelliteL5Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
