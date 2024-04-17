#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Wait until simulator has reached the specified substate unless simulator goes to error state or specified failure substate. Will return a SimulatorStateResult.
    /// Possible substates are :
    /// -None
    /// -Incomplete
    /// -Ready
    /// -Initializing
    /// -Armed
    /// -Streaming RF
    /// -Sync Worker Instance
    /// -WF Init (Worker)
    /// -WF Init (Main)
    /// -HIL Sync
    /// -Sync Init
    /// -Sync PPS Reset
    /// -Sync Start Time
    /// -Sync Start
    /// -Error
    ///
    /// Name         Type   Description
    /// ------------ ------ ----------------------------------------------------------
    /// State        string Simulator sub state string.
    /// FailureState string Abort waiting if simulator goes to this sub state instead.
    ///

    class WaitSimulatorState;
    typedef std::shared_ptr<WaitSimulatorState> WaitSimulatorStatePtr;
    
    
    class WaitSimulatorState : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      WaitSimulatorState();

      WaitSimulatorState(const std::string& state, const std::string& failureState);

      static WaitSimulatorStatePtr create(const std::string& state, const std::string& failureState);
      static WaitSimulatorStatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** state ****
      std::string state() const;
      void setState(const std::string& state);


      // **** failureState ****
      std::string failureState() const;
      void setFailureState(const std::string& failureState);
    };
    
  }
}

