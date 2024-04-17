
#include "gen/ResetReceiver.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetReceiver::CmdName = "ResetReceiver";
    const char* const ResetReceiver::Documentation = "Reset the receiver.";

    REGISTER_COMMAND_TO_FACTORY_DECL(ResetReceiver);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ResetReceiver);


    ResetReceiver::ResetReceiver()
      : CommandBase(CmdName)
    {

    }

    ResetReceiverPtr ResetReceiver::create()
    {
      return std::make_shared<ResetReceiver>();
    }

    ResetReceiverPtr ResetReceiver::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetReceiver>(ptr);
    }

    bool ResetReceiver::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ResetReceiver::documentation() const { return Documentation; }


    int ResetReceiver::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
