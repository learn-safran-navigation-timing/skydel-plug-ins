#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSatGeo
///
#include "gen/SetSatGeo.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSatGeo::CmdName = "SetSatGeo";
    const char* const SetSatGeo::Documentation = "Please note the command SetSatGeo is deprecated since 21.3. You may use ForceSVGeo.\n\nSet whether a satellite is geostationary";

    REGISTER_COMMAND_FACTORY(SetSatGeo);


    SetSatGeo::SetSatGeo()
      : CommandBase(CmdName)
    {}

    SetSatGeo::SetSatGeo(const std::string& system, int prn, bool isGeo, double longitude)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setIsGeo(isGeo);
      setLongitude(longitude);
    }


    SetSatGeoPtr SetSatGeo::create(const std::string& system, int prn, bool isGeo, double longitude)
    {
      return SetSatGeoPtr(new SetSatGeo(system, prn, isGeo, longitude));
    }

    SetSatGeoPtr SetSatGeo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSatGeo>(ptr);
    }

    bool SetSatGeo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsGeo"])
          && parse_json<double>::is_valid(m_values["Longitude"])
        ;

    }

    std::string SetSatGeo::documentation() const { return Documentation; }


    int SetSatGeo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSatGeo::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSatGeo::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatGeo::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSatGeo::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSatGeo::isGeo() const
    {
      return parse_json<bool>::parse(m_values["IsGeo"]);
    }

    void SetSatGeo::setIsGeo(bool isGeo)
    {
      m_values.AddMember("IsGeo", parse_json<bool>::format(isGeo, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatGeo::longitude() const
    {
      return parse_json<double>::parse(m_values["Longitude"]);
    }

    void SetSatGeo::setLongitude(double longitude)
    {
      m_values.AddMember("Longitude", parse_json<double>::format(longitude, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
