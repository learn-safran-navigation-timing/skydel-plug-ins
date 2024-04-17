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
    /// Result of IsNmeaMessageEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------------------------------------
    /// Message string The NMEA message to enable. Accepted values are:"GSV", "GNS", "GSA" or "All".
    /// Enabled bool   Message is enabled when value is True.
    ///

    class IsNmeaMessageEnabledResult;
    typedef std::shared_ptr<IsNmeaMessageEnabledResult> IsNmeaMessageEnabledResultPtr;
    
    
    class IsNmeaMessageEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsNmeaMessageEnabledResult();

      IsNmeaMessageEnabledResult(const std::string& message, bool enabled);

      IsNmeaMessageEnabledResult(CommandBasePtr relatedCommand, const std::string& message, bool enabled);

      static IsNmeaMessageEnabledResultPtr create(const std::string& message, bool enabled);

      static IsNmeaMessageEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& message, bool enabled);
      static IsNmeaMessageEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** message ****
      std::string message() const;
      void setMessage(const std::string& message);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsNmeaMessageEnabledResult);
  }
}

