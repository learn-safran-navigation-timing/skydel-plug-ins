#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns all the signals used for PVT.
    ///
    /// 
    ///

    class GetPVTSignals;
    typedef std::shared_ptr<GetPVTSignals> GetPVTSignalsPtr;
    
    
    class GetPVTSignals : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPVTSignals();

      static GetPVTSignalsPtr create();
      static GetPVTSignalsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

