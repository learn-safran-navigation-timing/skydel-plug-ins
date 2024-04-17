#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns all the systems tracked.
    ///
    /// 
    ///

    class GetSystemTracking;
    typedef std::shared_ptr<GetSystemTracking> GetSystemTrackingPtr;
    
    
    class GetSystemTracking : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSystemTracking();

      static GetSystemTrackingPtr create();
      static GetSystemTrackingPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

