#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Reset the receiver.
    ///
    /// 
    ///

    class ResetReceiver;
    typedef std::shared_ptr<ResetReceiver> ResetReceiverPtr;
    
    
    class ResetReceiver : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetReceiver();

      static ResetReceiverPtr create();
      static ResetReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

