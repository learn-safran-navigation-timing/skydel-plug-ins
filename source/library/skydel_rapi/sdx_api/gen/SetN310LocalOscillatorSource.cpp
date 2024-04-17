
#include "SetN310LocalOscillatorSource.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetN310LocalOscillatorSource
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetN310LocalOscillatorSource::CmdName = "SetN310LocalOscillatorSource";
    const char* const SetN310LocalOscillatorSource::Documentation = "Set the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ -------------------------------------------------------------------------------------------\n"
      "IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.\n"
      "Id         string N310 modulation target Id.";
    const char* const SetN310LocalOscillatorSource::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetN310LocalOscillatorSource);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetN310LocalOscillatorSource);


    SetN310LocalOscillatorSource::SetN310LocalOscillatorSource()
      : CommandBase(CmdName, TargetId)
    {}

    SetN310LocalOscillatorSource::SetN310LocalOscillatorSource(bool isExternal, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setIsExternal(isExternal);
      setId(id);
    }

    SetN310LocalOscillatorSourcePtr SetN310LocalOscillatorSource::create(bool isExternal, const std::string& id)
    {
      return std::make_shared<SetN310LocalOscillatorSource>(isExternal, id);
    }

    SetN310LocalOscillatorSourcePtr SetN310LocalOscillatorSource::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetN310LocalOscillatorSource>(ptr);
    }

    bool SetN310LocalOscillatorSource::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsExternal"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetN310LocalOscillatorSource::documentation() const { return Documentation; }

    const std::vector<std::string>& SetN310LocalOscillatorSource::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsExternal", "Id"}; 
      return names; 
    }


    int SetN310LocalOscillatorSource::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    bool SetN310LocalOscillatorSource::isExternal() const
    {
      return parse_json<bool>::parse(m_values["IsExternal"]);
    }

    void SetN310LocalOscillatorSource::setIsExternal(bool isExternal)
    {
      m_values.AddMember("IsExternal", parse_json<bool>::format(isExternal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetN310LocalOscillatorSource::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetN310LocalOscillatorSource::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
