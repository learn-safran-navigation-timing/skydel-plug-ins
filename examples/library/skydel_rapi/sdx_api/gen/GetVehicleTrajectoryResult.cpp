#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryResult
///
#include "gen/GetVehicleTrajectoryResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryResult::CmdName = "GetVehicleTrajectoryResult";
    const char* const GetVehicleTrajectoryResult::Documentation = "Result of GetVehicleTrajectory.";

    REGISTER_COMMAND_RESULT_FACTORY(GetVehicleTrajectoryResult);


    GetVehicleTrajectoryResult::GetVehicleTrajectoryResult()
      : CommandResult(CmdName)
    {}

    GetVehicleTrajectoryResult::GetVehicleTrajectoryResult(CommandBasePtr relatedCommand, const std::string& type)
      : CommandResult(CmdName, relatedCommand)
    {

      setType(type);
    }


    GetVehicleTrajectoryResultPtr GetVehicleTrajectoryResult::create(CommandBasePtr relatedCommand, const std::string& type)
    {
      return std::make_shared<GetVehicleTrajectoryResult>(relatedCommand, type);
    }

    GetVehicleTrajectoryResultPtr GetVehicleTrajectoryResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryResult>(ptr);
    }

    bool GetVehicleTrajectoryResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
        ;

    }

    std::string GetVehicleTrajectoryResult::documentation() const { return Documentation; }


    std::string GetVehicleTrajectoryResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetVehicleTrajectoryResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
