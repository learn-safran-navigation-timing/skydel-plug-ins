#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasDeltaUdreiOutsideOfRegions.
    ///
    /// Name            Type   Description
    /// --------------- ------ ----------------------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// DeltaUdrei      int    Delta UDREI applicable outside all the defined regions. Accepted range is [0..15].
    ///

    class GetSbasDeltaUdreiOutsideOfRegionsResult;
    typedef std::shared_ptr<GetSbasDeltaUdreiOutsideOfRegionsResult> GetSbasDeltaUdreiOutsideOfRegionsResultPtr;
    
    
    class GetSbasDeltaUdreiOutsideOfRegionsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasDeltaUdreiOutsideOfRegionsResult();

      GetSbasDeltaUdreiOutsideOfRegionsResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei);
  
      static GetSbasDeltaUdreiOutsideOfRegionsResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei);
      static GetSbasDeltaUdreiOutsideOfRegionsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** deltaUdrei ****
      int deltaUdrei() const;
      void setDeltaUdrei(int deltaUdrei);
    };
  }
}

