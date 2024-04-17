
#include "gen/GetNmeaOutputs.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNmeaOutputs
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNmeaOutputs::CmdName = "GetNmeaOutputs";
    const char* const GetNmeaOutputs::Documentation = "Returns all the enabled nmea output types.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNmeaOutputs);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNmeaOutputs);


    GetNmeaOutputs::GetNmeaOutputs()
      : CommandBase(CmdName)
    {

    }

    GetNmeaOutputsPtr GetNmeaOutputs::create()
    {
      return std::make_shared<GetNmeaOutputs>();
    }

    GetNmeaOutputsPtr GetNmeaOutputs::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNmeaOutputs>(ptr);
    }

    bool GetNmeaOutputs::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetNmeaOutputs::documentation() const { return Documentation; }


    int GetNmeaOutputs::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
