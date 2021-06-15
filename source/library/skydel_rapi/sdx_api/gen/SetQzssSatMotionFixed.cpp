#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatMotionFixed
///
#include "gen/SetQzssSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatMotionFixed::CmdName = "SetQzssSatMotionFixed";
    const char* const SetQzssSatMotionFixed::Documentation = "Please note the command SetQzssSatMotionFixed is deprecated since 20.9. You may use SetSatMotionFixed.\n\nIf IsFixed is set to true, the satellite will not move during the simulation and keep its initial position calculated at the beginning of the simulation.";

    REGISTER_COMMAND_FACTORY(SetQzssSatMotionFixed);


    SetQzssSatMotionFixed::SetQzssSatMotionFixed()
      : CommandBase(CmdName)
    {}

    SetQzssSatMotionFixed::SetQzssSatMotionFixed(int svId, bool isFixed)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setIsFixed(isFixed);
    }


    SetQzssSatMotionFixedPtr SetQzssSatMotionFixed::create(int svId, bool isFixed)
    {
      return SetQzssSatMotionFixedPtr(new SetQzssSatMotionFixed(svId, isFixed));
    }

    SetQzssSatMotionFixedPtr SetQzssSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssSatMotionFixed>(ptr);
    }

    bool SetQzssSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string SetQzssSatMotionFixed::documentation() const { return Documentation; }


    int SetQzssSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssSatMotionFixed::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssSatMotionFixed::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssSatMotionFixed::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void SetQzssSatMotionFixed::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
