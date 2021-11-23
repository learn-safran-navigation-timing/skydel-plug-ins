#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssLNAVNavigationMessage
///
#include "gen/GetQzssLNAVNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssLNAVNavigationMessage::CmdName = "GetQzssLNAVNavigationMessage";
    const char* const GetQzssLNAVNavigationMessage::Documentation = "Please note the command GetQzssLNAVNavigationMessage is deprecated since 21.3. You may use GetMessageModificationToQzssLNav.\n\nGet infos about this modification QZSS navigation message event.";

    REGISTER_COMMAND_FACTORY(GetQzssLNAVNavigationMessage);


    GetQzssLNAVNavigationMessage::GetQzssLNAVNavigationMessage()
      : CommandBase(CmdName)
    {}

    GetQzssLNAVNavigationMessage::GetQzssLNAVNavigationMessage(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetQzssLNAVNavigationMessagePtr GetQzssLNAVNavigationMessage::create(const std::string& id)
    {
      return GetQzssLNAVNavigationMessagePtr(new GetQzssLNAVNavigationMessage(id));
    }

    GetQzssLNAVNavigationMessagePtr GetQzssLNAVNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssLNAVNavigationMessage>(ptr);
    }

    bool GetQzssLNAVNavigationMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetQzssLNAVNavigationMessage::documentation() const { return Documentation; }


    int GetQzssLNAVNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssLNAVNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetQzssLNAVNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
