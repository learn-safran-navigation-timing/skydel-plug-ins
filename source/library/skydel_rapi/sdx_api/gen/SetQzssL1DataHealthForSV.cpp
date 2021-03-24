#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL1DataHealthForSV
///
#include "gen/SetQzssL1DataHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL1DataHealthForSV::CmdName = "SetQzssL1DataHealthForSV";
    const char* const SetQzssL1DataHealthForSV::Documentation = "Please note the command SetQzssSatelliteL1DataHealth is deprecated since 21.3. You may use SetQzssL1DataHealthForSV.\n\nSet QZSS L1 C/A nav data health";

    REGISTER_COMMAND_FACTORY(SetQzssL1DataHealthForSV);


    SetQzssL1DataHealthForSV::SetQzssL1DataHealthForSV()
      : CommandBase(CmdName)
    {}

    SetQzssL1DataHealthForSV::SetQzssL1DataHealthForSV(int svId, int health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetQzssL1DataHealthForSVPtr SetQzssL1DataHealthForSV::create(int svId, int health)
    {
      return SetQzssL1DataHealthForSVPtr(new SetQzssL1DataHealthForSV(svId, health));
    }

    SetQzssL1DataHealthForSVPtr SetQzssL1DataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL1DataHealthForSV>(ptr);
    }

    bool SetQzssL1DataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetQzssL1DataHealthForSV::documentation() const { return Documentation; }


    int SetQzssL1DataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL1DataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL1DataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetQzssL1DataHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetQzssL1DataHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
