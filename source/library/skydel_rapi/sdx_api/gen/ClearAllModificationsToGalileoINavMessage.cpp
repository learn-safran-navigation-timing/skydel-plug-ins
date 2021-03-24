#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToGalileoINavMessage
///
#include "gen/ClearAllModificationsToGalileoINavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToGalileoINavMessage::CmdName = "ClearAllModificationsToGalileoINavMessage";
    const char* const ClearAllModificationsToGalileoINavMessage::Documentation = "Please note the command ClearAllModificationsToGalileoINavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change GALILEO navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToGalileoINavMessage);


    ClearAllModificationsToGalileoINavMessage::ClearAllModificationsToGalileoINavMessage()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToGalileoINavMessagePtr ClearAllModificationsToGalileoINavMessage::create()
    {
      return ClearAllModificationsToGalileoINavMessagePtr(new ClearAllModificationsToGalileoINavMessage());
    }

    ClearAllModificationsToGalileoINavMessagePtr ClearAllModificationsToGalileoINavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToGalileoINavMessage>(ptr);
    }

    bool ClearAllModificationsToGalileoINavMessage::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToGalileoINavMessage::documentation() const { return Documentation; }


    int ClearAllModificationsToGalileoINavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
