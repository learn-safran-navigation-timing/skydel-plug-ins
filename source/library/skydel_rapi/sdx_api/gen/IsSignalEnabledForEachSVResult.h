#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSignalEnabledForEachSV.
    ///
    /// Name    Type       Description
    /// ------- ---------- --------------------------------------------------------------------------------------------------------------
    /// Signal  string     Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                          "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                          "B1", "B2", "B1C", "B2a", "SBASL1", "SBASL5", "QZSSL1CA",
    ///                                          "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).
    ///

    class IsSignalEnabledForEachSVResult;
    typedef std::shared_ptr<IsSignalEnabledForEachSVResult> IsSignalEnabledForEachSVResultPtr;
    
    
    class IsSignalEnabledForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalEnabledForEachSVResult();

      IsSignalEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);
  
      static IsSignalEnabledForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);
      static IsSignalEnabledForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
  }
}

