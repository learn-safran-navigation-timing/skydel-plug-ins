#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLogNmeaRate.
    ///
    /// Name Type Description
    /// ---- ---- ------------------------------
    /// Rate int  Accepted rates are 1 and 10 Hz
    ///

    class LogNmeaRateResult;
    typedef std::shared_ptr<LogNmeaRateResult> LogNmeaRateResultPtr;
    
    
    class LogNmeaRateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      LogNmeaRateResult();

      LogNmeaRateResult(int rate);

      LogNmeaRateResult(CommandBasePtr relatedCommand, int rate);

      static LogNmeaRateResultPtr create(int rate);

      static LogNmeaRateResultPtr create(CommandBasePtr relatedCommand, int rate);
      static LogNmeaRateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** rate ****
      int rate() const;
      void setRate(int rate);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(LogNmeaRateResult);
  }
}

