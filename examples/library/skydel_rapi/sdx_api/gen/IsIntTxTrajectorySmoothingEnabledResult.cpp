#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxTrajectorySmoothingEnabledResult
///
#include "gen/IsIntTxTrajectorySmoothingEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxTrajectorySmoothingEnabledResult::CmdName = "IsIntTxTrajectorySmoothingEnabledResult";
    const char* const IsIntTxTrajectorySmoothingEnabledResult::Documentation = "Result of IsIntTxTrajectorySmoothingEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsIntTxTrajectorySmoothingEnabledResult);


    IsIntTxTrajectorySmoothingEnabledResult::IsIntTxTrajectorySmoothingEnabledResult()
      : CommandResult(CmdName)
    {}

    IsIntTxTrajectorySmoothingEnabledResult::IsIntTxTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
      setId(id);
    }


    IsIntTxTrajectorySmoothingEnabledResultPtr IsIntTxTrajectorySmoothingEnabledResult::create(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
    {
      return IsIntTxTrajectorySmoothingEnabledResultPtr(new IsIntTxTrajectorySmoothingEnabledResult(relatedCommand, enabled, id));
    }

    IsIntTxTrajectorySmoothingEnabledResultPtr IsIntTxTrajectorySmoothingEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxTrajectorySmoothingEnabledResult>(ptr);
    }

    bool IsIntTxTrajectorySmoothingEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxTrajectorySmoothingEnabledResult::documentation() const { return Documentation; }


    bool IsIntTxTrajectorySmoothingEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsIntTxTrajectorySmoothingEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsIntTxTrajectorySmoothingEnabledResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxTrajectorySmoothingEnabledResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
