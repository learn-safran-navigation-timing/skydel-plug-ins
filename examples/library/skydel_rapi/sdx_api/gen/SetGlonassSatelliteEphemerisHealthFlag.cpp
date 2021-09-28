#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassSatelliteEphemerisHealthFlag
///
#include "gen/SetGlonassSatelliteEphemerisHealthFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassSatelliteEphemerisHealthFlag::CmdName = "SetGlonassSatelliteEphemerisHealthFlag";
    const char* const SetGlonassSatelliteEphemerisHealthFlag::Documentation = "Please note the command SetGlonassSatelliteEphemerisHealthFlag is deprecated since 21.3. You may use SetGlonassEphemerisHealthFlagForSV.\n\nSet GLONASS satellite Ephemeris Health Flag Bn(ln)";

    REGISTER_COMMAND_FACTORY(SetGlonassSatelliteEphemerisHealthFlag);


    SetGlonassSatelliteEphemerisHealthFlag::SetGlonassSatelliteEphemerisHealthFlag()
      : CommandBase(CmdName)
    {}

    SetGlonassSatelliteEphemerisHealthFlag::SetGlonassSatelliteEphemerisHealthFlag(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetGlonassSatelliteEphemerisHealthFlagPtr SetGlonassSatelliteEphemerisHealthFlag::create(int prn, bool health)
    {
      return SetGlonassSatelliteEphemerisHealthFlagPtr(new SetGlonassSatelliteEphemerisHealthFlag(prn, health));
    }

    SetGlonassSatelliteEphemerisHealthFlagPtr SetGlonassSatelliteEphemerisHealthFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlonassSatelliteEphemerisHealthFlag>(ptr);
    }

    bool SetGlonassSatelliteEphemerisHealthFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGlonassSatelliteEphemerisHealthFlag::documentation() const { return Documentation; }


    int SetGlonassSatelliteEphemerisHealthFlag::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGlonassSatelliteEphemerisHealthFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGlonassSatelliteEphemerisHealthFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGlonassSatelliteEphemerisHealthFlag::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGlonassSatelliteEphemerisHealthFlag::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
