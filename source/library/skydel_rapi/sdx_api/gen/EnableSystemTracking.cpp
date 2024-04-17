
#include "gen/EnableSystemTracking.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSystemTracking
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSystemTracking::CmdName = "EnableSystemTracking";
    const char* const EnableSystemTracking::Documentation = "Enable (or disable) the system tracked by the receiver.";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSystemTracking);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSystemTracking);


    EnableSystemTracking::EnableSystemTracking()
      : CommandBase(CmdName)
    {}

    EnableSystemTracking::EnableSystemTracking(const std::string& system, bool enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    EnableSystemTrackingPtr EnableSystemTracking::create(const std::string& system, bool enabled)
    {
      return std::make_shared<EnableSystemTracking>(system, enabled);
    }

    EnableSystemTrackingPtr EnableSystemTracking::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSystemTracking>(ptr);
    }

    bool EnableSystemTracking::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSystemTracking::documentation() const { return Documentation; }


    int EnableSystemTracking::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableSystemTracking::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableSystemTracking::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSystemTracking::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSystemTracking::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
