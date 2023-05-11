#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSpoofTxIgnoreRxAntennaGainPattern.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class IsSpoofTxIgnoreRxAntennaGainPatternResult;
    typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaGainPatternResult> IsSpoofTxIgnoreRxAntennaGainPatternResultPtr;
    
    
    class IsSpoofTxIgnoreRxAntennaGainPatternResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSpoofTxIgnoreRxAntennaGainPatternResult();

      IsSpoofTxIgnoreRxAntennaGainPatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id);
  
      static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr create(CommandBasePtr relatedCommand, bool ignore, const std::string& id);
      static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr dynamicCast(CommandBasePtr ptr);
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

