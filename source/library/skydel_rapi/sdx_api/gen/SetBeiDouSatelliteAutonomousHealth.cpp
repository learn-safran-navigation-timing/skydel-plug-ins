#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouSatelliteAutonomousHealth
///
#include "gen/SetBeiDouSatelliteAutonomousHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouSatelliteAutonomousHealth::CmdName = "SetBeiDouSatelliteAutonomousHealth";
    const char* const SetBeiDouSatelliteAutonomousHealth::Documentation = "Please note the command SetBeiDouSatelliteAutonomousHealth is deprecated since 21.3. You may use SetBeiDouAutonomousHealthForSV.\n\nSet BeiDou satellite autonomous health";

    REGISTER_COMMAND_FACTORY(SetBeiDouSatelliteAutonomousHealth);


    SetBeiDouSatelliteAutonomousHealth::SetBeiDouSatelliteAutonomousHealth()
      : CommandBase(CmdName)
    {}

    SetBeiDouSatelliteAutonomousHealth::SetBeiDouSatelliteAutonomousHealth(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetBeiDouSatelliteAutonomousHealthPtr SetBeiDouSatelliteAutonomousHealth::create(int prn, bool health)
    {
      return SetBeiDouSatelliteAutonomousHealthPtr(new SetBeiDouSatelliteAutonomousHealth(prn, health));
    }

    SetBeiDouSatelliteAutonomousHealthPtr SetBeiDouSatelliteAutonomousHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouSatelliteAutonomousHealth>(ptr);
    }

    bool SetBeiDouSatelliteAutonomousHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetBeiDouSatelliteAutonomousHealth::documentation() const { return Documentation; }


    int SetBeiDouSatelliteAutonomousHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouSatelliteAutonomousHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouSatelliteAutonomousHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetBeiDouSatelliteAutonomousHealth::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetBeiDouSatelliteAutonomousHealth::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
