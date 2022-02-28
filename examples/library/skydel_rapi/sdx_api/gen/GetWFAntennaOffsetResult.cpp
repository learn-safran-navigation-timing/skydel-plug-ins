#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaOffsetResult
///
#include "gen/GetWFAntennaOffsetResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaOffsetResult::CmdName = "GetWFAntennaOffsetResult";
    const char* const GetWFAntennaOffsetResult::Documentation = "Result of GetWFAntennaOffset.";

    REGISTER_COMMAND_RESULT_FACTORY(GetWFAntennaOffsetResult);


    GetWFAntennaOffsetResult::GetWFAntennaOffsetResult()
      : CommandResult(CmdName)
    {}

    GetWFAntennaOffsetResult::GetWFAntennaOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll)
      : CommandResult(CmdName, relatedCommand)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
    }


    GetWFAntennaOffsetResultPtr GetWFAntennaOffsetResult::create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll)
    {
      return std::make_shared<GetWFAntennaOffsetResult>(relatedCommand, x, y, z, yaw, pitch, roll);
    }

    GetWFAntennaOffsetResultPtr GetWFAntennaOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaOffsetResult>(ptr);
    }

    bool GetWFAntennaOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
        ;

    }

    std::string GetWFAntennaOffsetResult::documentation() const { return Documentation; }


    double GetWFAntennaOffsetResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetWFAntennaOffsetResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaOffsetResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetWFAntennaOffsetResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaOffsetResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetWFAntennaOffsetResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaOffsetResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetWFAntennaOffsetResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaOffsetResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetWFAntennaOffsetResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaOffsetResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetWFAntennaOffsetResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
