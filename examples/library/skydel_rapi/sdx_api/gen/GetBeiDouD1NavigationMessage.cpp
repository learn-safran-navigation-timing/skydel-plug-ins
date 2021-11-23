#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD1NavigationMessage
///
#include "gen/GetBeiDouD1NavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD1NavigationMessage::CmdName = "GetBeiDouD1NavigationMessage";
    const char* const GetBeiDouD1NavigationMessage::Documentation = "Please note the command GetBeiDouD1NavigationMessage is deprecated since 21.3. You may use GetMessageModificationToBeiDouD1Nav.\n\nGet infos about this modification BeiDou D1 navigation message event";

    REGISTER_COMMAND_FACTORY(GetBeiDouD1NavigationMessage);


    GetBeiDouD1NavigationMessage::GetBeiDouD1NavigationMessage()
      : CommandBase(CmdName)
    {}

    GetBeiDouD1NavigationMessage::GetBeiDouD1NavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetBeiDouD1NavigationMessagePtr GetBeiDouD1NavigationMessage::create(const std::string& id)
    {
      return GetBeiDouD1NavigationMessagePtr(new GetBeiDouD1NavigationMessage(id));
    }

    GetBeiDouD1NavigationMessagePtr GetBeiDouD1NavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD1NavigationMessage>(ptr);
    }

    bool GetBeiDouD1NavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetBeiDouD1NavigationMessage::documentation() const { return Documentation; }


    int GetBeiDouD1NavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouD1NavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouD1NavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
