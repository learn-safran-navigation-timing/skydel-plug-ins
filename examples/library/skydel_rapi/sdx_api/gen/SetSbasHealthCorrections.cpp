#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasHealthCorrections
///
#include "gen/SetSbasHealthCorrections.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasHealthCorrections::CmdName = "SetSbasHealthCorrections";
    const char* const SetSbasHealthCorrections::Documentation = "Please note the command SetSbasHealthCorrections is deprecated since 21.9. You may use SetSbasSVCorrectionsHealth.\n\nApply correction flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasHealthCorrections);


    SetSbasHealthCorrections::SetSbasHealthCorrections()
      : CommandBase(CmdName)
    {}

    SetSbasHealthCorrections::SetSbasHealthCorrections(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetSbasHealthCorrectionsPtr SetSbasHealthCorrections::create(int prn, bool health)
    {
      return SetSbasHealthCorrectionsPtr(new SetSbasHealthCorrections(prn, health));
    }

    SetSbasHealthCorrectionsPtr SetSbasHealthCorrections::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasHealthCorrections>(ptr);
    }

    bool SetSbasHealthCorrections::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasHealthCorrections::documentation() const { return Documentation; }


    int SetSbasHealthCorrections::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasHealthCorrections::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSbasHealthCorrections::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasHealthCorrections::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasHealthCorrections::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
