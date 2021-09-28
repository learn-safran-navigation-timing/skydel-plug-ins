#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteNavAlertFlag
///
#include "gen/GetGpsSatelliteNavAlertFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteNavAlertFlag::CmdName = "GetGpsSatelliteNavAlertFlag";
    const char* const GetGpsSatelliteNavAlertFlag::Documentation = "Please note the command GetGpsSatelliteNavAlertFlag is deprecated since 21.3. You may use GetGpsNavAlertFlagForSV.\n\nGet GPS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteNavAlertFlag);


    GetGpsSatelliteNavAlertFlag::GetGpsSatelliteNavAlertFlag()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteNavAlertFlag::GetGpsSatelliteNavAlertFlag(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteNavAlertFlagPtr GetGpsSatelliteNavAlertFlag::create(int prn)
    {
      return GetGpsSatelliteNavAlertFlagPtr(new GetGpsSatelliteNavAlertFlag(prn));
    }

    GetGpsSatelliteNavAlertFlagPtr GetGpsSatelliteNavAlertFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteNavAlertFlag>(ptr);
    }

    bool GetGpsSatelliteNavAlertFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteNavAlertFlag::documentation() const { return Documentation; }


    int GetGpsSatelliteNavAlertFlag::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteNavAlertFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteNavAlertFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
