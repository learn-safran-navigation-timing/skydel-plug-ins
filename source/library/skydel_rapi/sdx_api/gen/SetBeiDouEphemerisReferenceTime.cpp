#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphemerisReferenceTime
///
#include "gen/SetBeiDouEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphemerisReferenceTime::CmdName = "SetBeiDouEphemerisReferenceTime";
    const char* const SetBeiDouEphemerisReferenceTime::Documentation = "Please note the command SetBeiDouEphemerisReferenceTime is deprecated since 21.3. You may use SetEphemerisReferenceTimeForSV.\n\nSet the BeiDou ephemeris reference time";

    REGISTER_COMMAND_FACTORY(SetBeiDouEphemerisReferenceTime);


    SetBeiDouEphemerisReferenceTime::SetBeiDouEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    SetBeiDouEphemerisReferenceTime::SetBeiDouEphemerisReferenceTime(int prn, const Sdx::DateTime& time)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setTime(time);
    }


    SetBeiDouEphemerisReferenceTimePtr SetBeiDouEphemerisReferenceTime::create(int prn, const Sdx::DateTime& time)
    {
      return SetBeiDouEphemerisReferenceTimePtr(new SetBeiDouEphemerisReferenceTime(prn, time));
    }

    SetBeiDouEphemerisReferenceTimePtr SetBeiDouEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphemerisReferenceTime>(ptr);
    }

    bool SetBeiDouEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string SetBeiDouEphemerisReferenceTime::documentation() const { return Documentation; }


    int SetBeiDouEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetBeiDouEphemerisReferenceTime::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouEphemerisReferenceTime::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetBeiDouEphemerisReferenceTime::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void SetBeiDouEphemerisReferenceTime::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
