#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes an interference. When adding an event, the simulator
    /// sets the Id parameter. Use that Id here to remove the associated interference.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------------------------
    /// Id   string Unique identifier of the interference to remove.
    ///

    class RemoveInterference;
    typedef std::shared_ptr<RemoveInterference> RemoveInterferencePtr;
    
    
    class RemoveInterference : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveInterference();

      RemoveInterference(const std::string& id);
  
      static RemoveInterferencePtr create(const std::string& id);
      static RemoveInterferencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

