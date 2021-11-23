#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouSatMotionFixed
///
#include "gen/SetBeiDouSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouSatMotionFixed::CmdName = "SetBeiDouSatMotionFixed";
    const char* const SetBeiDouSatMotionFixed::Documentation = "Please note the command SetBeiDouSatMotionFixed is deprecated since 21.3. You may use SetSatMotionFixed.\n\nIf IsFixed is set to true, the satellite will not move during the simulation and keep its initial position calculated at the beginning of the simulation.";

    REGISTER_COMMAND_FACTORY(SetBeiDouSatMotionFixed);


    SetBeiDouSatMotionFixed::SetBeiDouSatMotionFixed()
      : CommandBase(CmdName)
    {}

    SetBeiDouSatMotionFixed::SetBeiDouSatMotionFixed(int prn, bool isFixed)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setIsFixed(isFixed);
    }


    SetBeiDouSatMotionFixedPtr SetBeiDouSatMotionFixed::create(int prn, bool isFixed)
    {
      return SetBeiDouSatMotionFixedPtr(new SetBeiDouSatMotionFixed(prn, isFixed));
    }

    SetBeiDouSatMotionFixedPtr SetBeiDouSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouSatMotionFixed>(ptr);
    }

    bool SetBeiDouSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string SetBeiDouSatMotionFixed::documentation() const { return Documentation; }


    int SetBeiDouSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetBeiDouSatMotionFixed::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouSatMotionFixed::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetBeiDouSatMotionFixed::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void SetBeiDouSatMotionFixed::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
