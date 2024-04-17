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
    /// Result of GetSystemTracking.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------
    /// Systems array string The systems tracked.
    ///

    class GetSystemTrackingResult;
    typedef std::shared_ptr<GetSystemTrackingResult> GetSystemTrackingResultPtr;
    
    
    class GetSystemTrackingResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSystemTrackingResult();

      GetSystemTrackingResult(const std::vector<std::string>& systems);

      GetSystemTrackingResult(CommandBasePtr relatedCommand, const std::vector<std::string>& systems);

      static GetSystemTrackingResultPtr create(const std::vector<std::string>& systems);

      static GetSystemTrackingResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& systems);
      static GetSystemTrackingResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** systems ****
      std::vector<std::string> systems() const;
      void setSystems(const std::vector<std::string>& systems);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSystemTrackingResult);
  }
}

