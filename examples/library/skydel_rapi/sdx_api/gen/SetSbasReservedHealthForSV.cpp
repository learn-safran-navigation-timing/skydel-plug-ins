#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasReservedHealthForSV
///
#include "gen/SetSbasReservedHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasReservedHealthForSV::CmdName = "SetSbasReservedHealthForSV";
    const char* const SetSbasReservedHealthForSV::Documentation = "Apply reserved flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasReservedHealthForSV);


    SetSbasReservedHealthForSV::SetSbasReservedHealthForSV()
      : CommandBase(CmdName)
    {}

    SetSbasReservedHealthForSV::SetSbasReservedHealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetSbasReservedHealthForSVPtr SetSbasReservedHealthForSV::create(int svId, bool health)
    {
      return SetSbasReservedHealthForSVPtr(new SetSbasReservedHealthForSV(svId, health));
    }

    SetSbasReservedHealthForSVPtr SetSbasReservedHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasReservedHealthForSV>(ptr);
    }

    bool SetSbasReservedHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasReservedHealthForSV::documentation() const { return Documentation; }


    int SetSbasReservedHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasReservedHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasReservedHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasReservedHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasReservedHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
