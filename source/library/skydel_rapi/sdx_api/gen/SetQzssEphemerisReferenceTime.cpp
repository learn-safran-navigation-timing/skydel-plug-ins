#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphemerisReferenceTime
///
#include "gen/SetQzssEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphemerisReferenceTime::CmdName = "SetQzssEphemerisReferenceTime";
    const char* const SetQzssEphemerisReferenceTime::Documentation = "Please note the command SetQzssEphemerisReferenceTime is deprecated since 20.9. You may use SetEphemerisReferenceTimeForSV.\n\nSet the QZSS ephemeris reference time";

    REGISTER_COMMAND_FACTORY(SetQzssEphemerisReferenceTime);


    SetQzssEphemerisReferenceTime::SetQzssEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    SetQzssEphemerisReferenceTime::SetQzssEphemerisReferenceTime(int svId, const Sdx::DateTime& time)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setTime(time);
    }


    SetQzssEphemerisReferenceTimePtr SetQzssEphemerisReferenceTime::create(int svId, const Sdx::DateTime& time)
    {
      return SetQzssEphemerisReferenceTimePtr(new SetQzssEphemerisReferenceTime(svId, time));
    }

    SetQzssEphemerisReferenceTimePtr SetQzssEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphemerisReferenceTime>(ptr);
    }

    bool SetQzssEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string SetQzssEphemerisReferenceTime::documentation() const { return Documentation; }


    int SetQzssEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssEphemerisReferenceTime::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssEphemerisReferenceTime::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetQzssEphemerisReferenceTime::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void SetQzssEphemerisReferenceTime::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
