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
    /// Result of GetTrackingSignals.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------
    /// Signals array string The signals tracked.
    ///

    class GetTrackingSignalsResult;
    typedef std::shared_ptr<GetTrackingSignalsResult> GetTrackingSignalsResultPtr;
    
    
    class GetTrackingSignalsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetTrackingSignalsResult();

      GetTrackingSignalsResult(const std::vector<std::string>& signals);

      GetTrackingSignalsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signals);

      static GetTrackingSignalsResultPtr create(const std::vector<std::string>& signals);

      static GetTrackingSignalsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signals);
      static GetTrackingSignalsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signals ****
      std::vector<std::string> signals() const;
      void setSignals(const std::vector<std::string>& signals);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetTrackingSignalsResult);
  }
}

