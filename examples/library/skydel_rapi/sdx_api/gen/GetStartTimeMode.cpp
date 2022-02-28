#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStartTimeMode
///
#include "gen/GetStartTimeMode.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStartTimeMode::CmdName = "GetStartTimeMode";
    const char* const GetStartTimeMode::Documentation = "Get the simulation start time mode.";

    REGISTER_COMMAND_FACTORY(GetStartTimeMode);


    GetStartTimeMode::GetStartTimeMode()
      : CommandBase(CmdName)
    {

    }


    GetStartTimeModePtr GetStartTimeMode::create()
    {
      return GetStartTimeModePtr(new GetStartTimeMode());
    }

    GetStartTimeModePtr GetStartTimeMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStartTimeMode>(ptr);
    }

    bool GetStartTimeMode::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetStartTimeMode::documentation() const { return Documentation; }


    int GetStartTimeMode::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
