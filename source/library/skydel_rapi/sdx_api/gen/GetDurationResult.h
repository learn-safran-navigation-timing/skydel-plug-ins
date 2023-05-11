#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDuration.
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------
    /// Second int  The duration in seconds
    ///

    class GetDurationResult;
    typedef std::shared_ptr<GetDurationResult> GetDurationResultPtr;
    
    
    class GetDurationResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetDurationResult();

      GetDurationResult(int second);

      GetDurationResult(CommandBasePtr relatedCommand, int second);

      static GetDurationResultPtr create(int second);

      static GetDurationResultPtr create(CommandBasePtr relatedCommand, int second);
      static GetDurationResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** second ****
      int second() const;
      void setSecond(int second);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetDurationResult);
  }
}

