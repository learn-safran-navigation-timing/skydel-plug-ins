#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToQzssLNAVNavigationMessage
///
#include "gen/ClearAllModificationsToQzssLNAVNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToQzssLNAVNavigationMessage::CmdName = "ClearAllModificationsToQzssLNAVNavigationMessage";
    const char* const ClearAllModificationsToQzssLNAVNavigationMessage::Documentation = "Please note the command ClearAllModificationsToQzssLNAVNavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change QZSS navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToQzssLNAVNavigationMessage);


    ClearAllModificationsToQzssLNAVNavigationMessage::ClearAllModificationsToQzssLNAVNavigationMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToQzssLNAVNavigationMessagePtr ClearAllModificationsToQzssLNAVNavigationMessage::create()
    {
      return ClearAllModificationsToQzssLNAVNavigationMessagePtr(new ClearAllModificationsToQzssLNAVNavigationMessage());
    }

    ClearAllModificationsToQzssLNAVNavigationMessagePtr ClearAllModificationsToQzssLNAVNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToQzssLNAVNavigationMessage>(ptr);
    }

    bool ClearAllModificationsToQzssLNAVNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToQzssLNAVNavigationMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToQzssLNAVNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
