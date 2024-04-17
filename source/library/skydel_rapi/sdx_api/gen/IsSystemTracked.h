#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the specified system is tracked.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------------------------------------------
    /// System string System to enable. Accepted values are:"GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "All".
    ///

    class IsSystemTracked;
    typedef std::shared_ptr<IsSystemTracked> IsSystemTrackedPtr;
    
    
    class IsSystemTracked : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSystemTracked();

      IsSystemTracked(const std::string& system);

      static IsSystemTrackedPtr create(const std::string& system);
      static IsSystemTrackedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

