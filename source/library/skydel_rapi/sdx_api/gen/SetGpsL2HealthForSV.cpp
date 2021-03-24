#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsL2HealthForSV
///
#include "gen/SetGpsL2HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsL2HealthForSV::CmdName = "SetGpsL2HealthForSV";
    const char* const SetGpsL2HealthForSV::Documentation = "Set GPS L2 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(SetGpsL2HealthForSV);


    SetGpsL2HealthForSV::SetGpsL2HealthForSV()
      : CommandBase(CmdName)
    {}

    SetGpsL2HealthForSV::SetGpsL2HealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetGpsL2HealthForSVPtr SetGpsL2HealthForSV::create(int svId, bool health)
    {
      return SetGpsL2HealthForSVPtr(new SetGpsL2HealthForSV(svId, health));
    }

    SetGpsL2HealthForSVPtr SetGpsL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsL2HealthForSV>(ptr);
    }

    bool SetGpsL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsL2HealthForSV::documentation() const { return Documentation; }


    int SetGpsL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsL2HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsL2HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
