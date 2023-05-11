#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSimulationStopAtTrajectoryEndEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------------
    /// Enabled bool If true, simulation will stop when the vehicle will reach trajectory end
    ///

    class IsSimulationStopAtTrajectoryEndEnabledResult;
    typedef std::shared_ptr<IsSimulationStopAtTrajectoryEndEnabledResult> IsSimulationStopAtTrajectoryEndEnabledResultPtr;
    
    
    class IsSimulationStopAtTrajectoryEndEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSimulationStopAtTrajectoryEndEnabledResult();

      IsSimulationStopAtTrajectoryEndEnabledResult(CommandBasePtr relatedCommand, bool enabled);
  
      static IsSimulationStopAtTrajectoryEndEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsSimulationStopAtTrajectoryEndEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

