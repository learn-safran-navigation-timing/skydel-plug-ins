#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryFixEcefResult
///
#include "gen/GetVehicleTrajectoryFixEcefResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryFixEcefResult::CmdName = "GetVehicleTrajectoryFixEcefResult";
    const char* const GetVehicleTrajectoryFixEcefResult::Documentation = "Result of GetVehicleTrajectoryFixEcef.";

    REGISTER_COMMAND_RESULT_FACTORY(GetVehicleTrajectoryFixEcefResult);


    GetVehicleTrajectoryFixEcefResult::GetVehicleTrajectoryFixEcefResult()
      : CommandResult(CmdName)
    {}

    GetVehicleTrajectoryFixEcefResult::GetVehicleTrajectoryFixEcefResult(CommandBasePtr relatedCommand, const std::string& type, double x, double y, double z, double yaw, double pitch, double roll)
      : CommandResult(CmdName, relatedCommand)
    {

      setType(type);
      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }


    GetVehicleTrajectoryFixEcefResultPtr GetVehicleTrajectoryFixEcefResult::create(CommandBasePtr relatedCommand, const std::string& type, double x, double y, double z, double yaw, double pitch, double roll)
    {
      return std::make_shared<GetVehicleTrajectoryFixEcefResult>(relatedCommand, type, x, y, z, yaw, pitch, roll);
    }

    GetVehicleTrajectoryFixEcefResultPtr GetVehicleTrajectoryFixEcefResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryFixEcefResult>(ptr);
    }

    bool GetVehicleTrajectoryFixEcefResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
        ;

    }

    std::string GetVehicleTrajectoryFixEcefResult::documentation() const { return Documentation; }


    std::string GetVehicleTrajectoryFixEcefResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetVehicleTrajectoryFixEcefResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixEcefResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetVehicleTrajectoryFixEcefResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixEcefResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetVehicleTrajectoryFixEcefResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixEcefResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetVehicleTrajectoryFixEcefResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixEcefResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetVehicleTrajectoryFixEcefResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixEcefResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetVehicleTrajectoryFixEcefResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleTrajectoryFixEcefResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetVehicleTrajectoryFixEcefResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
