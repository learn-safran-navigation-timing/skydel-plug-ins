#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL2HealthForSV
///
#include "gen/SetQzssL2HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL2HealthForSV::CmdName = "SetQzssL2HealthForSV";
    const char* const SetQzssL2HealthForSV::Documentation = "Please note the command SetQzssSatelliteL2Health is deprecated since 21.3. You may use SetQzssL2HealthForSV.\n\nSet QZSS L2 health (Health of L2C signal)";

    REGISTER_COMMAND_FACTORY(SetQzssL2HealthForSV);


    SetQzssL2HealthForSV::SetQzssL2HealthForSV()
      : CommandBase(CmdName)
    {}

    SetQzssL2HealthForSV::SetQzssL2HealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetQzssL2HealthForSVPtr SetQzssL2HealthForSV::create(int svId, bool health)
    {
      return SetQzssL2HealthForSVPtr(new SetQzssL2HealthForSV(svId, health));
    }

    SetQzssL2HealthForSVPtr SetQzssL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL2HealthForSV>(ptr);
    }

    bool SetQzssL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetQzssL2HealthForSV::documentation() const { return Documentation; }


    int SetQzssL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL2HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL2HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
