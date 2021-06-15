#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoSatelliteSignalHealthResult
///
#include "gen/GetGalileoSatelliteSignalHealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoSatelliteSignalHealthResult::CmdName = "GetGalileoSatelliteSignalHealthResult";
    const char* const GetGalileoSatelliteSignalHealthResult::Documentation = "Result of GetGalileoSatelliteSignalHealth.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoSatelliteSignalHealthResult);


    GetGalileoSatelliteSignalHealthResult::GetGalileoSatelliteSignalHealthResult()
      : CommandResult(CmdName)
    {}

    GetGalileoSatelliteSignalHealthResult::GetGalileoSatelliteSignalHealthResult(CommandBasePtr relatedCommand, int prn, const std::string& component, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setComponent(component);
      setHealth(health);
    }


    GetGalileoSatelliteSignalHealthResultPtr GetGalileoSatelliteSignalHealthResult::create(CommandBasePtr relatedCommand, int prn, const std::string& component, int health)
    {
      return GetGalileoSatelliteSignalHealthResultPtr(new GetGalileoSatelliteSignalHealthResult(relatedCommand, prn, component, health));
    }

    GetGalileoSatelliteSignalHealthResultPtr GetGalileoSatelliteSignalHealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoSatelliteSignalHealthResult>(ptr);
    }

    bool GetGalileoSatelliteSignalHealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGalileoSatelliteSignalHealthResult::documentation() const { return Documentation; }


    int GetGalileoSatelliteSignalHealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoSatelliteSignalHealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoSatelliteSignalHealthResult::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoSatelliteSignalHealthResult::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoSatelliteSignalHealthResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGalileoSatelliteSignalHealthResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
