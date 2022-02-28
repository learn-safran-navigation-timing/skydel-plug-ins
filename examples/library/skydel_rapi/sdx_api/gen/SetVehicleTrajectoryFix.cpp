#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetVehicleTrajectoryFix
///
#include "gen/SetVehicleTrajectoryFix.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetVehicleTrajectoryFix::CmdName = "SetVehicleTrajectoryFix";
    const char* const SetVehicleTrajectoryFix::Documentation = "Set vehicle static position and orientation";

    REGISTER_COMMAND_FACTORY(SetVehicleTrajectoryFix);


    SetVehicleTrajectoryFix::SetVehicleTrajectoryFix()
      : CommandBase(CmdName)
    {}

    SetVehicleTrajectoryFix::SetVehicleTrajectoryFix(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll)
      : CommandBase(CmdName)
    {

      setType(type);
      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }


    SetVehicleTrajectoryFixPtr SetVehicleTrajectoryFix::create(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll)
    {
      return SetVehicleTrajectoryFixPtr(new SetVehicleTrajectoryFix(type, lat, lon, alt, yaw, pitch, roll));
    }

    SetVehicleTrajectoryFixPtr SetVehicleTrajectoryFix::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetVehicleTrajectoryFix>(ptr);
    }

    bool SetVehicleTrajectoryFix::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<double>::is_valid(m_values["Lat"])
          && parse_json<double>::is_valid(m_values["Lon"])
          && parse_json<double>::is_valid(m_values["Alt"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
        ;

    }

    std::string SetVehicleTrajectoryFix::documentation() const { return Documentation; }


    int SetVehicleTrajectoryFix::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetVehicleTrajectoryFix::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetVehicleTrajectoryFix::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFix::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void SetVehicleTrajectoryFix::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFix::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void SetVehicleTrajectoryFix::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFix::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void SetVehicleTrajectoryFix::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFix::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetVehicleTrajectoryFix::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFix::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetVehicleTrajectoryFix::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetVehicleTrajectoryFix::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetVehicleTrajectoryFix::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
