#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Disconnect the receiver.
    ///
    /// 
    ///

    class DisconnectReceiver;
    typedef std::shared_ptr<DisconnectReceiver> DisconnectReceiverPtr;
    
    
    class DisconnectReceiver : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      DisconnectReceiver();

      static DisconnectReceiverPtr create();
      static DisconnectReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

