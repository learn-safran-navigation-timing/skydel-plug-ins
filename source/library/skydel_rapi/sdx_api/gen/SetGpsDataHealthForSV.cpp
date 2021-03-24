#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsDataHealthForSV
///
#include "gen/SetGpsDataHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsDataHealthForSV::CmdName = "SetGpsDataHealthForSV";
    const char* const SetGpsDataHealthForSV::Documentation = "Set GPS nav data health";

    REGISTER_COMMAND_FACTORY(SetGpsDataHealthForSV);


    SetGpsDataHealthForSV::SetGpsDataHealthForSV()
      : CommandBase(CmdName)
    {}

    SetGpsDataHealthForSV::SetGpsDataHealthForSV(int svId, int health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetGpsDataHealthForSVPtr SetGpsDataHealthForSV::create(int svId, int health)
    {
      return SetGpsDataHealthForSVPtr(new SetGpsDataHealthForSV(svId, health));
    }

    SetGpsDataHealthForSVPtr SetGpsDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsDataHealthForSV>(ptr);
    }

    bool SetGpsDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsDataHealthForSV::documentation() const { return Documentation; }


    int SetGpsDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsDataHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGpsDataHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
