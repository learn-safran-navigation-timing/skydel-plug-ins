#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetStartTimeOffset.
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------------------------------------------------
    /// Offset int  Time Offset, in seconds, between simulated GPS time and time given by GPS Timing receiver
    ///

    class GetStartTimeOffsetResult;
    typedef std::shared_ptr<GetStartTimeOffsetResult> GetStartTimeOffsetResultPtr;
    
    
    class GetStartTimeOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetStartTimeOffsetResult();

      GetStartTimeOffsetResult(CommandBasePtr relatedCommand, int offset);
  
      static GetStartTimeOffsetResultPtr create(CommandBasePtr relatedCommand, int offset);
      static GetStartTimeOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** offset ****
      int offset() const;
      void setOffset(int offset);
    };
  }
}

