#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLOSEnabled
///
#include "gen/IsLOSEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLOSEnabled::CmdName = "IsLOSEnabled";
    const char* const IsLOSEnabled::Documentation = "Please note the command IsLOSEnabled is deprecated since 21.3. You may use IsLosEnabledForSV.\n\nGet Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(IsLOSEnabled);


    IsLOSEnabled::IsLOSEnabled()
      : CommandBase(CmdName)
    {}

    IsLOSEnabled::IsLOSEnabled(int prn, const std::string& system)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSystem(system);
    }


    IsLOSEnabledPtr IsLOSEnabled::create(int prn, const std::string& system)
    {
      return IsLOSEnabledPtr(new IsLOSEnabled(prn, system));
    }

    IsLOSEnabledPtr IsLOSEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLOSEnabled>(ptr);
    }

    bool IsLOSEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsLOSEnabled::documentation() const { return Documentation; }


    int IsLOSEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsLOSEnabled::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsLOSEnabled::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsLOSEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLOSEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
