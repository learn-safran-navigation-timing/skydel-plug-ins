#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouHealthStatusForSV
///
#include "gen/SetBeiDouHealthStatusForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouHealthStatusForSV::CmdName = "SetBeiDouHealthStatusForSV";
    const char* const SetBeiDouHealthStatusForSV::Documentation = "Set BeiDou satellite health status";

    REGISTER_COMMAND_FACTORY(SetBeiDouHealthStatusForSV);


    SetBeiDouHealthStatusForSV::SetBeiDouHealthStatusForSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouHealthStatusForSV::SetBeiDouHealthStatusForSV(int svId, int health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetBeiDouHealthStatusForSVPtr SetBeiDouHealthStatusForSV::create(int svId, int health)
    {
      return SetBeiDouHealthStatusForSVPtr(new SetBeiDouHealthStatusForSV(svId, health));
    }

    SetBeiDouHealthStatusForSVPtr SetBeiDouHealthStatusForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouHealthStatusForSV>(ptr);
    }

    bool SetBeiDouHealthStatusForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetBeiDouHealthStatusForSV::documentation() const { return Documentation; }


    int SetBeiDouHealthStatusForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouHealthStatusForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouHealthStatusForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouHealthStatusForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouHealthStatusForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
