#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToBeiDouD2NavigationMessage
///
#include "gen/ClearAllModificationsToBeiDouD2NavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToBeiDouD2NavigationMessage::CmdName = "ClearAllModificationsToBeiDouD2NavigationMessage";
    const char* const ClearAllModificationsToBeiDouD2NavigationMessage::Documentation = "Please note the command ClearAllModificationsToBeiDouD2NavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change BeiDou navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToBeiDouD2NavigationMessage);


    ClearAllModificationsToBeiDouD2NavigationMessage::ClearAllModificationsToBeiDouD2NavigationMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToBeiDouD2NavigationMessagePtr ClearAllModificationsToBeiDouD2NavigationMessage::create()
    {
      return ClearAllModificationsToBeiDouD2NavigationMessagePtr(new ClearAllModificationsToBeiDouD2NavigationMessage());
    }

    ClearAllModificationsToBeiDouD2NavigationMessagePtr ClearAllModificationsToBeiDouD2NavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToBeiDouD2NavigationMessage>(ptr);
    }

    bool ClearAllModificationsToBeiDouD2NavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToBeiDouD2NavigationMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToBeiDouD2NavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
