#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsL1cHealthForSV
///
#include "gen/SetGpsL1cHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsL1cHealthForSV::CmdName = "SetGpsL1cHealthForSV";
    const char* const SetGpsL1cHealthForSV::Documentation = "Set GPS L1C health (used in CNAV2 only)";

    REGISTER_COMMAND_FACTORY(SetGpsL1cHealthForSV);


    SetGpsL1cHealthForSV::SetGpsL1cHealthForSV()
      : CommandBase(CmdName)
    {}

    SetGpsL1cHealthForSV::SetGpsL1cHealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetGpsL1cHealthForSVPtr SetGpsL1cHealthForSV::create(int svId, bool health)
    {
      return SetGpsL1cHealthForSVPtr(new SetGpsL1cHealthForSV(svId, health));
    }

    SetGpsL1cHealthForSVPtr SetGpsL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsL1cHealthForSV>(ptr);
    }

    bool SetGpsL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGpsL1cHealthForSV::documentation() const { return Documentation; }


    int SetGpsL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsL1cHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsL1cHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
