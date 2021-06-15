#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoSatelliteDataHealthResult
///
#include "gen/GetGalileoSatelliteDataHealthResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoSatelliteDataHealthResult::CmdName = "GetGalileoSatelliteDataHealthResult";
    const char* const GetGalileoSatelliteDataHealthResult::Documentation = "Result of GetGalileoSatelliteDataHealth.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoSatelliteDataHealthResult);


    GetGalileoSatelliteDataHealthResult::GetGalileoSatelliteDataHealthResult()
      : CommandResult(CmdName)
    {}

    GetGalileoSatelliteDataHealthResult::GetGalileoSatelliteDataHealthResult(CommandBasePtr relatedCommand, int prn, const std::string& component, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setComponent(component);
      setHealth(health);
    }


    GetGalileoSatelliteDataHealthResultPtr GetGalileoSatelliteDataHealthResult::create(CommandBasePtr relatedCommand, int prn, const std::string& component, bool health)
    {
      return GetGalileoSatelliteDataHealthResultPtr(new GetGalileoSatelliteDataHealthResult(relatedCommand, prn, component, health));
    }

    GetGalileoSatelliteDataHealthResultPtr GetGalileoSatelliteDataHealthResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoSatelliteDataHealthResult>(ptr);
    }

    bool GetGalileoSatelliteDataHealthResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGalileoSatelliteDataHealthResult::documentation() const { return Documentation; }


    int GetGalileoSatelliteDataHealthResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoSatelliteDataHealthResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoSatelliteDataHealthResult::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoSatelliteDataHealthResult::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGalileoSatelliteDataHealthResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGalileoSatelliteDataHealthResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
