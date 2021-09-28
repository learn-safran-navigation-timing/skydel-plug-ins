#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouSatelliteHealthInfo
///
#include "gen/SetBeiDouSatelliteHealthInfo.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouSatelliteHealthInfo::CmdName = "SetBeiDouSatelliteHealthInfo";
    const char* const SetBeiDouSatelliteHealthInfo::Documentation = "Please note the command SetBeiDouSatelliteHealthInfo is deprecated since 21.3. You may use SetBeiDouHealthInfoForSV.\n\nSet BeiDou satellite health info";

    REGISTER_COMMAND_FACTORY(SetBeiDouSatelliteHealthInfo);


    SetBeiDouSatelliteHealthInfo::SetBeiDouSatelliteHealthInfo()
      : CommandBase(CmdName)
    {}

    SetBeiDouSatelliteHealthInfo::SetBeiDouSatelliteHealthInfo(int prn, int health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetBeiDouSatelliteHealthInfoPtr SetBeiDouSatelliteHealthInfo::create(int prn, int health)
    {
      return SetBeiDouSatelliteHealthInfoPtr(new SetBeiDouSatelliteHealthInfo(prn, health));
    }

    SetBeiDouSatelliteHealthInfoPtr SetBeiDouSatelliteHealthInfo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouSatelliteHealthInfo>(ptr);
    }

    bool SetBeiDouSatelliteHealthInfo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetBeiDouSatelliteHealthInfo::documentation() const { return Documentation; }


    int SetBeiDouSatelliteHealthInfo::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouSatelliteHealthInfo::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouSatelliteHealthInfo::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouSatelliteHealthInfo::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouSatelliteHealthInfo::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
