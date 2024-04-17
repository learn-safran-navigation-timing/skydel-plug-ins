
#include "gen/GetPVTSignals.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPVTSignals
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPVTSignals::CmdName = "GetPVTSignals";
    const char* const GetPVTSignals::Documentation = "Returns all the signals used for PVT.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPVTSignals);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPVTSignals);


    GetPVTSignals::GetPVTSignals()
      : CommandBase(CmdName)
    {

    }

    GetPVTSignalsPtr GetPVTSignals::create()
    {
      return std::make_shared<GetPVTSignals>();
    }

    GetPVTSignalsPtr GetPVTSignals::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPVTSignals>(ptr);
    }

    bool GetPVTSignals::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetPVTSignals::documentation() const { return Documentation; }


    int GetPVTSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
