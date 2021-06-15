#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSatGeo
///
#include "gen/IsSatGeo.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSatGeo::CmdName = "IsSatGeo";
    const char* const IsSatGeo::Documentation = "Please note the command IsSatGeo is deprecated since 21.3. You may use IsSVForcedGeo.\n\nGet whether a satellite is geostationary";

    REGISTER_COMMAND_FACTORY(IsSatGeo);


    IsSatGeo::IsSatGeo()
      : CommandBase(CmdName)
    {}

    IsSatGeo::IsSatGeo(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    IsSatGeoPtr IsSatGeo::create(const std::string& system, int prn)
    {
      return IsSatGeoPtr(new IsSatGeo(system, prn));
    }

    IsSatGeoPtr IsSatGeo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSatGeo>(ptr);
    }

    bool IsSatGeo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string IsSatGeo::documentation() const { return Documentation; }


    int IsSatGeo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSatGeo::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSatGeo::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSatGeo::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsSatGeo::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
