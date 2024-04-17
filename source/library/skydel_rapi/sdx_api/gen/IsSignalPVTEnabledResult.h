#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSignalPVTEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal  string Signal to use. Accepted values are:"GPSL1CA", "GPSL1C", "GPSL1PY", "GPSL1MY", "GPSL2C", "GPSL2PY", "GPSL2MY", "GPSL5", "GLOL1CA", "GLOL2CA", "GALL1BC", "GALE1PRS", "GALE5a", "GALE5b", "GALE5", "GALE6BC", "GALE6PRS", "BDSB1I", "BDSB2I", "BDSB2a", "BDSB1C", "GEOL1", "GEOL5", "QZSL1CA", "QZSL1C", "QZSL2C", "QZSL5", "QZSL1S", "QZSL5S", "NAVICL5" or "ALL".
    /// Enabled bool   Signal is used when value is True.
    ///

    class IsSignalPVTEnabledResult;
    typedef std::shared_ptr<IsSignalPVTEnabledResult> IsSignalPVTEnabledResultPtr;
    
    
    class IsSignalPVTEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalPVTEnabledResult();

      IsSignalPVTEnabledResult(const std::string& signal, bool enabled);

      IsSignalPVTEnabledResult(CommandBasePtr relatedCommand, const std::string& signal, bool enabled);

      static IsSignalPVTEnabledResultPtr create(const std::string& signal, bool enabled);

      static IsSignalPVTEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, bool enabled);
      static IsSignalPVTEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsSignalPVTEnabledResult);
  }
}

