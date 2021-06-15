#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphemerisReferenceTime
///
#include "gen/GetGalileoEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphemerisReferenceTime::CmdName = "GetGalileoEphemerisReferenceTime";
    const char* const GetGalileoEphemerisReferenceTime::Documentation = "Please note the command GetGalileoEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.\n\nGet the Galileo ephemeris reference time";

    REGISTER_COMMAND_FACTORY(GetGalileoEphemerisReferenceTime);


    GetGalileoEphemerisReferenceTime::GetGalileoEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    GetGalileoEphemerisReferenceTime::GetGalileoEphemerisReferenceTime(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGalileoEphemerisReferenceTimePtr GetGalileoEphemerisReferenceTime::create(int prn)
    {
      return GetGalileoEphemerisReferenceTimePtr(new GetGalileoEphemerisReferenceTime(prn));
    }

    GetGalileoEphemerisReferenceTimePtr GetGalileoEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphemerisReferenceTime>(ptr);
    }

    bool GetGalileoEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGalileoEphemerisReferenceTime::documentation() const { return Documentation; }


    int GetGalileoEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoEphemerisReferenceTime::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoEphemerisReferenceTime::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
