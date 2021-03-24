#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL1HealthForSV
///
#include "gen/SetQzssL1HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL1HealthForSV::CmdName = "SetQzssL1HealthForSV";
    const char* const SetQzssL1HealthForSV::Documentation = "Please note the command SetQzssSatelliteL1Health is deprecated since 21.3. You may use SetQzssL1HealthForSV.\n\nSet QZSS L1 health (Health of L1C/A signal)";

    REGISTER_COMMAND_FACTORY(SetQzssL1HealthForSV);


    SetQzssL1HealthForSV::SetQzssL1HealthForSV()
      : CommandBase(CmdName)
    {}

    SetQzssL1HealthForSV::SetQzssL1HealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetQzssL1HealthForSVPtr SetQzssL1HealthForSV::create(int svId, bool health)
    {
      return SetQzssL1HealthForSVPtr(new SetQzssL1HealthForSV(svId, health));
    }

    SetQzssL1HealthForSVPtr SetQzssL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL1HealthForSV>(ptr);
    }

    bool SetQzssL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetQzssL1HealthForSV::documentation() const { return Documentation; }


    int SetQzssL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL1HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL1HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
