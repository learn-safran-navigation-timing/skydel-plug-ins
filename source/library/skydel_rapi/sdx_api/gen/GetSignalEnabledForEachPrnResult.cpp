#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalEnabledForEachPrnResult
///
#include "gen/GetSignalEnabledForEachPrnResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalEnabledForEachPrnResult::CmdName = "GetSignalEnabledForEachPrnResult";
    const char* const GetSignalEnabledForEachPrnResult::Documentation = "Result of GetSignalEnabledForEachPrn.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSignalEnabledForEachPrnResult);


    GetSignalEnabledForEachPrnResult::GetSignalEnabledForEachPrnResult()
      : CommandResult(CmdName)
    {}

    GetSignalEnabledForEachPrnResult::GetSignalEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    GetSignalEnabledForEachPrnResultPtr GetSignalEnabledForEachPrnResult::create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
    {
      return GetSignalEnabledForEachPrnResultPtr(new GetSignalEnabledForEachPrnResult(relatedCommand, signal, enabled));
    }

    GetSignalEnabledForEachPrnResultPtr GetSignalEnabledForEachPrnResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalEnabledForEachPrnResult>(ptr);
    }

    bool GetSignalEnabledForEachPrnResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string GetSignalEnabledForEachPrnResult::documentation() const { return Documentation; }


    std::string GetSignalEnabledForEachPrnResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSignalEnabledForEachPrnResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetSignalEnabledForEachPrnResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void GetSignalEnabledForEachPrnResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
