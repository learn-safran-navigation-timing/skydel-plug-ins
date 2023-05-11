#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSimulationElapsedTime.
    ///
    /// Name         Type Description
    /// ------------ ---- -----------------------------------------------------------------------------
    /// Milliseconds int  Simulation elapsed time in milliseconds. Note: Resolution is limited to 10Hz.
    ///

    class SimulationElapsedTimeResult;
    typedef std::shared_ptr<SimulationElapsedTimeResult> SimulationElapsedTimeResultPtr;
    
    
    class SimulationElapsedTimeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SimulationElapsedTimeResult();

      SimulationElapsedTimeResult(CommandBasePtr relatedCommand, int milliseconds);
  
      static SimulationElapsedTimeResultPtr create(CommandBasePtr relatedCommand, int milliseconds);
      static SimulationElapsedTimeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** milliseconds ****
      int milliseconds() const;
      void setMilliseconds(int milliseconds);
    };
  }
}

