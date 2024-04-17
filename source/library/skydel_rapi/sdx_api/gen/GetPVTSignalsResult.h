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
    /// Result of GetPVTSignals.
    ///
    /// Name    Type         Description
    /// ------- ------------ -------------------------
    /// Signals array string The signals used for PVT.
    ///

    class GetPVTSignalsResult;
    typedef std::shared_ptr<GetPVTSignalsResult> GetPVTSignalsResultPtr;
    
    
    class GetPVTSignalsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPVTSignalsResult();

      GetPVTSignalsResult(const std::vector<std::string>& signals);

      GetPVTSignalsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signals);

      static GetPVTSignalsResultPtr create(const std::vector<std::string>& signals);

      static GetPVTSignalsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signals);
      static GetPVTSignalsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signals ****
      std::vector<std::string> signals() const;
      void setSignals(const std::vector<std::string>& signals);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPVTSignalsResult);
  }
}

