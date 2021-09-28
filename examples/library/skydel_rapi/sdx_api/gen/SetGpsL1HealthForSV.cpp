#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsL1HealthForSV
///
#include "gen/SetGpsL1HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsL1HealthForSV::CmdName = "SetGpsL1HealthForSV";
    const char* const SetGpsL1HealthForSV::Documentation = "Set GPS L1 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(SetGpsL1HealthForSV);


    SetGpsL1HealthForSV::SetGpsL1HealthForSV()
      : CommandBase(CmdName)
    {}

    SetGpsL1HealthForSV::SetGpsL1HealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetGpsL1HealthForSVPtr SetGpsL1HealthForSV::create(int svId, bool health)
    {
      return SetGpsL1HealthForSVPtr(new SetGpsL1HealthForSV(svId, health));
    }

    SetGpsL1HealthForSVPtr SetGpsL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsL1HealthForSV>(ptr);
    }

    bool SetGpsL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsL1HealthForSV::documentation() const { return Documentation; }


    int SetGpsL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsL1HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsL1HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
