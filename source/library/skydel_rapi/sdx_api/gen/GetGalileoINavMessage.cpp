#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoINavMessage
///
#include "gen/GetGalileoINavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoINavMessage::CmdName = "GetGalileoINavMessage";
    const char* const GetGalileoINavMessage::Documentation = "Please note the command GetGalileoINavMessage is deprecated since 21.3. You may use GetMessageModificationToGalileoINav.\n\nGet infos about the INAV Message with this id";

    REGISTER_COMMAND_FACTORY(GetGalileoINavMessage);


    GetGalileoINavMessage::GetGalileoINavMessage()
      : CommandBase(CmdName)
    {}

    GetGalileoINavMessage::GetGalileoINavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetGalileoINavMessagePtr GetGalileoINavMessage::create(const std::string& id)
    {
      return GetGalileoINavMessagePtr(new GetGalileoINavMessage(id));
    }

    GetGalileoINavMessagePtr GetGalileoINavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoINavMessage>(ptr);
    }

    bool GetGalileoINavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGalileoINavMessage::documentation() const { return Documentation; }


    int GetGalileoINavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGalileoINavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGalileoINavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
