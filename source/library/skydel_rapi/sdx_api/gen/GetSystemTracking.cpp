
#include "gen/GetSystemTracking.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSystemTracking
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSystemTracking::CmdName = "GetSystemTracking";
    const char* const GetSystemTracking::Documentation = "Returns all the systems tracked.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSystemTracking);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSystemTracking);


    GetSystemTracking::GetSystemTracking()
      : CommandBase(CmdName)
    {

    }

    GetSystemTrackingPtr GetSystemTracking::create()
    {
      return std::make_shared<GetSystemTracking>();
    }

    GetSystemTrackingPtr GetSystemTracking::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSystemTracking>(ptr);
    }

    bool GetSystemTracking::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSystemTracking::documentation() const { return Documentation; }


    int GetSystemTracking::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
