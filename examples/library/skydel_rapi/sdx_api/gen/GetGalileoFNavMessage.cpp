#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFNavMessage
///
#include "gen/GetGalileoFNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFNavMessage::CmdName = "GetGalileoFNavMessage";
    const char* const GetGalileoFNavMessage::Documentation = "Please note the command GetGalileoFNavMessage is deprecated since 21.3. You may use GetMessageModificationToGalileoFNav.\n\nGet infos about the FNAV Message with this id";

    REGISTER_COMMAND_FACTORY(GetGalileoFNavMessage);


    GetGalileoFNavMessage::GetGalileoFNavMessage()
      : CommandBase(CmdName)
    {}

    GetGalileoFNavMessage::GetGalileoFNavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetGalileoFNavMessagePtr GetGalileoFNavMessage::create(const std::string& id)
    {
      return GetGalileoFNavMessagePtr(new GetGalileoFNavMessage(id));
    }

    GetGalileoFNavMessagePtr GetGalileoFNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoFNavMessage>(ptr);
    }

    bool GetGalileoFNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGalileoFNavMessage::documentation() const { return Documentation; }


    int GetGalileoFNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGalileoFNavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGalileoFNavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
