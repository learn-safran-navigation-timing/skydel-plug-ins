#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassSatelliteAlmanacUnhealthyFlag
///
#include "gen/SetGlonassSatelliteAlmanacUnhealthyFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassSatelliteAlmanacUnhealthyFlag::CmdName = "SetGlonassSatelliteAlmanacUnhealthyFlag";
    const char* const SetGlonassSatelliteAlmanacUnhealthyFlag::Documentation = "Please note the command SetGlonassSatelliteAlmanacUnhealthyFlag is deprecated since 21.3. You may use SetGlonassAlmanacUnhealthyFlagForSV.\n\nSet GLONASS satellite Almanac Unhealthy Flag Cn";

    REGISTER_COMMAND_FACTORY(SetGlonassSatelliteAlmanacUnhealthyFlag);


    SetGlonassSatelliteAlmanacUnhealthyFlag::SetGlonassSatelliteAlmanacUnhealthyFlag()
      : CommandBase(CmdName)
    {}

    SetGlonassSatelliteAlmanacUnhealthyFlag::SetGlonassSatelliteAlmanacUnhealthyFlag(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGlonassSatelliteAlmanacUnhealthyFlagPtr SetGlonassSatelliteAlmanacUnhealthyFlag::create(int prn, bool health)
    {
      return SetGlonassSatelliteAlmanacUnhealthyFlagPtr(new SetGlonassSatelliteAlmanacUnhealthyFlag(prn, health));
    }

    SetGlonassSatelliteAlmanacUnhealthyFlagPtr SetGlonassSatelliteAlmanacUnhealthyFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlonassSatelliteAlmanacUnhealthyFlag>(ptr);
    }

    bool SetGlonassSatelliteAlmanacUnhealthyFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGlonassSatelliteAlmanacUnhealthyFlag::documentation() const { return Documentation; }


    int SetGlonassSatelliteAlmanacUnhealthyFlag::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGlonassSatelliteAlmanacUnhealthyFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGlonassSatelliteAlmanacUnhealthyFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGlonassSatelliteAlmanacUnhealthyFlag::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGlonassSatelliteAlmanacUnhealthyFlag::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
