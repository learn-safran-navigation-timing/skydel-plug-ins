#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSpoofTxIgnoreRxAntennaPhasePattern.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna phase pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class IsSpoofTxIgnoreRxAntennaPhasePatternResult;
    typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaPhasePatternResult> IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr;
    
    
    class IsSpoofTxIgnoreRxAntennaPhasePatternResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSpoofTxIgnoreRxAntennaPhasePatternResult();

      IsSpoofTxIgnoreRxAntennaPhasePatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id);
  
      static IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr create(CommandBasePtr relatedCommand, bool ignore, const std::string& id);
      static IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ignore ****
      bool ignore() const;
      void setIgnore(bool ignore);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

