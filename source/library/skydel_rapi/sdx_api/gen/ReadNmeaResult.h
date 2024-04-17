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
    /// Result of ReadNmea.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------
    /// NmeaMessage string Nmea message.
    ///

    class ReadNmeaResult;
    typedef std::shared_ptr<ReadNmeaResult> ReadNmeaResultPtr;
    
    
    class ReadNmeaResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ReadNmeaResult();

      ReadNmeaResult(const std::string& nmeaMessage);

      ReadNmeaResult(CommandBasePtr relatedCommand, const std::string& nmeaMessage);

      static ReadNmeaResultPtr create(const std::string& nmeaMessage);

      static ReadNmeaResultPtr create(CommandBasePtr relatedCommand, const std::string& nmeaMessage);
      static ReadNmeaResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** nmeaMessage ****
      std::string nmeaMessage() const;
      void setNmeaMessage(const std::string& nmeaMessage);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(ReadNmeaResult);
  }
}

