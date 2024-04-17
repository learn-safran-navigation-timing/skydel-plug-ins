
#include "gen/EmptyNmeaQueue.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EmptyNmeaQueue
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EmptyNmeaQueue::CmdName = "EmptyNmeaQueue";
    const char* const EmptyNmeaQueue::Documentation = "Empty NMEA sentences queue.";

    REGISTER_COMMAND_TO_FACTORY_DECL(EmptyNmeaQueue);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EmptyNmeaQueue);


    EmptyNmeaQueue::EmptyNmeaQueue()
      : CommandBase(CmdName)
    {

    }

    EmptyNmeaQueuePtr EmptyNmeaQueue::create()
    {
      return std::make_shared<EmptyNmeaQueue>();
    }

    EmptyNmeaQueuePtr EmptyNmeaQueue::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EmptyNmeaQueue>(ptr);
    }

    bool EmptyNmeaQueue::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string EmptyNmeaQueue::documentation() const { return Documentation; }


    int EmptyNmeaQueue::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
