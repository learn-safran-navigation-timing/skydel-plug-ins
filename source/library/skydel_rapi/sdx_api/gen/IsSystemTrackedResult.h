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
    /// Result of IsSystemTracked.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------------------------------------------
    /// System  string System to enable. Accepted values are:"GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "All".
    /// Enabled bool   System is tracked when value is True.
    ///

    class IsSystemTrackedResult;
    typedef std::shared_ptr<IsSystemTrackedResult> IsSystemTrackedResultPtr;
    
    
    class IsSystemTrackedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSystemTrackedResult();

      IsSystemTrackedResult(const std::string& system, bool enabled);

      IsSystemTrackedResult(CommandBasePtr relatedCommand, const std::string& system, bool enabled);

      static IsSystemTrackedResultPtr create(const std::string& system, bool enabled);

      static IsSystemTrackedResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool enabled);
      static IsSystemTrackedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsSystemTrackedResult);
  }
}

