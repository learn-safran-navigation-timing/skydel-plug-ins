#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsMNavMessage
///
#include "gen/GetGpsMNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsMNavMessage::CmdName = "GetGpsMNavMessage";
    const char* const GetGpsMNavMessage::Documentation = "Please note the command GetGpsMNavMessage is deprecated since 21.3. You may use GetMessageModificationToGpsMNav.\n\nGet infos about the MNAV Message with this id";

    REGISTER_COMMAND_FACTORY(GetGpsMNavMessage);


    GetGpsMNavMessage::GetGpsMNavMessage()
      : CommandBase(CmdName)
    {}

    GetGpsMNavMessage::GetGpsMNavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetGpsMNavMessagePtr GetGpsMNavMessage::create(const std::string& id)
    {
      return GetGpsMNavMessagePtr(new GetGpsMNavMessage(id));
    }

    GetGpsMNavMessagePtr GetGpsMNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsMNavMessage>(ptr);
    }

    bool GetGpsMNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsMNavMessage::documentation() const { return Documentation; }


    int GetGpsMNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsMNavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsMNavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
