
#include "EnableTrajectorySmoothing.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableTrajectorySmoothing
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableTrajectorySmoothing::CmdName = "EnableTrajectorySmoothing";
    const char* const EnableTrajectorySmoothing::Documentation = "Set trajectory smoothing for Track or Route enabled or disabled\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ------------------------------------------------------\n"
      "Enabled bool If true, trajectory will be smoothed during simulation";
    const char* const EnableTrajectorySmoothing::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableTrajectorySmoothing);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableTrajectorySmoothing);


    EnableTrajectorySmoothing::EnableTrajectorySmoothing()
      : CommandBase(CmdName, TargetId)
    {}

    EnableTrajectorySmoothing::EnableTrajectorySmoothing(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableTrajectorySmoothingPtr EnableTrajectorySmoothing::create(bool enabled)
    {
      return std::make_shared<EnableTrajectorySmoothing>(enabled);
    }

    EnableTrajectorySmoothingPtr EnableTrajectorySmoothing::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableTrajectorySmoothing>(ptr);
    }

    bool EnableTrajectorySmoothing::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableTrajectorySmoothing::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableTrajectorySmoothing::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableTrajectorySmoothing::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableTrajectorySmoothing::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableTrajectorySmoothing::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
