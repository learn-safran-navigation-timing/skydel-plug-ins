#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPowerSbasOffset.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------
    /// ServiceProvider string Service Provider key, allowed values: "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM"
    /// Offset          double Offset in dB (negative value will attenuate signal)
    ///

    class GetPowerSbasOffsetResult;
    typedef std::shared_ptr<GetPowerSbasOffsetResult> GetPowerSbasOffsetResultPtr;
    
    
    class GetPowerSbasOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPowerSbasOffsetResult();

      GetPowerSbasOffsetResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, double offset);
  
      static GetPowerSbasOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, double offset);
      static GetPowerSbasOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
  }
}

