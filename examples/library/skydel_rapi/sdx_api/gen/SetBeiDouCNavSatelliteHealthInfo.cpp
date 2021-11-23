#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouCNavSatelliteHealthInfo
///
#include "gen/SetBeiDouCNavSatelliteHealthInfo.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouCNavSatelliteHealthInfo::CmdName = "SetBeiDouCNavSatelliteHealthInfo";
    const char* const SetBeiDouCNavSatelliteHealthInfo::Documentation = "Please note the command SetBeiDouCNavSatelliteHealthInfo is deprecated since 21.3. You may use SetBeiDouCNavHealthInfoForSV.\n\nSet BeiDou CNav satellite health info";

    REGISTER_COMMAND_FACTORY(SetBeiDouCNavSatelliteHealthInfo);


    SetBeiDouCNavSatelliteHealthInfo::SetBeiDouCNavSatelliteHealthInfo()
      : CommandBase(CmdName)
    {}

    SetBeiDouCNavSatelliteHealthInfo::SetBeiDouCNavSatelliteHealthInfo(int prn, int health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetBeiDouCNavSatelliteHealthInfoPtr SetBeiDouCNavSatelliteHealthInfo::create(int prn, int health)
    {
      return SetBeiDouCNavSatelliteHealthInfoPtr(new SetBeiDouCNavSatelliteHealthInfo(prn, health));
    }

    SetBeiDouCNavSatelliteHealthInfoPtr SetBeiDouCNavSatelliteHealthInfo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouCNavSatelliteHealthInfo>(ptr);
    }

    bool SetBeiDouCNavSatelliteHealthInfo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetBeiDouCNavSatelliteHealthInfo::documentation() const { return Documentation; }


    int SetBeiDouCNavSatelliteHealthInfo::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouCNavSatelliteHealthInfo::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouCNavSatelliteHealthInfo::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouCNavSatelliteHealthInfo::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouCNavSatelliteHealthInfo::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
