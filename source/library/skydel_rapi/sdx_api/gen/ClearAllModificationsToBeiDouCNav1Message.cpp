#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearAllModificationsToBeiDouCNav1Message
///
#include "gen/ClearAllModificationsToBeiDouCNav1Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearAllModificationsToBeiDouCNav1Message::CmdName = "ClearAllModificationsToBeiDouCNav1Message";
    const char* const ClearAllModificationsToBeiDouCNav1Message::Documentation = "Please note the command ClearAllModificationsToBeiDouCNav1Message is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.\n\nClear all events to change BeiDou navigation message bits";

    REGISTER_COMMAND_FACTORY(ClearAllModificationsToBeiDouCNav1Message);


    ClearAllModificationsToBeiDouCNav1Message::ClearAllModificationsToBeiDouCNav1Message()
      : CommandBase(CmdName)
    {

    }


    ClearAllModificationsToBeiDouCNav1MessagePtr ClearAllModificationsToBeiDouCNav1Message::create()
    {
      return ClearAllModificationsToBeiDouCNav1MessagePtr(new ClearAllModificationsToBeiDouCNav1Message());
    }

    ClearAllModificationsToBeiDouCNav1MessagePtr ClearAllModificationsToBeiDouCNav1Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearAllModificationsToBeiDouCNav1Message>(ptr);
    }

    bool ClearAllModificationsToBeiDouCNav1Message::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ClearAllModificationsToBeiDouCNav1Message::documentation() const { return Documentation; }


    int ClearAllModificationsToBeiDouCNav1Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
