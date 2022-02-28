#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerGlobalOffset
///
#include "gen/GetPowerGlobalOffset.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerGlobalOffset::CmdName = "GetPowerGlobalOffset";
    const char* const GetPowerGlobalOffset::Documentation = "Get global power offset default value for all signals and all systems";

    REGISTER_COMMAND_FACTORY(GetPowerGlobalOffset);


    GetPowerGlobalOffset::GetPowerGlobalOffset()
      : CommandBase(CmdName)
    {

    }


    GetPowerGlobalOffsetPtr GetPowerGlobalOffset::create()
    {
      return GetPowerGlobalOffsetPtr(new GetPowerGlobalOffset());
    }

    GetPowerGlobalOffsetPtr GetPowerGlobalOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerGlobalOffset>(ptr);
    }

    bool GetPowerGlobalOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetPowerGlobalOffset::documentation() const { return Documentation; }


    int GetPowerGlobalOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
