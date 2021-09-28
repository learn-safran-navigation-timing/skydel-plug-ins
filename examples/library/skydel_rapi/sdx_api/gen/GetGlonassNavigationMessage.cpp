#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassNavigationMessage
///
#include "gen/GetGlonassNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassNavigationMessage::CmdName = "GetGlonassNavigationMessage";
    const char* const GetGlonassNavigationMessage::Documentation = "Please note the command GetGlonassNavigationMessage is deprecated since 21.3. You may use GetMessageModificationToGlonassNav.\n\nGet infos about this modification Glonass navigation message event";

    REGISTER_COMMAND_FACTORY(GetGlonassNavigationMessage);


    GetGlonassNavigationMessage::GetGlonassNavigationMessage()
      : CommandBase(CmdName)
    {}

    GetGlonassNavigationMessage::GetGlonassNavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetGlonassNavigationMessagePtr GetGlonassNavigationMessage::create(const std::string& id)
    {
      return GetGlonassNavigationMessagePtr(new GetGlonassNavigationMessage(id));
    }

    GetGlonassNavigationMessagePtr GetGlonassNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassNavigationMessage>(ptr);
    }

    bool GetGlonassNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGlonassNavigationMessage::documentation() const { return Documentation; }


    int GetGlonassNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGlonassNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGlonassNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
