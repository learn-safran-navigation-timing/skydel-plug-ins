#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToGpsCNavMessage
///
#include "gen/ClearAllModificationsToGpsCNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToGpsCNavMessage::CmdName = "ClearAllModificationsToGpsCNavMessage";
    const char* const ClearAllModificationsToGpsCNavMessage::Documentation = "Please note the command ClearAllModificationsToGpsCNavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change GPS navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToGpsCNavMessage);


    ClearAllModificationsToGpsCNavMessage::ClearAllModificationsToGpsCNavMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToGpsCNavMessagePtr ClearAllModificationsToGpsCNavMessage::create()
    {
      return ClearAllModificationsToGpsCNavMessagePtr(new ClearAllModificationsToGpsCNavMessage());
    }

    ClearAllModificationsToGpsCNavMessagePtr ClearAllModificationsToGpsCNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToGpsCNavMessage>(ptr);
    }

    bool ClearAllModificationsToGpsCNavMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToGpsCNavMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToGpsCNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
