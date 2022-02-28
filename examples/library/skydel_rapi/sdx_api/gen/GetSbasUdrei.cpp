#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasUdrei
///
#include "gen/GetSbasUdrei.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasUdrei::CmdName = "GetSbasUdrei";
    const char* const GetSbasUdrei::Documentation = "Get the global UDREI value transmitted by SBAS";

    REGISTER_COMMAND_FACTORY(GetSbasUdrei);


    GetSbasUdrei::GetSbasUdrei()
      : CommandBase(CmdName)
    {

    }


    GetSbasUdreiPtr GetSbasUdrei::create()
    {
      return GetSbasUdreiPtr(new GetSbasUdrei());
    }

    GetSbasUdreiPtr GetSbasUdrei::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasUdrei>(ptr);
    }

    bool GetSbasUdrei::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSbasUdrei::documentation() const { return Documentation; }


    int GetSbasUdrei::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
