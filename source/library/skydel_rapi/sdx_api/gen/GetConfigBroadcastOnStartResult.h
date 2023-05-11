#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetConfigBroadcastOnStart.
    ///
    /// Name             Type Description
    /// ---------------- ---- --------------------------------------------------------------
    /// BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.
    ///

    class GetConfigBroadcastOnStartResult;
    typedef std::shared_ptr<GetConfigBroadcastOnStartResult> GetConfigBroadcastOnStartResultPtr;
    
    
    class GetConfigBroadcastOnStartResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetConfigBroadcastOnStartResult();

      GetConfigBroadcastOnStartResult(CommandBasePtr relatedCommand, bool broadcastOnStart);
  
      static GetConfigBroadcastOnStartResultPtr create(CommandBasePtr relatedCommand, bool broadcastOnStart);
      static GetConfigBroadcastOnStartResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** broadcastOnStart ****
      bool broadcastOnStart() const;
      void setBroadcastOnStart(bool broadcastOnStart);
    };
  }
}

