#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYEnabled
///
#include "gen/IsPYEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYEnabled::CmdName = "IsPYEnabled";
    const char* const IsPYEnabled::Documentation = "Please note the command IsPYEnabled is deprecated since 21.3. You may use IsPYCodeEnabledForSV.\n\nTells if P(Y)-Code is enabled for the specified satellite PRN. See IsPYEnabled description for allowed signals.";

    REGISTER_COMMAND_FACTORY(IsPYEnabled);


    IsPYEnabled::IsPYEnabled()
      : CommandBase(CmdName)
    {}

    IsPYEnabled::IsPYEnabled(int prn, const std::string& signal)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSignal(signal);
    }


    IsPYEnabledPtr IsPYEnabled::create(int prn, const std::string& signal)
    {
      return IsPYEnabledPtr(new IsPYEnabled(prn, signal));
    }

    IsPYEnabledPtr IsPYEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPYEnabled>(ptr);
    }

    bool IsPYEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsPYEnabled::documentation() const { return Documentation; }


    int IsPYEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsPYEnabled::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsPYEnabled::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsPYEnabled::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsPYEnabled::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
