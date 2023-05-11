#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsStopMasterWhenSlaveStop.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Enabled bool Enable master stop when slave fail flag
    ///

    class IsStopMasterWhenSlaveStopResult;
    typedef std::shared_ptr<IsStopMasterWhenSlaveStopResult> IsStopMasterWhenSlaveStopResultPtr;
    
    
    class IsStopMasterWhenSlaveStopResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsStopMasterWhenSlaveStopResult();

      IsStopMasterWhenSlaveStopResult(CommandBasePtr relatedCommand, bool enabled);
  
      static IsStopMasterWhenSlaveStopResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsStopMasterWhenSlaveStopResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

