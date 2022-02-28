#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsRFOutputEnabled
///
#include "gen/IsRFOutputEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsRFOutputEnabled::CmdName = "IsRFOutputEnabled";
    const char* const IsRFOutputEnabled::Documentation = "Tells if the RF output is enabled or disabled for the specified satellite.";

    REGISTER_COMMAND_FACTORY(IsRFOutputEnabled);


    IsRFOutputEnabled::IsRFOutputEnabled()
      : CommandBase(CmdName)
    {}

    IsRFOutputEnabled::IsRFOutputEnabled(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }


    IsRFOutputEnabledPtr IsRFOutputEnabled::create(const std::string& system, int svId)
    {
      return IsRFOutputEnabledPtr(new IsRFOutputEnabled(system, svId));
    }

    IsRFOutputEnabledPtr IsRFOutputEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsRFOutputEnabled>(ptr);
    }

    bool IsRFOutputEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsRFOutputEnabled::documentation() const { return Documentation; }


    int IsRFOutputEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsRFOutputEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsRFOutputEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsRFOutputEnabled::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsRFOutputEnabled::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
