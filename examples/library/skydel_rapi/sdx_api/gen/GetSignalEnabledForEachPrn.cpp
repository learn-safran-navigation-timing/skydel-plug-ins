#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalEnabledForEachPrn
///
#include "gen/GetSignalEnabledForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalEnabledForEachPrn::CmdName = "GetSignalEnabledForEachPrn";
    const char* const GetSignalEnabledForEachPrn::Documentation = "Please note the command GetSignalEnabledForEachPrn is deprecated since 21.3. You may use IsSignalEnabledForEachSV.\n\nTells if the signal is enabled or disabled for each satellite. See GetSignalEnabledForEachPrn description for allowed signals.";

    REGISTER_COMMAND_FACTORY(GetSignalEnabledForEachPrn);


    GetSignalEnabledForEachPrn::GetSignalEnabledForEachPrn()
      : CommandBase(CmdName)
    {}

    GetSignalEnabledForEachPrn::GetSignalEnabledForEachPrn(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }


    GetSignalEnabledForEachPrnPtr GetSignalEnabledForEachPrn::create(const std::string& signal)
    {
      return GetSignalEnabledForEachPrnPtr(new GetSignalEnabledForEachPrn(signal));
    }

    GetSignalEnabledForEachPrnPtr GetSignalEnabledForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalEnabledForEachPrn>(ptr);
    }

    bool GetSignalEnabledForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetSignalEnabledForEachPrn::documentation() const { return Documentation; }


    int GetSignalEnabledForEachPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSignalEnabledForEachPrn::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSignalEnabledForEachPrn::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
