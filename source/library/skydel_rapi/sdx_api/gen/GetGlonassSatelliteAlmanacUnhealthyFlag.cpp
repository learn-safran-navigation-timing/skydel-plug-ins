#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassSatelliteAlmanacUnhealthyFlag
///
#include "gen/GetGlonassSatelliteAlmanacUnhealthyFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassSatelliteAlmanacUnhealthyFlag::CmdName = "GetGlonassSatelliteAlmanacUnhealthyFlag";
    const char* const GetGlonassSatelliteAlmanacUnhealthyFlag::Documentation = "Please note the command GetGlonassSatelliteAlmanacUnhealthyFlag is deprecated since 21.3. You may use GetGlonassAlmanacUnhealthyFlagForSV.\n\nGet GLONASS satellite Almanac Unhealthy Flag Cn";

    REGISTER_COMMAND_FACTORY(GetGlonassSatelliteAlmanacUnhealthyFlag);


    GetGlonassSatelliteAlmanacUnhealthyFlag::GetGlonassSatelliteAlmanacUnhealthyFlag()
      : CommandBase(CmdName)
    {}

    GetGlonassSatelliteAlmanacUnhealthyFlag::GetGlonassSatelliteAlmanacUnhealthyFlag(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGlonassSatelliteAlmanacUnhealthyFlagPtr GetGlonassSatelliteAlmanacUnhealthyFlag::create(int prn)
    {
      return GetGlonassSatelliteAlmanacUnhealthyFlagPtr(new GetGlonassSatelliteAlmanacUnhealthyFlag(prn));
    }

    GetGlonassSatelliteAlmanacUnhealthyFlagPtr GetGlonassSatelliteAlmanacUnhealthyFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassSatelliteAlmanacUnhealthyFlag>(ptr);
    }

    bool GetGlonassSatelliteAlmanacUnhealthyFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGlonassSatelliteAlmanacUnhealthyFlag::documentation() const { return Documentation; }


    int GetGlonassSatelliteAlmanacUnhealthyFlag::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGlonassSatelliteAlmanacUnhealthyFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassSatelliteAlmanacUnhealthyFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
