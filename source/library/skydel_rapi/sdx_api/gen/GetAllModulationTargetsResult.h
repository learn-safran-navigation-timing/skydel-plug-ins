#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAllModulationTargets.
    ///
    /// Name Type         Description
    /// ---- ------------ ---------------
    /// Ids  array string list of all IDs
    ///

    class GetAllModulationTargetsResult;
    typedef std::shared_ptr<GetAllModulationTargetsResult> GetAllModulationTargetsResultPtr;
    
    
    class GetAllModulationTargetsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllModulationTargetsResult();

      GetAllModulationTargetsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetAllModulationTargetsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllModulationTargetsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

