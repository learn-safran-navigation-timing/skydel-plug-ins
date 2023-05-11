#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsAttitudeToZeroForced.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------
    /// Enabled bool If true, vehicle won't rotate during simulation
    ///

    class IsAttitudeToZeroForcedResult;
    typedef std::shared_ptr<IsAttitudeToZeroForcedResult> IsAttitudeToZeroForcedResultPtr;
    
    
    class IsAttitudeToZeroForcedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsAttitudeToZeroForcedResult();

      IsAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled);
  
      static IsAttitudeToZeroForcedResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsAttitudeToZeroForcedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

