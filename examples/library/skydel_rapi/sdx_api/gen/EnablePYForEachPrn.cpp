#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePYForEachPrn
///
#include "gen/EnablePYForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePYForEachPrn::CmdName = "EnablePYForEachPrn";
    const char* const EnablePYForEachPrn::Documentation = "Please note the command EnablePYForEachPrn is deprecated since 21.3. You may use EnablePYCodeForEachSV.\n\nEnable (or disable) P(Y)-Code for each satellite individually.\nAllowed signal keys: \"L1P\", \"L2P\"";

    REGISTER_COMMAND_FACTORY(EnablePYForEachPrn);


    EnablePYForEachPrn::EnablePYForEachPrn()
      : CommandBase(CmdName)
    {}

    EnablePYForEachPrn::EnablePYForEachPrn(const std::string& signal, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    EnablePYForEachPrnPtr EnablePYForEachPrn::create(const std::string& signal, const std::vector<bool>& enabled)
    {
      return EnablePYForEachPrnPtr(new EnablePYForEachPrn(signal, enabled));
    }

    EnablePYForEachPrnPtr EnablePYForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnablePYForEachPrn>(ptr);
    }

    bool EnablePYForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnablePYForEachPrn::documentation() const { return Documentation; }


    int EnablePYForEachPrn::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnablePYForEachPrn::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnablePYForEachPrn::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnablePYForEachPrn::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnablePYForEachPrn::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
