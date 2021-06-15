#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavigationMessage
///
#include "gen/GetGpsNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavigationMessage::CmdName = "GetGpsNavigationMessage";
    const char* const GetGpsNavigationMessage::Documentation = "Please note the command GetGpsNavigationMessage is deprecated since 21.3. You may use GetMessageModificationToGpsLNav.\n\nGet infos about this modification gps navigation message event.";

    REGISTER_COMMAND_FACTORY(GetGpsNavigationMessage);


    GetGpsNavigationMessage::GetGpsNavigationMessage()
      : CommandBase(CmdName)
    {}

    GetGpsNavigationMessage::GetGpsNavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetGpsNavigationMessagePtr GetGpsNavigationMessage::create(const std::string& id)
    {
      return GetGpsNavigationMessagePtr(new GetGpsNavigationMessage(id));
    }

    GetGpsNavigationMessagePtr GetGpsNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavigationMessage>(ptr);
    }

    bool GetGpsNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsNavigationMessage::documentation() const { return Documentation; }


    int GetGpsNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
