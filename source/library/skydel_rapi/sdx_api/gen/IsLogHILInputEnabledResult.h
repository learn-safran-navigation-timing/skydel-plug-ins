#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogHILInputEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------
    /// Enabled bool If true, files will be created during simulation
    ///

    class IsLogHILInputEnabledResult;
    typedef std::shared_ptr<IsLogHILInputEnabledResult> IsLogHILInputEnabledResultPtr;
    
    
    class IsLogHILInputEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLogHILInputEnabledResult();

      IsLogHILInputEnabledResult(CommandBasePtr relatedCommand, bool enabled);
  
      static IsLogHILInputEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsLogHILInputEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

