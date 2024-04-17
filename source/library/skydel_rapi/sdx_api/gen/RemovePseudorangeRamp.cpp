
#include "RemovePseudorangeRamp.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemovePseudorangeRamp
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemovePseudorangeRamp::CmdName = "RemovePseudorangeRamp";
    const char* const RemovePseudorangeRamp::Documentation = "Removes a PSR ramp events. When adding an event, the simulator\n"
      "sets the Id parameter. Use that Id here to remove the associated ramp.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Id     string Unique identifier of the PSR ramp to remove.";
    const char* const RemovePseudorangeRamp::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemovePseudorangeRamp);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemovePseudorangeRamp);


    RemovePseudorangeRamp::RemovePseudorangeRamp()
      : CommandBase(CmdName, TargetId)
    {}

    RemovePseudorangeRamp::RemovePseudorangeRamp(const std::string& system, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setId(id);
    }

    RemovePseudorangeRampPtr RemovePseudorangeRamp::create(const std::string& system, const std::string& id)
    {
      return std::make_shared<RemovePseudorangeRamp>(system, id);
    }

    RemovePseudorangeRampPtr RemovePseudorangeRamp::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemovePseudorangeRamp>(ptr);
    }

    bool RemovePseudorangeRamp::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemovePseudorangeRamp::documentation() const { return Documentation; }

    const std::vector<std::string>& RemovePseudorangeRamp::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Id"}; 
      return names; 
    }


    int RemovePseudorangeRamp::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemovePseudorangeRamp::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RemovePseudorangeRamp::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemovePseudorangeRamp::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemovePseudorangeRamp::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
