#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav1Message
///
#include "gen/GetBeiDouCNav1Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav1Message::CmdName = "GetBeiDouCNav1Message";
    const char* const GetBeiDouCNav1Message::Documentation = "Please note the command GetBeiDouCNav1Message is deprecated since 21.3. You may use GetMessageModificationToBeiDouCNav1.\n\nGet infos about the CNAV1 Message with this id";

    REGISTER_COMMAND_FACTORY(GetBeiDouCNav1Message);


    GetBeiDouCNav1Message::GetBeiDouCNav1Message()
      : CommandBase(CmdName)
    {}

    GetBeiDouCNav1Message::GetBeiDouCNav1Message(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetBeiDouCNav1MessagePtr GetBeiDouCNav1Message::create(const std::string& id)
    {
      return GetBeiDouCNav1MessagePtr(new GetBeiDouCNav1Message(id));
    }

    GetBeiDouCNav1MessagePtr GetBeiDouCNav1Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav1Message>(ptr);
    }

    bool GetBeiDouCNav1Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetBeiDouCNav1Message::documentation() const { return Documentation; }


    int GetBeiDouCNav1Message::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouCNav1Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouCNav1Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
