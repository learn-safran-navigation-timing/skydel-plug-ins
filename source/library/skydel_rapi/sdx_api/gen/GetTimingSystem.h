#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns the selected timing system.
    ///
    /// 
    ///

    class GetTimingSystem;
    typedef std::shared_ptr<GetTimingSystem> GetTimingSystemPtr;
    
    
    class GetTimingSystem : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetTimingSystem();

      static GetTimingSystemPtr create();
      static GetTimingSystemPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

