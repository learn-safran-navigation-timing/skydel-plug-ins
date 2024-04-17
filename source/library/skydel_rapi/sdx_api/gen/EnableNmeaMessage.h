#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) the NMEA message.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------------------------------------
    /// Message string The NMEA message to enable. Accepted values are:"GSV", "GNS", "GSA" or "All".
    /// Enabled bool   Message is enabled when value is True.
    ///

    class EnableNmeaMessage;
    typedef std::shared_ptr<EnableNmeaMessage> EnableNmeaMessagePtr;
    
    
    class EnableNmeaMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableNmeaMessage();

      EnableNmeaMessage(const std::string& message, bool enabled);

      static EnableNmeaMessagePtr create(const std::string& message, bool enabled);
      static EnableNmeaMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** message ****
      std::string message() const;
      void setMessage(const std::string& message);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

