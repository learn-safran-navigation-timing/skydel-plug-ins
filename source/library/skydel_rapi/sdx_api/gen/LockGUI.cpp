
#include "LockGUI.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of LockGUI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const LockGUI::CmdName = "LockGUI";
    const char* const LockGUI::Documentation = "Prevent GUI updates while modify the configuration. Use UnlockGUI when done with\n"
      "configuration modifications.";
    const char* const LockGUI::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(LockGUI);
    REGISTER_COMMAND_TO_FACTORY_IMPL(LockGUI);


    LockGUI::LockGUI()
      : CommandBase(CmdName, TargetId)
    {

    }

    LockGUIPtr LockGUI::create()
    {
      return std::make_shared<LockGUI>();
    }

    LockGUIPtr LockGUI::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<LockGUI>(ptr);
    }

    bool LockGUI::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string LockGUI::documentation() const { return Documentation; }

    const std::vector<std::string>& LockGUI::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int LockGUI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
