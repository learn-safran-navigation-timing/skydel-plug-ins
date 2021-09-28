#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD2NavigationMessage
///
#include "gen/GetBeiDouD2NavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD2NavigationMessage::CmdName = "GetBeiDouD2NavigationMessage";
    const char* const GetBeiDouD2NavigationMessage::Documentation = "Please note the command GetBeiDouD2NavigationMessage is deprecated since 21.3. You may use GetMessageModificationToBeiDouD2Nav.\n\nGet infos about this modification BeiDou D2 navigation message event";

    REGISTER_COMMAND_FACTORY(GetBeiDouD2NavigationMessage);


    GetBeiDouD2NavigationMessage::GetBeiDouD2NavigationMessage()
      : CommandBase(CmdName)
    {}

    GetBeiDouD2NavigationMessage::GetBeiDouD2NavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetBeiDouD2NavigationMessagePtr GetBeiDouD2NavigationMessage::create(const std::string& id)
    {
      return GetBeiDouD2NavigationMessagePtr(new GetBeiDouD2NavigationMessage(id));
    }

    GetBeiDouD2NavigationMessagePtr GetBeiDouD2NavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD2NavigationMessage>(ptr);
    }

    bool GetBeiDouD2NavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetBeiDouD2NavigationMessage::documentation() const { return Documentation; }


    int GetBeiDouD2NavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouD2NavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouD2NavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
