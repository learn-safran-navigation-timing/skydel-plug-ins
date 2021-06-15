#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatMotionFixed
///
#include "gen/SetGpsSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatMotionFixed::CmdName = "SetGpsSatMotionFixed";
    const char* const SetGpsSatMotionFixed::Documentation = "Please note the command SetGpsSatMotionFixed is deprecated since 21.3. You may use SetSatMotionFixed.\n\nIf IsFixed is set to true, the satellite will not move during the simulation and keep its initial position calculated at the beginning of the simulation.";

    REGISTER_COMMAND_FACTORY(SetGpsSatMotionFixed);


    SetGpsSatMotionFixed::SetGpsSatMotionFixed()
      : CommandBase(CmdName)
    {}

    SetGpsSatMotionFixed::SetGpsSatMotionFixed(int prn, bool isFixed)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setIsFixed(isFixed);
    }


    SetGpsSatMotionFixedPtr SetGpsSatMotionFixed::create(int prn, bool isFixed)
    {
      return SetGpsSatMotionFixedPtr(new SetGpsSatMotionFixed(prn, isFixed));
    }

    SetGpsSatMotionFixedPtr SetGpsSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatMotionFixed>(ptr);
    }

    bool SetGpsSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string SetGpsSatMotionFixed::documentation() const { return Documentation; }


    int SetGpsSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsSatMotionFixed::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatMotionFixed::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsSatMotionFixed::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void SetGpsSatMotionFixed::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
