#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPYEnabledForEachPrnResult
///
#include "gen/GetPYEnabledForEachPrnResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPYEnabledForEachPrnResult::CmdName = "GetPYEnabledForEachPrnResult";
    const char* const GetPYEnabledForEachPrnResult::Documentation = "Result of GetPYEnabledForEachPrn.";

    REGISTER_COMMAND_RESULT_FACTORY(GetPYEnabledForEachPrnResult);


    GetPYEnabledForEachPrnResult::GetPYEnabledForEachPrnResult()
      : CommandResult(CmdName)
    {}

    GetPYEnabledForEachPrnResult::GetPYEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    GetPYEnabledForEachPrnResultPtr GetPYEnabledForEachPrnResult::create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
    {
      return GetPYEnabledForEachPrnResultPtr(new GetPYEnabledForEachPrnResult(relatedCommand, signal, enabled));
    }

    GetPYEnabledForEachPrnResultPtr GetPYEnabledForEachPrnResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPYEnabledForEachPrnResult>(ptr);
    }

    bool GetPYEnabledForEachPrnResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string GetPYEnabledForEachPrnResult::documentation() const { return Documentation; }


    std::string GetPYEnabledForEachPrnResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPYEnabledForEachPrnResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetPYEnabledForEachPrnResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void GetPYEnabledForEachPrnResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
