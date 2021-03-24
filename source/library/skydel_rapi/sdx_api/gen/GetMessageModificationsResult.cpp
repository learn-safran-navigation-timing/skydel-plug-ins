#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationsResult
///
#include "gen/GetMessageModificationsResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationsResult::CmdName = "GetMessageModificationsResult";
    const char* const GetMessageModificationsResult::Documentation = "Result of GetMessageModifications";

    REGISTER_COMMAND_RESULT_FACTORY(GetMessageModificationsResult);


    GetMessageModificationsResult::GetMessageModificationsResult()
      : CommandResult(CmdName)
    {}

    GetMessageModificationsResult::GetMessageModificationsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetMessageModificationsResultPtr GetMessageModificationsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetMessageModificationsResultPtr(new GetMessageModificationsResult(relatedCommand, ids));
    }

    GetMessageModificationsResultPtr GetMessageModificationsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationsResult>(ptr);
    }

    bool GetMessageModificationsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetMessageModificationsResult::documentation() const { return Documentation; }


    std::vector<std::string> GetMessageModificationsResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetMessageModificationsResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
