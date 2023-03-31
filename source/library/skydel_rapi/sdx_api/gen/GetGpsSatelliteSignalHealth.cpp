#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteSignalHealth
///
#include "gen/GetGpsSatelliteSignalHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteSignalHealth::CmdName = "GetGpsSatelliteSignalHealth";
    const char* const GetGpsSatelliteSignalHealth::Documentation = "Please note the command GetGpsSatelliteSignalHealth is deprecated since 21.3. You may use GetGpsSignalHealthForSV.\n\nGet GPS signal health";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteSignalHealth);


    GetGpsSatelliteSignalHealth::GetGpsSatelliteSignalHealth()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteSignalHealth::GetGpsSatelliteSignalHealth(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteSignalHealthPtr GetGpsSatelliteSignalHealth::create(int prn)
    {
      return GetGpsSatelliteSignalHealthPtr(new GetGpsSatelliteSignalHealth(prn));
    }

    GetGpsSatelliteSignalHealthPtr GetGpsSatelliteSignalHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteSignalHealth>(ptr);
    }

    bool GetGpsSatelliteSignalHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteSignalHealth::documentation() const { return Documentation; }


    int GetGpsSatelliteSignalHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteSignalHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteSignalHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
