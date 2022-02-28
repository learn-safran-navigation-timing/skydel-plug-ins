#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTrajectoryCompletedResult
///
#include "gen/IsTrajectoryCompletedResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTrajectoryCompletedResult::CmdName = "IsTrajectoryCompletedResult";
    const char* const IsTrajectoryCompletedResult::Documentation = "Result of IsTrajectoryCompleted.";

    REGISTER_COMMAND_RESULT_FACTORY(IsTrajectoryCompletedResult);


    IsTrajectoryCompletedResult::IsTrajectoryCompletedResult()
      : CommandResult(CmdName)
    {}

    IsTrajectoryCompletedResult::IsTrajectoryCompletedResult(CommandBasePtr relatedCommand, bool isCompleted)
      : CommandResult(CmdName, relatedCommand)
    {

      setIsCompleted(isCompleted);
    }


    IsTrajectoryCompletedResultPtr IsTrajectoryCompletedResult::create(CommandBasePtr relatedCommand, bool isCompleted)
    {
      return std::make_shared<IsTrajectoryCompletedResult>(relatedCommand, isCompleted);
    }

    IsTrajectoryCompletedResultPtr IsTrajectoryCompletedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTrajectoryCompletedResult>(ptr);
    }

    bool IsTrajectoryCompletedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsCompleted"])
        ;

    }

    std::string IsTrajectoryCompletedResult::documentation() const { return Documentation; }


    bool IsTrajectoryCompletedResult::isCompleted() const
    {
      return parse_json<bool>::parse(m_values["IsCompleted"]);
    }

    void IsTrajectoryCompletedResult::setIsCompleted(bool isCompleted)
    {
      m_values.AddMember("IsCompleted", parse_json<bool>::format(isCompleted, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
