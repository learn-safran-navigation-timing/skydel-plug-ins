#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSignalHealthForSV
///
#include "gen/SetGalileoSignalHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSignalHealthForSV::CmdName = "SetGalileoSignalHealthForSV";
    const char* const SetGalileoSignalHealthForSV::Documentation = "Set Galileo signal health for I/NAV and F/NAV message";

    REGISTER_COMMAND_FACTORY(SetGalileoSignalHealthForSV);


    SetGalileoSignalHealthForSV::SetGalileoSignalHealthForSV()
      : CommandBase(CmdName)
    {}

    SetGalileoSignalHealthForSV::SetGalileoSignalHealthForSV(int svId, const std::string& component, int health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
    }


    SetGalileoSignalHealthForSVPtr SetGalileoSignalHealthForSV::create(int svId, const std::string& component, int health)
    {
      return SetGalileoSignalHealthForSVPtr(new SetGalileoSignalHealthForSV(svId, component, health));
    }

    SetGalileoSignalHealthForSVPtr SetGalileoSignalHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSignalHealthForSV>(ptr);
    }

    bool SetGalileoSignalHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGalileoSignalHealthForSV::documentation() const { return Documentation; }


    int SetGalileoSignalHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGalileoSignalHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGalileoSignalHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGalileoSignalHealthForSV::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void SetGalileoSignalHealthForSV::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoSignalHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGalileoSignalHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
