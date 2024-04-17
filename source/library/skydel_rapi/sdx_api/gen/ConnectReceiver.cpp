
#include "gen/ConnectReceiver.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ConnectReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ConnectReceiver::CmdName = "ConnectReceiver";
    const char* const ConnectReceiver::Documentation = "Connect to receiver.";

    REGISTER_COMMAND_TO_FACTORY_DECL(ConnectReceiver);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ConnectReceiver);


    ConnectReceiver::ConnectReceiver()
      : CommandBase(CmdName)
    {}

    ConnectReceiver::ConnectReceiver(const std::string& address)
      : CommandBase(CmdName)
    {

      setAddress(address);
    }

    ConnectReceiverPtr ConnectReceiver::create(const std::string& address)
    {
      return std::make_shared<ConnectReceiver>(address);
    }

    ConnectReceiverPtr ConnectReceiver::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ConnectReceiver>(ptr);
    }

    bool ConnectReceiver::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Address"])
        ;

    }

    std::string ConnectReceiver::documentation() const { return Documentation; }


    int ConnectReceiver::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string ConnectReceiver::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void ConnectReceiver::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
