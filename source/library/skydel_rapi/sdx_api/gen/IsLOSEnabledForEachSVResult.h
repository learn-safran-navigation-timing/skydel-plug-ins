#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLOSEnabledForEachSV.
    ///
    /// Name    Type       Description
    /// ------- ---------- -----------------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool Direct Line of Sight enabled or not. Zero based index (index 0 => SV ID 1, index 1 => second SV ID 2, etc).
    ///

    class IsLOSEnabledForEachSVResult;
    typedef std::shared_ptr<IsLOSEnabledForEachSVResult> IsLOSEnabledForEachSVResultPtr;
    
    
    class IsLOSEnabledForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsLOSEnabledForEachSVResult();

      IsLOSEnabledForEachSVResult(const std::string& system, const std::vector<bool>& enabled);

      IsLOSEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);

      static IsLOSEnabledForEachSVResultPtr create(const std::string& system, const std::vector<bool>& enabled);

      static IsLOSEnabledForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
      static IsLOSEnabledForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsLOSEnabledForEachSVResult);
  }
}

