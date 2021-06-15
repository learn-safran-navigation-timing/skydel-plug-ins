#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsRFEnabled
///
#include "gen/IsRFEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsRFEnabled::CmdName = "IsRFEnabled";
    const char* const IsRFEnabled::Documentation = "Please note the command IsRFEnabled is deprecated since 21.3. You may use IsRFOutputEnabled.\n\nTells if the RF is enabled or disabled for the specified satellite.";

    REGISTER_COMMAND_FACTORY(IsRFEnabled);


    IsRFEnabled::IsRFEnabled()
      : CommandBase(CmdName)
    {}

    IsRFEnabled::IsRFEnabled(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    IsRFEnabledPtr IsRFEnabled::create(const std::string& system, int prn)
    {
      return IsRFEnabledPtr(new IsRFEnabled(system, prn));
    }

    IsRFEnabledPtr IsRFEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsRFEnabled>(ptr);
    }

    bool IsRFEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string IsRFEnabled::documentation() const { return Documentation; }


    int IsRFEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsRFEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsRFEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsRFEnabled::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsRFEnabled::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
