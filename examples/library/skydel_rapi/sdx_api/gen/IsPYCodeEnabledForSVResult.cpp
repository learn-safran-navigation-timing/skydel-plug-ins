#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYCodeEnabledForSVResult
///
#include "gen/IsPYCodeEnabledForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYCodeEnabledForSVResult::CmdName = "IsPYCodeEnabledForSVResult";
    const char* const IsPYCodeEnabledForSVResult::Documentation = "Result of IsPYCodeEnabledForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(IsPYCodeEnabledForSVResult);


    IsPYCodeEnabledForSVResult::IsPYCodeEnabledForSVResult()
      : CommandResult(CmdName)
    {}

    IsPYCodeEnabledForSVResult::IsPYCodeEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }


    IsPYCodeEnabledForSVResultPtr IsPYCodeEnabledForSVResult::create(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
    {
      return IsPYCodeEnabledForSVResultPtr(new IsPYCodeEnabledForSVResult(relatedCommand, signal, svId, enabled));
    }

    IsPYCodeEnabledForSVResultPtr IsPYCodeEnabledForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPYCodeEnabledForSVResult>(ptr);
    }

    bool IsPYCodeEnabledForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPYCodeEnabledForSVResult::documentation() const { return Documentation; }


    std::string IsPYCodeEnabledForSVResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsPYCodeEnabledForSVResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsPYCodeEnabledForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsPYCodeEnabledForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsPYCodeEnabledForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsPYCodeEnabledForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
