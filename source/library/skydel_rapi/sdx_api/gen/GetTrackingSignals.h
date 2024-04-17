#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns all the signals tracked.
    ///
    /// 
    ///

    class GetTrackingSignals;
    typedef std::shared_ptr<GetTrackingSignals> GetTrackingSignalsPtr;
    
    
    class GetTrackingSignals : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetTrackingSignals();

      static GetTrackingSignalsPtr create();
      static GetTrackingSignalsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

