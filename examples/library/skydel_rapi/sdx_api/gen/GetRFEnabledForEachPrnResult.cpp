#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetRFEnabledForEachPrnResult
///
#include "gen/GetRFEnabledForEachPrnResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetRFEnabledForEachPrnResult::CmdName = "GetRFEnabledForEachPrnResult";
    const char* const GetRFEnabledForEachPrnResult::Documentation = "Result of GetRFEnabledForEachPrn.";

    REGISTER_COMMAND_RESULT_FACTORY(GetRFEnabledForEachPrnResult);


    GetRFEnabledForEachPrnResult::GetRFEnabledForEachPrnResult()
      : CommandResult(CmdName)
    {}

    GetRFEnabledForEachPrnResult::GetRFEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    GetRFEnabledForEachPrnResultPtr GetRFEnabledForEachPrnResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
    {
      return GetRFEnabledForEachPrnResultPtr(new GetRFEnabledForEachPrnResult(relatedCommand, system, enabled));
    }

    GetRFEnabledForEachPrnResultPtr GetRFEnabledForEachPrnResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetRFEnabledForEachPrnResult>(ptr);
    }

    bool GetRFEnabledForEachPrnResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string GetRFEnabledForEachPrnResult::documentation() const { return Documentation; }


    std::string GetRFEnabledForEachPrnResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetRFEnabledForEachPrnResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetRFEnabledForEachPrnResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void GetRFEnabledForEachPrnResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
