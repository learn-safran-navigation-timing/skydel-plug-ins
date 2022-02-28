#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of HilPortResult
///
#include "gen/HilPortResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const HilPortResult::CmdName = "HilPortResult";
    const char* const HilPortResult::Documentation = "Result of GetHilPort.";

    REGISTER_COMMAND_RESULT_FACTORY(HilPortResult);


    HilPortResult::HilPortResult()
      : CommandResult(CmdName)
    {}

    HilPortResult::HilPortResult(CommandBasePtr relatedCommand, int port)
      : CommandResult(CmdName, relatedCommand)
    {

      setPort(port);
    }


    HilPortResultPtr HilPortResult::create(CommandBasePtr relatedCommand, int port)
    {
      return std::make_shared<HilPortResult>(relatedCommand, port);
    }

    HilPortResultPtr HilPortResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<HilPortResult>(ptr);
    }

    bool HilPortResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Port"])
        ;

    }

    std::string HilPortResult::documentation() const { return Documentation; }


    int HilPortResult::port() const
    {
      return parse_json<int>::parse(m_values["Port"]);
    }

    void HilPortResult::setPort(int port)
    {
      m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
