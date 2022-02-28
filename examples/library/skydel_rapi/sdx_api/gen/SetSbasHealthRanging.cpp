#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasHealthRanging
///
#include "gen/SetSbasHealthRanging.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasHealthRanging::CmdName = "SetSbasHealthRanging";
    const char* const SetSbasHealthRanging::Documentation = "Please note the command SetSbasHealthRanging is deprecated since 21.9. You may use SetSbasSVRangingHealth.\n\nApply ranging flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasHealthRanging);


    SetSbasHealthRanging::SetSbasHealthRanging()
      : CommandBase(CmdName)
    {}

    SetSbasHealthRanging::SetSbasHealthRanging(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetSbasHealthRangingPtr SetSbasHealthRanging::create(int prn, bool health)
    {
      return std::make_shared<SetSbasHealthRanging>(prn, health);
    }

    SetSbasHealthRangingPtr SetSbasHealthRanging::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasHealthRanging>(ptr);
    }

    bool SetSbasHealthRanging::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasHealthRanging::documentation() const { return Documentation; }


    int SetSbasHealthRanging::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasHealthRanging::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSbasHealthRanging::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasHealthRanging::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasHealthRanging::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
