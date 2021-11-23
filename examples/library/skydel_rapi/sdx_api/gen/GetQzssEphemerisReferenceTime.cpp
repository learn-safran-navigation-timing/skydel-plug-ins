#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisReferenceTime
///
#include "gen/GetQzssEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisReferenceTime::CmdName = "GetQzssEphemerisReferenceTime";
    const char* const GetQzssEphemerisReferenceTime::Documentation = "Please note the command GetQzssEphemerisReferenceTime is deprecated since 20.9. You may use GetEphemerisReferenceTimeForSV.\n\nGet the QZSS ephemeris reference time";

    REGISTER_COMMAND_FACTORY(GetQzssEphemerisReferenceTime);


    GetQzssEphemerisReferenceTime::GetQzssEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    GetQzssEphemerisReferenceTime::GetQzssEphemerisReferenceTime(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssEphemerisReferenceTimePtr GetQzssEphemerisReferenceTime::create(int svId)
    {
      return GetQzssEphemerisReferenceTimePtr(new GetQzssEphemerisReferenceTime(svId));
    }

    GetQzssEphemerisReferenceTimePtr GetQzssEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisReferenceTime>(ptr);
    }

    bool GetQzssEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssEphemerisReferenceTime::documentation() const { return Documentation; }


    int GetQzssEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphemerisReferenceTime::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphemerisReferenceTime::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
