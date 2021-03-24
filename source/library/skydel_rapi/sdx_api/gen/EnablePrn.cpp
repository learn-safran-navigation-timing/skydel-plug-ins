#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePrn
///
#include "gen/EnablePrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePrn::CmdName = "EnablePrn";
    const char* const EnablePrn::Documentation = "Please note the command EnablePrn is deprecated since 21.3. You may use EnableSV.\n\nSet  enabled or disabled satellite for this constellation.";

    REGISTER_COMMAND_FACTORY(EnablePrn);


    EnablePrn::EnablePrn()
      : CommandBase(CmdName)
    {}

    EnablePrn::EnablePrn(const std::string& system, int prn, bool enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setEnabled(enabled);
    }


    EnablePrnPtr EnablePrn::create(const std::string& system, int prn, bool enabled)
    {
      return EnablePrnPtr(new EnablePrn(system, prn, enabled));
    }

    EnablePrnPtr EnablePrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnablePrn>(ptr);
    }

    bool EnablePrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnablePrn::documentation() const { return Documentation; }


    int EnablePrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnablePrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnablePrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnablePrn::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void EnablePrn::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnablePrn::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnablePrn::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
