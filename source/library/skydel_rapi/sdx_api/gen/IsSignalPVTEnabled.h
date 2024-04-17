#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the specified signal is used for PVT.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Signal to use. Accepted values are:"GPSL1CA", "GPSL1C", "GPSL1PY", "GPSL1MY", "GPSL2C", "GPSL2PY", "GPSL2MY", "GPSL5", "GLOL1CA", "GLOL2CA", "GALL1BC", "GALE1PRS", "GALE5a", "GALE5b", "GALE5", "GALE6BC", "GALE6PRS", "BDSB1I", "BDSB2I", "BDSB2a", "BDSB1C", "GEOL1", "GEOL5", "QZSL1CA", "QZSL1C", "QZSL2C", "QZSL5", "QZSL1S", "QZSL5S", "NAVICL5" or "ALL".
    ///

    class IsSignalPVTEnabled;
    typedef std::shared_ptr<IsSignalPVTEnabled> IsSignalPVTEnabledPtr;
    
    
    class IsSignalPVTEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalPVTEnabled();

      IsSignalPVTEnabled(const std::string& signal);

      static IsSignalPVTEnabledPtr create(const std::string& signal);
      static IsSignalPVTEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
    
  }
}

