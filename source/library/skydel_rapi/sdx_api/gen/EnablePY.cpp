#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePY
///
#include "gen/EnablePY.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePY::CmdName = "EnablePY";
    const char* const EnablePY::Documentation = "Please note the command EnablePY is deprecated since 21.3. You may use EnablePYCodeForSV.\n\nEnable (or disable) P(Y)-Code for specified satellite PRN. Use PRN 0 to enabled/disable all satellites.\nAllowed signal keys: \"L1P\", \"L2P\"";

    REGISTER_COMMAND_FACTORY(EnablePY);


    EnablePY::EnablePY()
      : CommandBase(CmdName)
    {}

    EnablePY::EnablePY(int prn, const std::string& signal, bool enabled)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSignal(signal);
      setEnabled(enabled);
    }


    EnablePYPtr EnablePY::create(int prn, const std::string& signal, bool enabled)
    {
      return EnablePYPtr(new EnablePY(prn, signal, enabled));
    }

    EnablePYPtr EnablePY::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnablePY>(ptr);
    }

    bool EnablePY::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnablePY::documentation() const { return Documentation; }


    int EnablePY::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int EnablePY::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void EnablePY::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnablePY::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnablePY::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnablePY::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnablePY::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
