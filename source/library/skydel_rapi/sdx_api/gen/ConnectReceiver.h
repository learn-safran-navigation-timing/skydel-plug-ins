#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Connect to receiver.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------
    /// Address string Receiver IP address.
    ///

    class ConnectReceiver;
    typedef std::shared_ptr<ConnectReceiver> ConnectReceiverPtr;
    
    
    class ConnectReceiver : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ConnectReceiver();

      ConnectReceiver(const std::string& address);

      static ConnectReceiverPtr create(const std::string& address);
      static ConnectReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** address ****
      std::string address() const;
      void setAddress(const std::string& address);
    };
    
  }
}

