#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Select the timing system used. Default is GPS.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------
    /// System string The timing system. Accepted values are:"GPS", "BeiDou" or "Galileo"
    ///

    class SetTimingSystem;
    typedef std::shared_ptr<SetTimingSystem> SetTimingSystemPtr;
    
    
    class SetTimingSystem : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetTimingSystem();

      SetTimingSystem(const std::string& system);

      static SetTimingSystemPtr create(const std::string& system);
      static SetTimingSystemPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

