#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLOSForEachPrn
///
#include "gen/EnableLOSForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLOSForEachPrn::CmdName = "EnableLOSForEachPrn";
    const char* const EnableLOSForEachPrn::Documentation = "Please note the command EnableLOSForEachPrn is deprecated since 21.3. You may use EnableLosForEachSV.\n\nSet Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(EnableLOSForEachPrn);


    EnableLOSForEachPrn::EnableLOSForEachPrn()
      : CommandBase(CmdName)
    {}

    EnableLOSForEachPrn::EnableLOSForEachPrn(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    EnableLOSForEachPrnPtr EnableLOSForEachPrn::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return EnableLOSForEachPrnPtr(new EnableLOSForEachPrn(system, enabled));
    }

    EnableLOSForEachPrnPtr EnableLOSForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLOSForEachPrn>(ptr);
    }

    bool EnableLOSForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLOSForEachPrn::documentation() const { return Documentation; }


    int EnableLOSForEachPrn::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableLOSForEachPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableLOSForEachPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnableLOSForEachPrn::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableLOSForEachPrn::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
