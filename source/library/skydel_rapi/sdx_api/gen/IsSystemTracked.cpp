
#include "gen/IsSystemTracked.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSystemTracked
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSystemTracked::CmdName = "IsSystemTracked";
    const char* const IsSystemTracked::Documentation = "Tells if the specified system is tracked.";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSystemTracked);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSystemTracked);


    IsSystemTracked::IsSystemTracked()
      : CommandBase(CmdName)
    {}

    IsSystemTracked::IsSystemTracked(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    IsSystemTrackedPtr IsSystemTracked::create(const std::string& system)
    {
      return std::make_shared<IsSystemTracked>(system);
    }

    IsSystemTrackedPtr IsSystemTracked::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSystemTracked>(ptr);
    }

    bool IsSystemTracked::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsSystemTracked::documentation() const { return Documentation; }


    int IsSystemTracked::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSystemTracked::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSystemTracked::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
