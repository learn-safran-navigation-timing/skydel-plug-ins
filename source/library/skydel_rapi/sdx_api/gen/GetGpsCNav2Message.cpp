#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNav2Message
///
#include "gen/GetGpsCNav2Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNav2Message::CmdName = "GetGpsCNav2Message";
    const char* const GetGpsCNav2Message::Documentation = "Please note the command GetGpsCNav2Message is deprecated since 21.3. You may use GetMessageModificationToGpsCNav2.\n\nGet infos about the CNAV2 Message with this id";

    REGISTER_COMMAND_FACTORY(GetGpsCNav2Message);


    GetGpsCNav2Message::GetGpsCNav2Message()
      : CommandBase(CmdName)
    {}

    GetGpsCNav2Message::GetGpsCNav2Message(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetGpsCNav2MessagePtr GetGpsCNav2Message::create(const std::string& id)
    {
      return GetGpsCNav2MessagePtr(new GetGpsCNav2Message(id));
    }

    GetGpsCNav2MessagePtr GetGpsCNav2Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNav2Message>(ptr);
    }

    bool GetGpsCNav2Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsCNav2Message::documentation() const { return Documentation; }


    int GetGpsCNav2Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsCNav2Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsCNav2Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
