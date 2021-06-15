#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICL5Message
///
#include "gen/GetNavICL5Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICL5Message::CmdName = "GetNavICL5Message";
    const char* const GetNavICL5Message::Documentation = "Please note the command GetNavICL5Message is deprecated since 21.3. You may use GetMessageModificationToNavICNav.\n\nGet infos about the NAV Message with this id";

    REGISTER_COMMAND_FACTORY(GetNavICL5Message);


    GetNavICL5Message::GetNavICL5Message()
      : CommandBase(CmdName)
    {}

    GetNavICL5Message::GetNavICL5Message(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetNavICL5MessagePtr GetNavICL5Message::create(const std::string& id)
    {
      return GetNavICL5MessagePtr(new GetNavICL5Message(id));
    }

    GetNavICL5MessagePtr GetNavICL5Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICL5Message>(ptr);
    }

    bool GetNavICL5Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetNavICL5Message::documentation() const { return Documentation; }


    int GetNavICL5Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetNavICL5Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetNavICL5Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
