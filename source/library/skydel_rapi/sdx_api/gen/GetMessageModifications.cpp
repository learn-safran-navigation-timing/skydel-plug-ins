#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModifications
///
#include "gen/GetMessageModifications.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModifications::CmdName = "GetMessageModifications";
    const char* const GetMessageModifications::Documentation = "Please note the command GetMessageModifications is deprecated since 21.3. You may use GetAllMessageModificationIdsForSignal.\n\nGet all event's IDs whose will modify the signal's message for this SV ID";

    REGISTER_COMMAND_FACTORY(GetMessageModifications);


    GetMessageModifications::GetMessageModifications()
      : CommandBase(CmdName)
    {}

    GetMessageModifications::GetMessageModifications(const std::string& signal, int svId)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
    }


    GetMessageModificationsPtr GetMessageModifications::create(const std::string& signal, int svId)
    {
      return GetMessageModificationsPtr(new GetMessageModifications(signal, svId));
    }

    GetMessageModificationsPtr GetMessageModifications::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModifications>(ptr);
    }

    bool GetMessageModifications::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetMessageModifications::documentation() const { return Documentation; }


    int GetMessageModifications::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModifications::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetMessageModifications::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModifications::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModifications::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
