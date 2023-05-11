#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasMessageUpdateInterval.
    ///
    /// Name           Type Description
    /// -------------- ---- -----------------------------------------------------------------------------------------------
    /// Message        int  The message type.
    /// UpdateInterval int  The message update interval in seconds. Accepted range is [6..300] and must be a multiple of 6.
    ///

    class GetSbasMessageUpdateIntervalResult;
    typedef std::shared_ptr<GetSbasMessageUpdateIntervalResult> GetSbasMessageUpdateIntervalResultPtr;
    
    
    class GetSbasMessageUpdateIntervalResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasMessageUpdateIntervalResult();

      GetSbasMessageUpdateIntervalResult(CommandBasePtr relatedCommand, int message, int updateInterval);
  
      static GetSbasMessageUpdateIntervalResultPtr create(CommandBasePtr relatedCommand, int message, int updateInterval);
      static GetSbasMessageUpdateIntervalResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** message ****
      int message() const;
      void setMessage(int message);


      // **** updateInterval ****
      int updateInterval() const;
      void setUpdateInterval(int updateInterval);
    };
  }
}

