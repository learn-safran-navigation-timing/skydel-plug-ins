#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToGlonassNavigationMessage
///
#include "gen/ClearAllModificationsToGlonassNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToGlonassNavigationMessage::CmdName = "ClearAllModificationsToGlonassNavigationMessage";
    const char* const ClearAllModificationsToGlonassNavigationMessage::Documentation = "Please note the command ClearAllModificationsToGlonassNavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change GLONASS navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToGlonassNavigationMessage);


    ClearAllModificationsToGlonassNavigationMessage::ClearAllModificationsToGlonassNavigationMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToGlonassNavigationMessagePtr ClearAllModificationsToGlonassNavigationMessage::create()
    {
      return ClearAllModificationsToGlonassNavigationMessagePtr(new ClearAllModificationsToGlonassNavigationMessage());
    }

    ClearAllModificationsToGlonassNavigationMessagePtr ClearAllModificationsToGlonassNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToGlonassNavigationMessage>(ptr);
    }

    bool ClearAllModificationsToGlonassNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToGlonassNavigationMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToGlonassNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
