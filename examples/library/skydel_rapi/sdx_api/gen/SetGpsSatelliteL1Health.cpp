#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteL1Health
///
#include "gen/SetGpsSatelliteL1Health.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteL1Health::CmdName = "SetGpsSatelliteL1Health";
    const char* const SetGpsSatelliteL1Health::Documentation = "Please note the command SetGpsSatelliteL1Health is deprecated since 21.3. You may use SetGpsL1HealthForSV.\n\nSet GPS L1 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteL1Health);


    SetGpsSatelliteL1Health::SetGpsSatelliteL1Health()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteL1Health::SetGpsSatelliteL1Health(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGpsSatelliteL1HealthPtr SetGpsSatelliteL1Health::create(int prn, bool health)
    {
      return SetGpsSatelliteL1HealthPtr(new SetGpsSatelliteL1Health(prn, health));
    }

    SetGpsSatelliteL1HealthPtr SetGpsSatelliteL1Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteL1Health>(ptr);
    }

    bool SetGpsSatelliteL1Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsSatelliteL1Health::documentation() const { return Documentation; }


    int SetGpsSatelliteL1Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteL1Health::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteL1Health::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsSatelliteL1Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsSatelliteL1Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
