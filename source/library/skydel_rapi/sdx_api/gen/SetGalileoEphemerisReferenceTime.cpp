#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoEphemerisReferenceTime
///
#include "gen/SetGalileoEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoEphemerisReferenceTime::CmdName = "SetGalileoEphemerisReferenceTime";
    const char* const SetGalileoEphemerisReferenceTime::Documentation = "Please note the command SetGalileoEphemerisReferenceTime is deprecated since 21.3. You may use SetEphemerisReferenceTimeForSV.\n\nSet the Galileo ephemeris reference time";

    REGISTER_COMMAND_FACTORY(SetGalileoEphemerisReferenceTime);


    SetGalileoEphemerisReferenceTime::SetGalileoEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    SetGalileoEphemerisReferenceTime::SetGalileoEphemerisReferenceTime(int prn, const Sdx::DateTime& time)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setTime(time);
    }


    SetGalileoEphemerisReferenceTimePtr SetGalileoEphemerisReferenceTime::create(int prn, const Sdx::DateTime& time)
    {
      return SetGalileoEphemerisReferenceTimePtr(new SetGalileoEphemerisReferenceTime(prn, time));
    }

    SetGalileoEphemerisReferenceTimePtr SetGalileoEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoEphemerisReferenceTime>(ptr);
    }

    bool SetGalileoEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string SetGalileoEphemerisReferenceTime::documentation() const { return Documentation; }


    int SetGalileoEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGalileoEphemerisReferenceTime::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoEphemerisReferenceTime::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetGalileoEphemerisReferenceTime::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void SetGalileoEphemerisReferenceTime::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
