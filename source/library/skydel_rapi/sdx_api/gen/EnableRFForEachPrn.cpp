#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableRFForEachPrn
///
#include "gen/EnableRFForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableRFForEachPrn::CmdName = "EnableRFForEachPrn";
    const char* const EnableRFForEachPrn::Documentation = "Please note the command EnableRFForEachPrn is deprecated since 21.3. You may use EnableRFOutputForEachSV.\n\nEnable (or disable) RF for each satellite individually.";

    REGISTER_COMMAND_FACTORY(EnableRFForEachPrn);


    EnableRFForEachPrn::EnableRFForEachPrn()
      : CommandBase(CmdName)
    {}

    EnableRFForEachPrn::EnableRFForEachPrn(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    EnableRFForEachPrnPtr EnableRFForEachPrn::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return EnableRFForEachPrnPtr(new EnableRFForEachPrn(system, enabled));
    }

    EnableRFForEachPrnPtr EnableRFForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableRFForEachPrn>(ptr);
    }

    bool EnableRFForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableRFForEachPrn::documentation() const { return Documentation; }


    int EnableRFForEachPrn::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableRFForEachPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableRFForEachPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnableRFForEachPrn::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableRFForEachPrn::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
