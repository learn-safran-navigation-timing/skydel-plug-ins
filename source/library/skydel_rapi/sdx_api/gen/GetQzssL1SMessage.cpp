#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1SMessage
///
#include "gen/GetQzssL1SMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1SMessage::CmdName = "GetQzssL1SMessage";
    const char* const GetQzssL1SMessage::Documentation = "Please note the command GetQzssL1SMessage is deprecated since 21.3. You may use GetMessageModificationToQzssSlas.\n\nGet infos about the L1S Message with this id";

    REGISTER_COMMAND_FACTORY(GetQzssL1SMessage);


    GetQzssL1SMessage::GetQzssL1SMessage()
      : CommandBase(CmdName)
    {}

    GetQzssL1SMessage::GetQzssL1SMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetQzssL1SMessagePtr GetQzssL1SMessage::create(const std::string& id)
    {
      return GetQzssL1SMessagePtr(new GetQzssL1SMessage(id));
    }

    GetQzssL1SMessagePtr GetQzssL1SMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1SMessage>(ptr);
    }

    bool GetQzssL1SMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetQzssL1SMessage::documentation() const { return Documentation; }


    int GetQzssL1SMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssL1SMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetQzssL1SMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
