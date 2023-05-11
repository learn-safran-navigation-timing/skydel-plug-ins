#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSignalStrengthModelEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// Enabled bool If true, signal strengh model is enabled for all satellites
    ///

    class IsSignalStrengthModelEnabledResult;
    typedef std::shared_ptr<IsSignalStrengthModelEnabledResult> IsSignalStrengthModelEnabledResultPtr;
    
    
    class IsSignalStrengthModelEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalStrengthModelEnabledResult();

      IsSignalStrengthModelEnabledResult(CommandBasePtr relatedCommand, bool enabled);
  
      static IsSignalStrengthModelEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsSignalStrengthModelEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

