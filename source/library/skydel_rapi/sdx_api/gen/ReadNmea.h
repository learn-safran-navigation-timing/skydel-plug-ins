#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the next NMEA sentence.
    ///
    /// 
    ///

    class ReadNmea;
    typedef std::shared_ptr<ReadNmea> ReadNmeaPtr;
    
    
    class ReadNmea : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ReadNmea();

      static ReadNmeaPtr create();
      static ReadNmeaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

