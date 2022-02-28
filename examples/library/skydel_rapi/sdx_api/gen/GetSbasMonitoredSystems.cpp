#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMonitoredSystems
///
#include "gen/GetSbasMonitoredSystems.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMonitoredSystems::CmdName = "GetSbasMonitoredSystems";
    const char* const GetSbasMonitoredSystems::Documentation = "Get the systems monitored by SBAS.";

    REGISTER_COMMAND_FACTORY(GetSbasMonitoredSystems);


    GetSbasMonitoredSystems::GetSbasMonitoredSystems()
      : CommandBase(CmdName)
    {

    }


    GetSbasMonitoredSystemsPtr GetSbasMonitoredSystems::create()
    {
      return GetSbasMonitoredSystemsPtr(new GetSbasMonitoredSystems());
    }

    GetSbasMonitoredSystemsPtr GetSbasMonitoredSystems::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMonitoredSystems>(ptr);
    }

    bool GetSbasMonitoredSystems::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSbasMonitoredSystems::documentation() const { return Documentation; }


    int GetSbasMonitoredSystems::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
