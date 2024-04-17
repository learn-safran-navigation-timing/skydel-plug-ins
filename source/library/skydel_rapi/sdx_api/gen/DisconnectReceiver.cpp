
#include "gen/DisconnectReceiver.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of DisconnectReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DisconnectReceiver::CmdName = "DisconnectReceiver";
    const char* const DisconnectReceiver::Documentation = "Disconnect the receiver.";

    REGISTER_COMMAND_TO_FACTORY_DECL(DisconnectReceiver);
    REGISTER_COMMAND_TO_FACTORY_IMPL(DisconnectReceiver);


    DisconnectReceiver::DisconnectReceiver()
      : CommandBase(CmdName)
    {

    }

    DisconnectReceiverPtr DisconnectReceiver::create()
    {
      return std::make_shared<DisconnectReceiver>();
    }

    DisconnectReceiverPtr DisconnectReceiver::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DisconnectReceiver>(ptr);
    }

    bool DisconnectReceiver::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string DisconnectReceiver::documentation() const { return Documentation; }


    int DisconnectReceiver::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
