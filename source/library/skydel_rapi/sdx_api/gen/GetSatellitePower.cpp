#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePower
///
#include "gen/GetSatellitePower.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePower::CmdName = "GetSatellitePower";
    const char* const GetSatellitePower::Documentation = "Please note the command GetSatellitePower is deprecated since 21.3. You may use GetPowerForSV.\n\nGet power offset for specified satellite PRN.";

    REGISTER_COMMAND_FACTORY(GetSatellitePower);


    GetSatellitePower::GetSatellitePower()
      : CommandBase(CmdName)
    {}

    GetSatellitePower::GetSatellitePower(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    GetSatellitePowerPtr GetSatellitePower::create(const std::string& system, int prn)
    {
      return GetSatellitePowerPtr(new GetSatellitePower(system, prn));
    }

    GetSatellitePowerPtr GetSatellitePower::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePower>(ptr);
    }

    bool GetSatellitePower::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetSatellitePower::documentation() const { return Documentation; }


    int GetSatellitePower::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetSatellitePower::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatellitePower::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePower::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatellitePower::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
