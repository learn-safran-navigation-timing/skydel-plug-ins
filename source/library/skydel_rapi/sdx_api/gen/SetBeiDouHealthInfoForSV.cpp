#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouHealthInfoForSV
///
#include "gen/SetBeiDouHealthInfoForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouHealthInfoForSV::CmdName = "SetBeiDouHealthInfoForSV";
    const char* const SetBeiDouHealthInfoForSV::Documentation = "Set BeiDou satellite health info";

    REGISTER_COMMAND_FACTORY(SetBeiDouHealthInfoForSV);


    SetBeiDouHealthInfoForSV::SetBeiDouHealthInfoForSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouHealthInfoForSV::SetBeiDouHealthInfoForSV(int svId, int health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetBeiDouHealthInfoForSVPtr SetBeiDouHealthInfoForSV::create(int svId, int health)
    {
      return SetBeiDouHealthInfoForSVPtr(new SetBeiDouHealthInfoForSV(svId, health));
    }

    SetBeiDouHealthInfoForSVPtr SetBeiDouHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouHealthInfoForSV>(ptr);
    }

    bool SetBeiDouHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetBeiDouHealthInfoForSV::documentation() const { return Documentation; }


    int SetBeiDouHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouHealthInfoForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouHealthInfoForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
