#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassSatelliteEphemerisHealthFlag
///
#include "gen/GetGlonassSatelliteEphemerisHealthFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassSatelliteEphemerisHealthFlag::CmdName = "GetGlonassSatelliteEphemerisHealthFlag";
    const char* const GetGlonassSatelliteEphemerisHealthFlag::Documentation = "Please note the command GetGlonassSatelliteEphemerisHealthFlag is deprecated since 21.3. You may use GetGlonassEphemerisHealthFlagForSV.\n\nGet GLONASS satellite Ephemeris Health Flag Bn(ln)";

    REGISTER_COMMAND_FACTORY(GetGlonassSatelliteEphemerisHealthFlag);


    GetGlonassSatelliteEphemerisHealthFlag::GetGlonassSatelliteEphemerisHealthFlag()
      : CommandBase(CmdName)
    {}

    GetGlonassSatelliteEphemerisHealthFlag::GetGlonassSatelliteEphemerisHealthFlag(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGlonassSatelliteEphemerisHealthFlagPtr GetGlonassSatelliteEphemerisHealthFlag::create(int prn)
    {
      return GetGlonassSatelliteEphemerisHealthFlagPtr(new GetGlonassSatelliteEphemerisHealthFlag(prn));
    }

    GetGlonassSatelliteEphemerisHealthFlagPtr GetGlonassSatelliteEphemerisHealthFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassSatelliteEphemerisHealthFlag>(ptr);
    }

    bool GetGlonassSatelliteEphemerisHealthFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGlonassSatelliteEphemerisHealthFlag::documentation() const { return Documentation; }


    int GetGlonassSatelliteEphemerisHealthFlag::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGlonassSatelliteEphemerisHealthFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassSatelliteEphemerisHealthFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
