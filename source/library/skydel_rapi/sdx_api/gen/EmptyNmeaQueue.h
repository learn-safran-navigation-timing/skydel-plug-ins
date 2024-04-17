#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Empty NMEA sentences queue.
    ///
    /// 
    ///

    class EmptyNmeaQueue;
    typedef std::shared_ptr<EmptyNmeaQueue> EmptyNmeaQueuePtr;
    
    
    class EmptyNmeaQueue : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EmptyNmeaQueue();

      static EmptyNmeaQueuePtr create();
      static EmptyNmeaQueuePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

