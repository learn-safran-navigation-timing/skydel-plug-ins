#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToGpsCNav2Message
///
#include "gen/ClearAllModificationsToGpsCNav2Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToGpsCNav2Message::CmdName = "ClearAllModificationsToGpsCNav2Message";
    const char* const ClearAllModificationsToGpsCNav2Message::Documentation = "Please note the command ClearAllModificationsToGpsCNav2Message is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change GPS navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToGpsCNav2Message);


    ClearAllModificationsToGpsCNav2Message::ClearAllModificationsToGpsCNav2Message()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToGpsCNav2MessagePtr ClearAllModificationsToGpsCNav2Message::create()
    {
      return ClearAllModificationsToGpsCNav2MessagePtr(new ClearAllModificationsToGpsCNav2Message());
    }

    ClearAllModificationsToGpsCNav2MessagePtr ClearAllModificationsToGpsCNav2Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToGpsCNav2Message>(ptr);
    }

    bool ClearAllModificationsToGpsCNav2Message::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToGpsCNav2Message::documentation() const { return Documentation; }


    int ClearAllModificationsToGpsCNav2Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
