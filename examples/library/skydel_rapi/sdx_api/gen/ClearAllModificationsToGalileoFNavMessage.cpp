#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToGalileoFNavMessage
///
#include "gen/ClearAllModificationsToGalileoFNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToGalileoFNavMessage::CmdName = "ClearAllModificationsToGalileoFNavMessage";
    const char* const ClearAllModificationsToGalileoFNavMessage::Documentation = "Please note the command ClearAllModificationsToGalileoFNavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change GALILEO navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToGalileoFNavMessage);


    ClearAllModificationsToGalileoFNavMessage::ClearAllModificationsToGalileoFNavMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToGalileoFNavMessagePtr ClearAllModificationsToGalileoFNavMessage::create()
    {
      return ClearAllModificationsToGalileoFNavMessagePtr(new ClearAllModificationsToGalileoFNavMessage());
    }

    ClearAllModificationsToGalileoFNavMessagePtr ClearAllModificationsToGalileoFNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToGalileoFNavMessage>(ptr);
    }

    bool ClearAllModificationsToGalileoFNavMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToGalileoFNavMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToGalileoFNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
