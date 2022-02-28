#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllModulationTargetsResult
///
#include "gen/GetAllModulationTargetsResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllModulationTargetsResult::CmdName = "GetAllModulationTargetsResult";
    const char* const GetAllModulationTargetsResult::Documentation = "Result of GetAllModulationTargets.";

    REGISTER_COMMAND_RESULT_FACTORY(GetAllModulationTargetsResult);


    GetAllModulationTargetsResult::GetAllModulationTargetsResult()
      : CommandResult(CmdName)
    {}

    GetAllModulationTargetsResult::GetAllModulationTargetsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setIds(ids);
    }


    GetAllModulationTargetsResultPtr GetAllModulationTargetsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return GetAllModulationTargetsResultPtr(new GetAllModulationTargetsResult(relatedCommand, ids));
    }

    GetAllModulationTargetsResultPtr GetAllModulationTargetsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllModulationTargetsResult>(ptr);
    }

    bool GetAllModulationTargetsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllModulationTargetsResult::documentation() const { return Documentation; }


    std::vector<std::string> GetAllModulationTargetsResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllModulationTargetsResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
