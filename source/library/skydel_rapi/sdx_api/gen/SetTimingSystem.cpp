
#include "gen/SetTimingSystem.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetTimingSystem
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetTimingSystem::CmdName = "SetTimingSystem";
    const char* const SetTimingSystem::Documentation = "Select the timing system used. Default is GPS.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetTimingSystem);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetTimingSystem);


    SetTimingSystem::SetTimingSystem()
      : CommandBase(CmdName)
    {}

    SetTimingSystem::SetTimingSystem(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    SetTimingSystemPtr SetTimingSystem::create(const std::string& system)
    {
      return std::make_shared<SetTimingSystem>(system);
    }

    SetTimingSystemPtr SetTimingSystem::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetTimingSystem>(ptr);
    }

    bool SetTimingSystem::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string SetTimingSystem::documentation() const { return Documentation; }


    int SetTimingSystem::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetTimingSystem::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetTimingSystem::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
