#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsUsingVelocityInSbasMessage25.
    ///
    /// Name        Type Description
    /// ----------- ---- --------------------------------------------------------
    /// UseVelocity bool Whether SBAS message 25 should send velocity corrections
    ///

    class IsUsingVelocityInSbasMessage25Result;
    typedef std::shared_ptr<IsUsingVelocityInSbasMessage25Result> IsUsingVelocityInSbasMessage25ResultPtr;
    
    
    class IsUsingVelocityInSbasMessage25Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsUsingVelocityInSbasMessage25Result();

      IsUsingVelocityInSbasMessage25Result(CommandBasePtr relatedCommand, bool useVelocity);
  
      static IsUsingVelocityInSbasMessage25ResultPtr create(CommandBasePtr relatedCommand, bool useVelocity);
      static IsUsingVelocityInSbasMessage25ResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** useVelocity ****
      bool useVelocity() const;
      void setUseVelocity(bool useVelocity);
    };
  }
}

