#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYEnabledResult
///
#include "gen/IsPYEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYEnabledResult::CmdName = "IsPYEnabledResult";
    const char* const IsPYEnabledResult::Documentation = "Result of IsPYEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsPYEnabledResult);


    IsPYEnabledResult::IsPYEnabledResult()
      : CommandResult(CmdName)
    {}

    IsPYEnabledResult::IsPYEnabledResult(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setSignal(signal);
      setEnabled(enabled);
    }


    IsPYEnabledResultPtr IsPYEnabledResult::create(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled)
    {
      return IsPYEnabledResultPtr(new IsPYEnabledResult(relatedCommand, prn, signal, enabled));
    }

    IsPYEnabledResultPtr IsPYEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPYEnabledResult>(ptr);
    }

    bool IsPYEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPYEnabledResult::documentation() const { return Documentation; }


    int IsPYEnabledResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsPYEnabledResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsPYEnabledResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsPYEnabledResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsPYEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsPYEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
