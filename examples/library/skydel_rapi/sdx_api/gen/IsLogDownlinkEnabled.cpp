#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogDownlinkEnabled
///
#include "gen/IsLogDownlinkEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogDownlinkEnabled::CmdName = "IsLogDownlinkEnabled";
    const char* const IsLogDownlinkEnabled::Documentation = "Tells if downlink data Logging is enabled";

    REGISTER_COMMAND_FACTORY(IsLogDownlinkEnabled);


    IsLogDownlinkEnabled::IsLogDownlinkEnabled()
      : CommandBase(CmdName)
    {

    }


    IsLogDownlinkEnabledPtr IsLogDownlinkEnabled::create()
    {
      return std::make_shared<IsLogDownlinkEnabled>();
    }

    IsLogDownlinkEnabledPtr IsLogDownlinkEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogDownlinkEnabled>(ptr);
    }

    bool IsLogDownlinkEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogDownlinkEnabled::documentation() const { return Documentation; }


    int IsLogDownlinkEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
