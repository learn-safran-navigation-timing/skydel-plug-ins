#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteL2Health
///
#include "gen/SetGpsSatelliteL2Health.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteL2Health::CmdName = "SetGpsSatelliteL2Health";
    const char* const SetGpsSatelliteL2Health::Documentation = "Please note the command SetGpsSatelliteL2Health is deprecated since 21.3. You may use SetGpsL2HealthForSV.\n\nSet GPS L2 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteL2Health);


    SetGpsSatelliteL2Health::SetGpsSatelliteL2Health()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteL2Health::SetGpsSatelliteL2Health(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGpsSatelliteL2HealthPtr SetGpsSatelliteL2Health::create(int prn, bool health)
    {
      return SetGpsSatelliteL2HealthPtr(new SetGpsSatelliteL2Health(prn, health));
    }

    SetGpsSatelliteL2HealthPtr SetGpsSatelliteL2Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteL2Health>(ptr);
    }

    bool SetGpsSatelliteL2Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsSatelliteL2Health::documentation() const { return Documentation; }


    int SetGpsSatelliteL2Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteL2Health::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteL2Health::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsSatelliteL2Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsSatelliteL2Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
