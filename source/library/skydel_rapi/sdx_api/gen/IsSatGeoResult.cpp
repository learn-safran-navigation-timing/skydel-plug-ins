#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSatGeoResult
///
#include "gen/IsSatGeoResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSatGeoResult::CmdName = "IsSatGeoResult";
    const char* const IsSatGeoResult::Documentation = "Result of IsSatGeo.";

    REGISTER_COMMAND_RESULT_FACTORY(IsSatGeoResult);


    IsSatGeoResult::IsSatGeoResult()
      : CommandResult(CmdName)
    {}

    IsSatGeoResult::IsSatGeoResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool isGeo, double longitude)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setIsGeo(isGeo);
      setLongitude(longitude);
    }


    IsSatGeoResultPtr IsSatGeoResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool isGeo, double longitude)
    {
      return IsSatGeoResultPtr(new IsSatGeoResult(relatedCommand, system, prn, isGeo, longitude));
    }

    IsSatGeoResultPtr IsSatGeoResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSatGeoResult>(ptr);
    }

    bool IsSatGeoResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsGeo"])
          && parse_json<double>::is_valid(m_values["Longitude"])
        ;

    }

    std::string IsSatGeoResult::documentation() const { return Documentation; }


    std::string IsSatGeoResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSatGeoResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSatGeoResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsSatGeoResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSatGeoResult::isGeo() const
    {
      return parse_json<bool>::parse(m_values["IsGeo"]);
    }

    void IsSatGeoResult::setIsGeo(bool isGeo)
    {
      m_values.AddMember("IsGeo", parse_json<bool>::format(isGeo, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double IsSatGeoResult::longitude() const
    {
      return parse_json<double>::parse(m_values["Longitude"]);
    }

    void IsSatGeoResult::setLongitude(double longitude)
    {
      m_values.AddMember("Longitude", parse_json<double>::format(longitude, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
