
#include "gen/GetTimingSystem.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTimingSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTimingSystem::CmdName = "GetTimingSystem";
    const char* const GetTimingSystem::Documentation = "Returns the selected timing system.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetTimingSystem);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTimingSystem);


    GetTimingSystem::GetTimingSystem()
      : CommandBase(CmdName)
    {

    }

    GetTimingSystemPtr GetTimingSystem::create()
    {
      return std::make_shared<GetTimingSystem>();
    }

    GetTimingSystemPtr GetTimingSystem::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTimingSystem>(ptr);
    }

    bool GetTimingSystem::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetTimingSystem::documentation() const { return Documentation; }


    int GetTimingSystem::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
