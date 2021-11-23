#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSatMotionFixed
///
#include "gen/SetGalileoSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSatMotionFixed::CmdName = "SetGalileoSatMotionFixed";
    const char* const SetGalileoSatMotionFixed::Documentation = "Please note the command SetGalileoSatMotionFixed is deprecated since 21.3. You may use SetSatMotionFixed.\n\nIf IsFixed is set to true, the satellite will not move during the simulation and keep its initial position calculated at the beginning of the simulation.";

    REGISTER_COMMAND_FACTORY(SetGalileoSatMotionFixed);


    SetGalileoSatMotionFixed::SetGalileoSatMotionFixed()
      : CommandBase(CmdName)
    {}

    SetGalileoSatMotionFixed::SetGalileoSatMotionFixed(int prn, bool isFixed)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setIsFixed(isFixed);
    }


    SetGalileoSatMotionFixedPtr SetGalileoSatMotionFixed::create(int prn, bool isFixed)
    {
      return SetGalileoSatMotionFixedPtr(new SetGalileoSatMotionFixed(prn, isFixed));
    }

    SetGalileoSatMotionFixedPtr SetGalileoSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSatMotionFixed>(ptr);
    }

    bool SetGalileoSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string SetGalileoSatMotionFixed::documentation() const { return Documentation; }


    int SetGalileoSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGalileoSatMotionFixed::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoSatMotionFixed::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGalileoSatMotionFixed::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void SetGalileoSatMotionFixed::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
