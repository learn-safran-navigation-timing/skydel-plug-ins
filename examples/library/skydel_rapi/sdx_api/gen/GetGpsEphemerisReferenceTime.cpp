#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisReferenceTime
///
#include "gen/GetGpsEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisReferenceTime::CmdName = "GetGpsEphemerisReferenceTime";
    const char* const GetGpsEphemerisReferenceTime::Documentation = "Please note the command GetGpsEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.\n\nGet the GPS ephemeris reference time";

    REGISTER_COMMAND_FACTORY(GetGpsEphemerisReferenceTime);


    GetGpsEphemerisReferenceTime::GetGpsEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    GetGpsEphemerisReferenceTime::GetGpsEphemerisReferenceTime(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsEphemerisReferenceTimePtr GetGpsEphemerisReferenceTime::create(int prn)
    {
      return GetGpsEphemerisReferenceTimePtr(new GetGpsEphemerisReferenceTime(prn));
    }

    GetGpsEphemerisReferenceTimePtr GetGpsEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisReferenceTime>(ptr);
    }

    bool GetGpsEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsEphemerisReferenceTime::documentation() const { return Documentation; }


    int GetGpsEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsEphemerisReferenceTime::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsEphemerisReferenceTime::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
