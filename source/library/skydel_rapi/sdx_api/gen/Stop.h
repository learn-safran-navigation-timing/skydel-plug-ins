#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Stop the simulation.
    ///
    /// 
    ///

    class Stop;
    typedef std::shared_ptr<Stop> StopPtr;
    
    
    class Stop : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      Stop();
  
      static StopPtr create();
      static StopPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

