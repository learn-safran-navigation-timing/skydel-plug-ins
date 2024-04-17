
#include "IsSpoofTxIgnoreRxAntennaPhasePatternResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxIgnoreRxAntennaPhasePatternResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxIgnoreRxAntennaPhasePatternResult::CmdName = "IsSpoofTxIgnoreRxAntennaPhasePatternResult";
    const char* const IsSpoofTxIgnoreRxAntennaPhasePatternResult::Documentation = "Result of IsSpoofTxIgnoreRxAntennaPhasePattern.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------\n"
      "Ignore bool   If true, the receiver's antenna phase pattern will be ignored.\n"
      "Id     string Transmitter unique identifier.";
    const char* const IsSpoofTxIgnoreRxAntennaPhasePatternResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxIgnoreRxAntennaPhasePatternResult);


    IsSpoofTxIgnoreRxAntennaPhasePatternResult::IsSpoofTxIgnoreRxAntennaPhasePatternResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSpoofTxIgnoreRxAntennaPhasePatternResult::IsSpoofTxIgnoreRxAntennaPhasePatternResult(bool ignore, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setIgnore(ignore);
      setId(id);
    }

    IsSpoofTxIgnoreRxAntennaPhasePatternResult::IsSpoofTxIgnoreRxAntennaPhasePatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIgnore(ignore);
      setId(id);
    }


    IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr IsSpoofTxIgnoreRxAntennaPhasePatternResult::create(bool ignore, const std::string& id)
    {
      return std::make_shared<IsSpoofTxIgnoreRxAntennaPhasePatternResult>(ignore, id);
    }

    IsSpoofTxIgnoreRxAntennaPhasePatternResultPtr IsSpoofTxIgnoreRxAntennaPhasePatternResult::create(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
    {
      return std::make_shared<IsSpoofTxIgnoreRxAntennaPhasePatternResult>(relatedCommand, ignore, id);
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

    const std::vector<std::string>& IsSpoofTxIgnoreRxAntennaPhasePatternResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ignore", "Id"}; 
      return names; 
    }


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
