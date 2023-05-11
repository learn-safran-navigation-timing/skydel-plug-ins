#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSpectrumVisible.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------
    /// Visible bool Show spectrum flag
    ///

    class IsSpectrumVisibleResult;
    typedef std::shared_ptr<IsSpectrumVisibleResult> IsSpectrumVisibleResultPtr;
    
    
    class IsSpectrumVisibleResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSpectrumVisibleResult();

      IsSpectrumVisibleResult(CommandBasePtr relatedCommand, bool visible);
  
      static IsSpectrumVisibleResultPtr create(CommandBasePtr relatedCommand, bool visible);
      static IsSpectrumVisibleResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** visible ****
      bool visible() const;
      void setVisible(bool visible);
    };
  }
}

