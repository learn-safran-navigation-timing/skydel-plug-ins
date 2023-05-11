#pragma once

#include <memory>
#include "command_result.h"
#include "date.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLastLeapSecondDate.
    ///
    /// Name Type Description
    /// ---- ---- ----------------
    /// Date date Leap second date
    ///

    class GetLastLeapSecondDateResult;
    typedef std::shared_ptr<GetLastLeapSecondDateResult> GetLastLeapSecondDateResultPtr;
    
    
    class GetLastLeapSecondDateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetLastLeapSecondDateResult();

      GetLastLeapSecondDateResult(CommandBasePtr relatedCommand, const Sdx::Date& date);
  
      static GetLastLeapSecondDateResultPtr create(CommandBasePtr relatedCommand, const Sdx::Date& date);
      static GetLastLeapSecondDateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** date ****
      Sdx::Date date() const;
      void setDate(const Sdx::Date& date);
    };
  }
}

