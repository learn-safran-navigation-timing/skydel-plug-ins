#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPYEnabledForEachPrn
///
#include "gen/GetPYEnabledForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPYEnabledForEachPrn::CmdName = "GetPYEnabledForEachPrn";
    const char* const GetPYEnabledForEachPrn::Documentation = "Please note the command GetPYEnabledForEachPrn is deprecated since 21.3. You may use IsPYCodeEnabledForEachSV.\n\nTells if the P(Y)-Code is enabled or disabled for each satellite. See GetPYEnabledForEachPrn description for allowed signals.";

    REGISTER_COMMAND_FACTORY(GetPYEnabledForEachPrn);


    GetPYEnabledForEachPrn::GetPYEnabledForEachPrn()
      : CommandBase(CmdName)
    {}

    GetPYEnabledForEachPrn::GetPYEnabledForEachPrn(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }


    GetPYEnabledForEachPrnPtr GetPYEnabledForEachPrn::create(const std::string& signal)
    {
      return GetPYEnabledForEachPrnPtr(new GetPYEnabledForEachPrn(signal));
    }

    GetPYEnabledForEachPrnPtr GetPYEnabledForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPYEnabledForEachPrn>(ptr);
    }

    bool GetPYEnabledForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetPYEnabledForEachPrn::documentation() const { return Documentation; }


    int GetPYEnabledForEachPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPYEnabledForEachPrn::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPYEnabledForEachPrn::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
