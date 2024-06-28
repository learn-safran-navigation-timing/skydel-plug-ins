
#include "SetWFAntennaElementOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaElementOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaElementOffset::CmdName = "SetWFAntennaElementOffset";
    const char* const SetWFAntennaElementOffset::Documentation = "Please note the command SetWFAntennaElementOffset is deprecated since 23.11. You may use SetVehicleAntennaOffset.\n"
      "\n"
      "Set WF antenna offset and orientation relative to CRPA Antenna frame for the specified element index.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------\n"
      "X       double WF Element X offset in the CRPA antenna frame (meter)\n"
      "Y       double WF Element Y offset in the CRPA antenna frame (meter)\n"
      "Z       double WF Element Z offset in the CRPA antenna frame (meter)\n"
      "Yaw     double WF Element Yaw offset in the CRPA antenna frame (rad)\n"
      "Pitch   double WF Element Pitch offset in the CRPA antenna frame (rad)\n"
      "Roll    double WF Element Roll offset in the CRPA antenna frame (rad)\n"
      "Element int    One-based index for element in antenna.";
    const char* const SetWFAntennaElementOffset::TargetId = "";

    const char* const SetWFAntennaElementOffset::Deprecated = "Please note the command SetWFAntennaElementOffset is deprecated since 23.11. You may use SetVehicleAntennaOffset.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetWFAntennaElementOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetWFAntennaElementOffset);


    SetWFAntennaElementOffset::SetWFAntennaElementOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetWFAntennaElementOffset::SetWFAntennaElementOffset(double x, double y, double z, double yaw, double pitch, double roll, int element)
      : CommandBase(CmdName, TargetId)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setElement(element);
    }

    SetWFAntennaElementOffsetPtr SetWFAntennaElementOffset::create(double x, double y, double z, double yaw, double pitch, double roll, int element)
    {
      return std::make_shared<SetWFAntennaElementOffset>(x, y, z, yaw, pitch, roll, element);
    }

    SetWFAntennaElementOffsetPtr SetWFAntennaElementOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFAntennaElementOffset>(ptr);
    }

    bool SetWFAntennaElementOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string SetWFAntennaElementOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetWFAntennaElementOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Element"}; 
      return names; 
    }

    std::optional<std::string> SetWFAntennaElementOffset::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int SetWFAntennaElementOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetWFAntennaElementOffset::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void SetWFAntennaElementOffset::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaElementOffset::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void SetWFAntennaElementOffset::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaElementOffset::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void SetWFAntennaElementOffset::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaElementOffset::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void SetWFAntennaElementOffset::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaElementOffset::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void SetWFAntennaElementOffset::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetWFAntennaElementOffset::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void SetWFAntennaElementOffset::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetWFAntennaElementOffset::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void SetWFAntennaElementOffset::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
