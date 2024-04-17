#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns all the enabled nmea output types.
    ///
    /// 
    ///

    class GetNmeaOutputs;
    typedef std::shared_ptr<GetNmeaOutputs> GetNmeaOutputsPtr;
    
    
    class GetNmeaOutputs : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNmeaOutputs();

      static GetNmeaOutputsPtr create();
      static GetNmeaOutputsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

