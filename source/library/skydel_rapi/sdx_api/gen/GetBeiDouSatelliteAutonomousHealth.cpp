#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouSatelliteAutonomousHealth
///
#include "gen/GetBeiDouSatelliteAutonomousHealth.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouSatelliteAutonomousHealth::CmdName = "GetBeiDouSatelliteAutonomousHealth";
    const char* const GetBeiDouSatelliteAutonomousHealth::Documentation = "Please note the command GetBeiDouSatelliteAutonomousHealth is deprecated since 21.3. You may use GetBeiDouAutonomousHealthForSV.\n\nGet BeiDou satellite autonomous health";

    REGISTER_COMMAND_FACTORY(GetBeiDouSatelliteAutonomousHealth);


    GetBeiDouSatelliteAutonomousHealth::GetBeiDouSatelliteAutonomousHealth()
      : CommandBase(CmdName)
    {}

    GetBeiDouSatelliteAutonomousHealth::GetBeiDouSatelliteAutonomousHealth(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouSatelliteAutonomousHealthPtr GetBeiDouSatelliteAutonomousHealth::create(int prn)
    {
      return GetBeiDouSatelliteAutonomousHealthPtr(new GetBeiDouSatelliteAutonomousHealth(prn));
    }

    GetBeiDouSatelliteAutonomousHealthPtr GetBeiDouSatelliteAutonomousHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouSatelliteAutonomousHealth>(ptr);
    }

    bool GetBeiDouSatelliteAutonomousHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouSatelliteAutonomousHealth::documentation() const { return Documentation; }


    int GetBeiDouSatelliteAutonomousHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouSatelliteAutonomousHealth::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouSatelliteAutonomousHealth::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
