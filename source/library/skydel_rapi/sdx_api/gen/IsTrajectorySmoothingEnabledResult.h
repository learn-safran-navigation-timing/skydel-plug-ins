#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsTrajectorySmoothingEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------
    /// Enabled bool If true, trajectory will be smoothed during simulation
    ///

    class IsTrajectorySmoothingEnabledResult;
    typedef std::shared_ptr<IsTrajectorySmoothingEnabledResult> IsTrajectorySmoothingEnabledResultPtr;
    
    
    class IsTrajectorySmoothingEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsTrajectorySmoothingEnabledResult();

      IsTrajectorySmoothingEnabledResult(bool enabled);

      IsTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsTrajectorySmoothingEnabledResultPtr create(bool enabled);

      static IsTrajectorySmoothingEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsTrajectorySmoothingEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsTrajectorySmoothingEnabledResult);
  }
}

