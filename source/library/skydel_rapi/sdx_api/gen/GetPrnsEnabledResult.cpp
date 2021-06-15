#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnsEnabledResult
///
#include "gen/GetPrnsEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnsEnabledResult::CmdName = "GetPrnsEnabledResult";
    const char* const GetPrnsEnabledResult::Documentation = "Result of GetPrnsEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(GetPrnsEnabledResult);


    GetPrnsEnabledResult::GetPrnsEnabledResult()
      : CommandResult(CmdName)
    {}

    GetPrnsEnabledResult::GetPrnsEnabledResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    GetPrnsEnabledResultPtr GetPrnsEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
    {
      return GetPrnsEnabledResultPtr(new GetPrnsEnabledResult(relatedCommand, system, enabled));
    }

    GetPrnsEnabledResultPtr GetPrnsEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnsEnabledResult>(ptr);
    }

    bool GetPrnsEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string GetPrnsEnabledResult::documentation() const { return Documentation; }


    std::string GetPrnsEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPrnsEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetPrnsEnabledResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void GetPrnsEnabledResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
