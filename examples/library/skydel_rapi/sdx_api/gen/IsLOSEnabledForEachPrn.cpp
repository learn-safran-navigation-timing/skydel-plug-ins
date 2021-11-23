#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLOSEnabledForEachPrn
///
#include "gen/IsLOSEnabledForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLOSEnabledForEachPrn::CmdName = "IsLOSEnabledForEachPrn";
    const char* const IsLOSEnabledForEachPrn::Documentation = "Please note the command IsLOSEnabledForEachPrn is deprecated since 21.3. You may use IsLOSEnabledForEachSV.\n\nGet Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(IsLOSEnabledForEachPrn);


    IsLOSEnabledForEachPrn::IsLOSEnabledForEachPrn()
      : CommandBase(CmdName)
    {}

    IsLOSEnabledForEachPrn::IsLOSEnabledForEachPrn(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }


    IsLOSEnabledForEachPrnPtr IsLOSEnabledForEachPrn::create(const std::string& system)
    {
      return IsLOSEnabledForEachPrnPtr(new IsLOSEnabledForEachPrn(system));
    }

    IsLOSEnabledForEachPrnPtr IsLOSEnabledForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLOSEnabledForEachPrn>(ptr);
    }

    bool IsLOSEnabledForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsLOSEnabledForEachPrn::documentation() const { return Documentation; }


    int IsLOSEnabledForEachPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsLOSEnabledForEachPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLOSEnabledForEachPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
