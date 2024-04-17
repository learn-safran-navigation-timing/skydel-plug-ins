#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNmeaOutputs.
    ///
    /// Name      Type         Description
    /// --------- ------------ ------------------------------
    /// NmeaOutps array string The enabled nmea output types.
    ///

    class GetNmeaOutputsResult;
    typedef std::shared_ptr<GetNmeaOutputsResult> GetNmeaOutputsResultPtr;
    
    
    class GetNmeaOutputsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNmeaOutputsResult();

      GetNmeaOutputsResult(const std::vector<std::string>& nmeaOutps);

      GetNmeaOutputsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& nmeaOutps);

      static GetNmeaOutputsResultPtr create(const std::vector<std::string>& nmeaOutps);

      static GetNmeaOutputsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& nmeaOutps);
      static GetNmeaOutputsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** nmeaOutps ****
      std::vector<std::string> nmeaOutps() const;
      void setNmeaOutps(const std::vector<std::string>& nmeaOutps);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNmeaOutputsResult);
  }
}

