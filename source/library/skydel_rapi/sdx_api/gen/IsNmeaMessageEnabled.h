#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the specified NMEA message is enabled.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------------------------------------
    /// Message string The NMEA message to enable. Accepted values are:"GSV", "GNS", "GSA" or "All".
    ///

    class IsNmeaMessageEnabled;
    typedef std::shared_ptr<IsNmeaMessageEnabled> IsNmeaMessageEnabledPtr;
    
    
    class IsNmeaMessageEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsNmeaMessageEnabled();

      IsNmeaMessageEnabled(const std::string& message);

      static IsNmeaMessageEnabledPtr create(const std::string& message);
      static IsNmeaMessageEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** message ****
      std::string message() const;
      void setMessage(const std::string& message);
    };
    
  }
}

