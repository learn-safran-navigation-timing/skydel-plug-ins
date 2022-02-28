#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAntennaChangeResult
///
#include "gen/GetAntennaChangeResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAntennaChangeResult::CmdName = "GetAntennaChangeResult";
    const char* const GetAntennaChangeResult::Documentation = "Result of GetAntennaChange.";

    REGISTER_COMMAND_RESULT_FACTORY(GetAntennaChangeResult);


    GetAntennaChangeResult::GetAntennaChangeResult()
      : CommandResult(CmdName)
    {}

    GetAntennaChangeResult::GetAntennaChangeResult(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setStartTime(startTime);
      setAntenna(antenna);
      setId(id);
    }


    GetAntennaChangeResultPtr GetAntennaChangeResult::create(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id)
    {
      return std::make_shared<GetAntennaChangeResult>(relatedCommand, startTime, antenna, id);
    }

    GetAntennaChangeResultPtr GetAntennaChangeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAntennaChangeResult>(ptr);
    }

    bool GetAntennaChangeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["StartTime"])
          && parse_json<std::string>::is_valid(m_values["Antenna"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetAntennaChangeResult::documentation() const { return Documentation; }


    double GetAntennaChangeResult::startTime() const
    {
      return parse_json<double>::parse(m_values["StartTime"]);
    }

    void GetAntennaChangeResult::setStartTime(double startTime)
    {
      m_values.AddMember("StartTime", parse_json<double>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetAntennaChangeResult::antenna() const
    {
      return parse_json<std::string>::parse(m_values["Antenna"]);
    }

    void GetAntennaChangeResult::setAntenna(const std::string& antenna)
    {
      m_values.AddMember("Antenna", parse_json<std::string>::format(antenna, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetAntennaChangeResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetAntennaChangeResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
