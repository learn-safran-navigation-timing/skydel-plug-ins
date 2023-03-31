#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasHealthIntegrity
///
#include "gen/SetSbasHealthIntegrity.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasHealthIntegrity::CmdName = "SetSbasHealthIntegrity";
    const char* const SetSbasHealthIntegrity::Documentation = "Please note the command SetSbasHealthIntegrity is deprecated since 21.9. You may use SetSbasSVIntegrityHealth.\n\nApply integrity flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasHealthIntegrity);


    SetSbasHealthIntegrity::SetSbasHealthIntegrity()
      : CommandBase(CmdName)
    {}

    SetSbasHealthIntegrity::SetSbasHealthIntegrity(int prn, bool health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetSbasHealthIntegrityPtr SetSbasHealthIntegrity::create(int prn, bool health)
    {
      return std::make_shared<SetSbasHealthIntegrity>(prn, health);
    }

    SetSbasHealthIntegrityPtr SetSbasHealthIntegrity::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasHealthIntegrity>(ptr);
    }

    bool SetSbasHealthIntegrity::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasHealthIntegrity::documentation() const { return Documentation; }


    int SetSbasHealthIntegrity::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasHealthIntegrity::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSbasHealthIntegrity::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasHealthIntegrity::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasHealthIntegrity::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
