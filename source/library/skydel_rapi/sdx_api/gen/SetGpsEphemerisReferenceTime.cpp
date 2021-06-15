#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphemerisReferenceTime
///
#include "gen/SetGpsEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphemerisReferenceTime::CmdName = "SetGpsEphemerisReferenceTime";
    const char* const SetGpsEphemerisReferenceTime::Documentation = "Please note the command SetGpsEphemerisReferenceTime is deprecated since 21.3. You may use SetEphemerisReferenceTimeForSV.\n\nSet the GPS ephemeris reference time";

    REGISTER_COMMAND_FACTORY(SetGpsEphemerisReferenceTime);


    SetGpsEphemerisReferenceTime::SetGpsEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    SetGpsEphemerisReferenceTime::SetGpsEphemerisReferenceTime(int prn, const Sdx::DateTime& time)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setTime(time);
    }


    SetGpsEphemerisReferenceTimePtr SetGpsEphemerisReferenceTime::create(int prn, const Sdx::DateTime& time)
    {
      return SetGpsEphemerisReferenceTimePtr(new SetGpsEphemerisReferenceTime(prn, time));
    }

    SetGpsEphemerisReferenceTimePtr SetGpsEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphemerisReferenceTime>(ptr);
    }

    bool SetGpsEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string SetGpsEphemerisReferenceTime::documentation() const { return Documentation; }


    int SetGpsEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsEphemerisReferenceTime::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsEphemerisReferenceTime::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetGpsEphemerisReferenceTime::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void SetGpsEphemerisReferenceTime::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
