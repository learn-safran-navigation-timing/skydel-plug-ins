#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxIgnoreRxAntennaGainPatternResult
///
#include "gen/IsIntTxIgnoreRxAntennaGainPatternResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxIgnoreRxAntennaGainPatternResult::CmdName = "IsIntTxIgnoreRxAntennaGainPatternResult";
    const char* const IsIntTxIgnoreRxAntennaGainPatternResult::Documentation = "Result of IsIntTxIgnoreRxAntennaGainPattern.";

    REGISTER_COMMAND_RESULT_FACTORY(IsIntTxIgnoreRxAntennaGainPatternResult);


    IsIntTxIgnoreRxAntennaGainPatternResult::IsIntTxIgnoreRxAntennaGainPatternResult()
      : CommandResult(CmdName)
    {}

    IsIntTxIgnoreRxAntennaGainPatternResult::IsIntTxIgnoreRxAntennaGainPatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setIgnore(ignore);
      setId(id);
    }


    IsIntTxIgnoreRxAntennaGainPatternResultPtr IsIntTxIgnoreRxAntennaGainPatternResult::create(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
    {
      return std::make_shared<IsIntTxIgnoreRxAntennaGainPatternResult>(relatedCommand, ignore, id);
    }

    IsIntTxIgnoreRxAntennaGainPatternResultPtr IsIntTxIgnoreRxAntennaGainPatternResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaGainPatternResult>(ptr);
    }

    bool IsIntTxIgnoreRxAntennaGainPatternResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxIgnoreRxAntennaGainPatternResult::documentation() const { return Documentation; }


    bool IsIntTxIgnoreRxAntennaGainPatternResult::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void IsIntTxIgnoreRxAntennaGainPatternResult::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsIntTxIgnoreRxAntennaGainPatternResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxIgnoreRxAntennaGainPatternResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
