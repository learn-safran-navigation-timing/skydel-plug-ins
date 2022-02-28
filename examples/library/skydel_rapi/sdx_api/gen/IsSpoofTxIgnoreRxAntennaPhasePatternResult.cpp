#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxIgnoreRxAntennaPhasePatternResult
///
#include "gen/IsSpoofTxIgnoreRxAntennaPhasePatternResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxIgnoreRxAntennaPhasePatternResult::CmdName = "IsSpoofTxIgnoreRxAntennaPhasePatternResult";
    const char* const IsSpoofTxIgnoreRxAntennaPhasePatternResult::Documentation = "Result of IsSpoofTxIgnoreRxAntennaPhasePattern.";

    REGISTER_COMMAND_RESULT_FACTORY(IsSpoofTxIgnoreRxAntennaPhasePatternResult);


    IsSpoofTxIgnoreRxAntennaPhasePatternResult::IsSpoofTxIgnoreRxAntennaPhasePatternResult()
      : CommandResult(CmdName)
    {}

    IsSpoofTxIgnoreRxAntennaPhasePatternResult::IsSpoofTxIgnoreRxAntennaPhasePatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setIgnore(ignore);
      setId(id);
    }


    IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr IsSpoofTxIgnoreRxAntennaPhasePatternResult::create(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
    {
      return IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr(new IsSpoofTxIgnoreRxAntennaPhasePatternResult(relatedCommand, ignore, id));
    }

    IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr IsSpoofTxIgnoreRxAntennaPhasePatternResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxIgnoreRxAntennaPhasePatternResult>(ptr);
    }

    bool IsSpoofTxIgnoreRxAntennaPhasePatternResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxIgnoreRxAntennaPhasePatternResult::documentation() const { return Documentation; }


    bool IsSpoofTxIgnoreRxAntennaPhasePatternResult::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void IsSpoofTxIgnoreRxAntennaPhasePatternResult::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsSpoofTxIgnoreRxAntennaPhasePatternResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxIgnoreRxAntennaPhasePatternResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
