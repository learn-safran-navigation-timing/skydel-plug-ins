#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToBeiDouCNav2Message
///
#include "gen/ClearAllModificationsToBeiDouCNav2Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToBeiDouCNav2Message::CmdName = "ClearAllModificationsToBeiDouCNav2Message";
    const char* const ClearAllModificationsToBeiDouCNav2Message::Documentation = "Please note the command ClearAllModificationsToBeiDouCNav2Message is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change BeiDou CNAV2 navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToBeiDouCNav2Message);


    ClearAllModificationsToBeiDouCNav2Message::ClearAllModificationsToBeiDouCNav2Message()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToBeiDouCNav2MessagePtr ClearAllModificationsToBeiDouCNav2Message::create()
    {
      return ClearAllModificationsToBeiDouCNav2MessagePtr(new ClearAllModificationsToBeiDouCNav2Message());
    }

    ClearAllModificationsToBeiDouCNav2MessagePtr ClearAllModificationsToBeiDouCNav2Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToBeiDouCNav2Message>(ptr);
    }

    bool ClearAllModificationsToBeiDouCNav2Message::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToBeiDouCNav2Message::documentation() const { return Documentation; }


    int ClearAllModificationsToBeiDouCNav2Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
