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
    /// Result of GetTimingSystem.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------
    /// System string The timing system. Accepted values are:"GPS", "BeiDou" or "Galileo"
    ///

    class GetTimingSystemResult;
    typedef std::shared_ptr<GetTimingSystemResult> GetTimingSystemResultPtr;
    
    
    class GetTimingSystemResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetTimingSystemResult();

      GetTimingSystemResult(const std::string& system);

      GetTimingSystemResult(CommandBasePtr relatedCommand, const std::string& system);

      static GetTimingSystemResultPtr create(const std::string& system);

      static GetTimingSystemResultPtr create(CommandBasePtr relatedCommand, const std::string& system);
      static GetTimingSystemResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetTimingSystemResult);
  }
}

