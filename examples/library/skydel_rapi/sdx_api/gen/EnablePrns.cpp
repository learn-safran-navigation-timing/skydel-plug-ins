#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePrns
///
#include "gen/EnablePrns.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePrns::CmdName = "EnablePrns";
    const char* const EnablePrns::Documentation = "Please note the command EnablePrns is deprecated since 21.3. You may use EnableEachSV.\n\nSet  enabled or disabled satellites for this constellation.";

    REGISTER_COMMAND_FACTORY(EnablePrns);


    EnablePrns::EnablePrns()
      : CommandBase(CmdName)
    {}

    EnablePrns::EnablePrns(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    EnablePrnsPtr EnablePrns::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return EnablePrnsPtr(new EnablePrns(system, enabled));
    }

    EnablePrnsPtr EnablePrns::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnablePrns>(ptr);
    }

    bool EnablePrns::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnablePrns::documentation() const { return Documentation; }


    int EnablePrns::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnablePrns::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnablePrns::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnablePrns::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnablePrns::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
