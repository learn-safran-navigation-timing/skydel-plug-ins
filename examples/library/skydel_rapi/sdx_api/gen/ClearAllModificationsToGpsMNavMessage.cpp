#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToGpsMNavMessage
///
#include "gen/ClearAllModificationsToGpsMNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToGpsMNavMessage::CmdName = "ClearAllModificationsToGpsMNavMessage";
    const char* const ClearAllModificationsToGpsMNavMessage::Documentation = "Please note the command ClearAllModificationsToGpsMNavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change GPS navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToGpsMNavMessage);


    ClearAllModificationsToGpsMNavMessage::ClearAllModificationsToGpsMNavMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToGpsMNavMessagePtr ClearAllModificationsToGpsMNavMessage::create()
    {
      return ClearAllModificationsToGpsMNavMessagePtr(new ClearAllModificationsToGpsMNavMessage());
    }

    ClearAllModificationsToGpsMNavMessagePtr ClearAllModificationsToGpsMNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToGpsMNavMessage>(ptr);
    }

    bool ClearAllModificationsToGpsMNavMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToGpsMNavMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToGpsMNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
