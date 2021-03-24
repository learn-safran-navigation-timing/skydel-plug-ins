#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToGpsNavigationMessage
///
#include "gen/ClearAllModificationsToGpsNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToGpsNavigationMessage::CmdName = "ClearAllModificationsToGpsNavigationMessage";
    const char* const ClearAllModificationsToGpsNavigationMessage::Documentation = "Please note the command ClearAllModificationsToGpsNavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change GPS navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToGpsNavigationMessage);


    ClearAllModificationsToGpsNavigationMessage::ClearAllModificationsToGpsNavigationMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToGpsNavigationMessagePtr ClearAllModificationsToGpsNavigationMessage::create()
    {
      return ClearAllModificationsToGpsNavigationMessagePtr(new ClearAllModificationsToGpsNavigationMessage());
    }

    ClearAllModificationsToGpsNavigationMessagePtr ClearAllModificationsToGpsNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToGpsNavigationMessage>(ptr);
    }

    bool ClearAllModificationsToGpsNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToGpsNavigationMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToGpsNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
