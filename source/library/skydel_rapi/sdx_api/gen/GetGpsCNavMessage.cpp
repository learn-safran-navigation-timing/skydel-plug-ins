#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavMessage
///
#include "gen/GetGpsCNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavMessage::CmdName = "GetGpsCNavMessage";
    const char* const GetGpsCNavMessage::Documentation = "Please note the command GetGpsCNavMessage is deprecated since 21.3. You may use GetMessageModificationToGpsCNav.\n\nGet infos about the CNAV Message with this id";

    REGISTER_COMMAND_FACTORY(GetGpsCNavMessage);


    GetGpsCNavMessage::GetGpsCNavMessage()
      : CommandBase(CmdName)
    {}

    GetGpsCNavMessage::GetGpsCNavMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetGpsCNavMessagePtr GetGpsCNavMessage::create(const std::string& id)
    {
      return GetGpsCNavMessagePtr(new GetGpsCNavMessage(id));
    }

    GetGpsCNavMessagePtr GetGpsCNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNavMessage>(ptr);
    }

    bool GetGpsCNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsCNavMessage::documentation() const { return Documentation; }


    int GetGpsCNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsCNavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsCNavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
