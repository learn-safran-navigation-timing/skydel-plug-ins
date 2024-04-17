#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) the system tracked by the receiver.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------------------------------------------
    /// System  string System to enable. Accepted values are:"GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "All".
    /// Enabled bool   System is tracked when value is True.
    ///

    class EnableSystemTracking;
    typedef std::shared_ptr<EnableSystemTracking> EnableSystemTrackingPtr;
    
    
    class EnableSystemTracking : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSystemTracking();

      EnableSystemTracking(const std::string& system, bool enabled);

      static EnableSystemTrackingPtr create(const std::string& system, bool enabled);
      static EnableSystemTrackingPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

