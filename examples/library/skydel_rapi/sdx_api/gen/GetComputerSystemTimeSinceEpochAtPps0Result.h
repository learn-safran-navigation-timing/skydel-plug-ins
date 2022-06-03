#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetComputerSystemTimeSinceEpochAtPps0.
    ///
    /// Name         Type   Description
    /// ------------ ------ ---------------------------------------------------------
    /// Milliseconds double Computer system time since epoch at PPS0 in milliseconds.
    ///

    class GetComputerSystemTimeSinceEpochAtPps0Result;
    typedef std::shared_ptr<GetComputerSystemTimeSinceEpochAtPps0Result> GetComputerSystemTimeSinceEpochAtPps0ResultPtr;
    
    
    class GetComputerSystemTimeSinceEpochAtPps0Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetComputerSystemTimeSinceEpochAtPps0Result();

      GetComputerSystemTimeSinceEpochAtPps0Result(CommandBasePtr relatedCommand, double milliseconds);
  
      static GetComputerSystemTimeSinceEpochAtPps0ResultPtr create(CommandBasePtr relatedCommand, double milliseconds);
      static GetComputerSystemTimeSinceEpochAtPps0ResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** milliseconds ****
      double milliseconds() const;
      void setMilliseconds(double milliseconds);
    };
  }
}

