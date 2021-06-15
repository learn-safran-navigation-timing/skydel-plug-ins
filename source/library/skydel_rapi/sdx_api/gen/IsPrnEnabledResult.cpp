#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPrnEnabledResult
///
#include "gen/IsPrnEnabledResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPrnEnabledResult::CmdName = "IsPrnEnabledResult";
    const char* const IsPrnEnabledResult::Documentation = "Result of IsPrnEnabled.";

    REGISTER_COMMAND_RESULT_FACTORY(IsPrnEnabledResult);


    IsPrnEnabledResult::IsPrnEnabledResult()
      : CommandResult(CmdName)
    {}

    IsPrnEnabledResult::IsPrnEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setEnabled(enabled);
    }


    IsPrnEnabledResultPtr IsPrnEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled)
    {
      return IsPrnEnabledResultPtr(new IsPrnEnabledResult(relatedCommand, system, prn, enabled));
    }

    IsPrnEnabledResultPtr IsPrnEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPrnEnabledResult>(ptr);
    }

    bool IsPrnEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPrnEnabledResult::documentation() const { return Documentation; }


    std::string IsPrnEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsPrnEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsPrnEnabledResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsPrnEnabledResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsPrnEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsPrnEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
