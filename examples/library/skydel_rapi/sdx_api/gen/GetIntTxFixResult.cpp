#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxFixResult
///
#include "gen/GetIntTxFixResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxFixResult::CmdName = "GetIntTxFixResult";
    const char* const GetIntTxFixResult::Documentation = "Result of GetIntTxFix.";

    REGISTER_COMMAND_RESULT_FACTORY(GetIntTxFixResult);


    GetIntTxFixResult::GetIntTxFixResult()
      : CommandResult(CmdName)
    {}

    GetIntTxFixResult::GetIntTxFixResult(CommandBasePtr relatedCommand, double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setLat(lat);
      setLon(lon);
      setAlt(alt);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setId(id);
    }


    GetIntTxFixResultPtr GetIntTxFixResult::create(CommandBasePtr relatedCommand, double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
    {
      return std::make_shared<GetIntTxFixResult>(relatedCommand, lat, lon, alt, yaw, pitch, roll, id);
    }

    GetIntTxFixResultPtr GetIntTxFixResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxFixResult>(ptr);
    }

    bool GetIntTxFixResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Lat"])
          && parse_json<double>::is_valid(m_values["Lon"])
          && parse_json<double>::is_valid(m_values["Alt"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxFixResult::documentation() const { return Documentation; }


    double GetIntTxFixResult::lat() const
    {
      return parse_json<double>::parse(m_values["Lat"]);
    }

    void GetIntTxFixResult::setLat(double lat)
    {
      m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixResult::lon() const
    {
      return parse_json<double>::parse(m_values["Lon"]);
    }

    void GetIntTxFixResult::setLon(double lon)
    {
      m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixResult::alt() const
    {
      return parse_json<double>::parse(m_values["Alt"]);
    }

    void GetIntTxFixResult::setAlt(double alt)
    {
      m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetIntTxFixResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetIntTxFixResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxFixResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetIntTxFixResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxFixResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxFixResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
