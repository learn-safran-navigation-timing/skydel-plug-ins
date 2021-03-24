#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToBeiDouD1NavigationMessage
///
#include "gen/ClearAllModificationsToBeiDouD1NavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToBeiDouD1NavigationMessage::CmdName = "ClearAllModificationsToBeiDouD1NavigationMessage";
    const char* const ClearAllModificationsToBeiDouD1NavigationMessage::Documentation = "Please note the command ClearAllModificationsToBeiDouD1NavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change BeiDou navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToBeiDouD1NavigationMessage);


    ClearAllModificationsToBeiDouD1NavigationMessage::ClearAllModificationsToBeiDouD1NavigationMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToBeiDouD1NavigationMessagePtr ClearAllModificationsToBeiDouD1NavigationMessage::create()
    {
      return ClearAllModificationsToBeiDouD1NavigationMessagePtr(new ClearAllModificationsToBeiDouD1NavigationMessage());
    }

    ClearAllModificationsToBeiDouD1NavigationMessagePtr ClearAllModificationsToBeiDouD1NavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToBeiDouD1NavigationMessage>(ptr);
    }

    bool ClearAllModificationsToBeiDouD1NavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToBeiDouD1NavigationMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToBeiDouD1NavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
