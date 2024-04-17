#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Overrides the currently tracked signals.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signals array string Signals to track. Accepted values are:"GPSL1CA", "GPSL1C", "GPSL1PY", "GPSL1MY", "GPSL2C", "GPSL2PY", "GPSL2MY", "GPSL5", "GLOL1CA", "GLOL2CA", "GALL1BC", "GALE1PRS", "GALE5a", "GALE5b", "GALE5", "GALE6BC", "GALE6PRS", "BDSB1I", "BDSB2I", "BDSB2a", "BDSB1C", "GEOL1", "GEOL5", "QZSL1CA", "QZSL1C", "QZSL2C", "QZSL5", "QZSL1S", "QZSL5S", "NAVICL5" or "ALL".
    ///

    class OverrideTrackedSignals;
    typedef std::shared_ptr<OverrideTrackedSignals> OverrideTrackedSignalsPtr;
    
    
    class OverrideTrackedSignals : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      OverrideTrackedSignals();

      OverrideTrackedSignals(const std::vector<std::string>& signals);

      static OverrideTrackedSignalsPtr create(const std::vector<std::string>& signals);
      static OverrideTrackedSignalsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signals ****
      std::vector<std::string> signals() const;
      void setSignals(const std::vector<std::string>& signals);
    };
    
  }
}

