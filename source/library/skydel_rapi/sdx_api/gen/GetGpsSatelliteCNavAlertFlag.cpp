#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteCNavAlertFlag
///
#include "gen/GetGpsSatelliteCNavAlertFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteCNavAlertFlag::CmdName = "GetGpsSatelliteCNavAlertFlag";
    const char* const GetGpsSatelliteCNavAlertFlag::Documentation = "Please note the command GetGpsSatelliteCNavAlertFlag is deprecated since 21.3. You may use GetGpsCNavAlertFlagToSV.\n\nGet GPS CNAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteCNavAlertFlag);


    GetGpsSatelliteCNavAlertFlag::GetGpsSatelliteCNavAlertFlag()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteCNavAlertFlag::GetGpsSatelliteCNavAlertFlag(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteCNavAlertFlagPtr GetGpsSatelliteCNavAlertFlag::create(int prn)
    {
      return GetGpsSatelliteCNavAlertFlagPtr(new GetGpsSatelliteCNavAlertFlag(prn));
    }

    GetGpsSatelliteCNavAlertFlagPtr GetGpsSatelliteCNavAlertFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteCNavAlertFlag>(ptr);
    }

    bool GetGpsSatelliteCNavAlertFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteCNavAlertFlag::documentation() const { return Documentation; }


    int GetGpsSatelliteCNavAlertFlag::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteCNavAlertFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteCNavAlertFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
