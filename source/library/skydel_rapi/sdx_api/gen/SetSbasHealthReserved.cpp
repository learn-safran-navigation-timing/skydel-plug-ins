#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasHealthReserved
///
#include "gen/SetSbasHealthReserved.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasHealthReserved::CmdName = "SetSbasHealthReserved";
    const char* const SetSbasHealthReserved::Documentation = "Please note the command SetSbasHealthReserved is deprecated since 21.9. You may use SetSbasSVReservedHealth.\n\nApply reserved flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasHealthReserved);


    SetSbasHealthReserved::SetSbasHealthReserved()
      : CommandBase(CmdName)
    {}

    SetSbasHealthReserved::SetSbasHealthReserved(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetSbasHealthReservedPtr SetSbasHealthReserved::create(int prn, bool health)
    {
      return std::make_shared<SetSbasHealthReserved>(prn, health);
    }

    SetSbasHealthReservedPtr SetSbasHealthReserved::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasHealthReserved>(ptr);
    }

    bool SetSbasHealthReserved::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasHealthReserved::documentation() const { return Documentation; }


    int SetSbasHealthReserved::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasHealthReserved::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSbasHealthReserved::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasHealthReserved::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasHealthReserved::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
