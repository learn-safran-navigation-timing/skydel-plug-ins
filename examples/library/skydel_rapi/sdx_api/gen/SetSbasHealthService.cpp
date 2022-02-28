#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasHealthService
///
#include "gen/SetSbasHealthService.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasHealthService::CmdName = "SetSbasHealthService";
    const char* const SetSbasHealthService::Documentation = "Please note the command SetSbasHealthService is deprecated since 21.9. You may use SetSbasSVServiceHealth.\n\nApply service provider for a satellite";

    REGISTER_COMMAND_FACTORY(SetSbasHealthService);


    SetSbasHealthService::SetSbasHealthService()
      : CommandBase(CmdName)
    {}

    SetSbasHealthService::SetSbasHealthService(int prn, int health)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setHealth(health);
    }


    SetSbasHealthServicePtr SetSbasHealthService::create(int prn, int health)
    {
      return SetSbasHealthServicePtr(new SetSbasHealthService(prn, health));
    }

    SetSbasHealthServicePtr SetSbasHealthService::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasHealthService>(ptr);
    }

    bool SetSbasHealthService::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasHealthService::documentation() const { return Documentation; }


    int SetSbasHealthService::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetSbasHealthService::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSbasHealthService::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSbasHealthService::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetSbasHealthService::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
