#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouSatelliteHealthStatus
///
#include "gen/SetBeiDouSatelliteHealthStatus.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouSatelliteHealthStatus::CmdName = "SetBeiDouSatelliteHealthStatus";
    const char* const SetBeiDouSatelliteHealthStatus::Documentation = "Please note the command SetBeiDouSatelliteHealthStatus is deprecated since 21.3. You may use SetBeiDouHealthStatusForSV.\n\nSet BeiDou satellite health status";

    REGISTER_COMMAND_FACTORY(SetBeiDouSatelliteHealthStatus);


    SetBeiDouSatelliteHealthStatus::SetBeiDouSatelliteHealthStatus()
      : CommandBase(CmdName)
    {}

    SetBeiDouSatelliteHealthStatus::SetBeiDouSatelliteHealthStatus(int prn, int health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetBeiDouSatelliteHealthStatusPtr SetBeiDouSatelliteHealthStatus::create(int prn, int health)
    {
      return SetBeiDouSatelliteHealthStatusPtr(new SetBeiDouSatelliteHealthStatus(prn, health));
    }

    SetBeiDouSatelliteHealthStatusPtr SetBeiDouSatelliteHealthStatus::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouSatelliteHealthStatus>(ptr);
    }

    bool SetBeiDouSatelliteHealthStatus::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetBeiDouSatelliteHealthStatus::documentation() const { return Documentation; }


    int SetBeiDouSatelliteHealthStatus::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouSatelliteHealthStatus::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouSatelliteHealthStatus::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouSatelliteHealthStatus::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouSatelliteHealthStatus::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
