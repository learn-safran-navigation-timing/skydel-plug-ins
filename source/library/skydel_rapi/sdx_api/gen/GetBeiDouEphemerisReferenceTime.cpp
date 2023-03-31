#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisReferenceTime
///
#include "gen/GetBeiDouEphemerisReferenceTime.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisReferenceTime::CmdName = "GetBeiDouEphemerisReferenceTime";
    const char* const GetBeiDouEphemerisReferenceTime::Documentation = "Please note the command GetBeiDouEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.\n\nGet the BeiDou ephemeris reference time";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphemerisReferenceTime);


    GetBeiDouEphemerisReferenceTime::GetBeiDouEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphemerisReferenceTime::GetBeiDouEphemerisReferenceTime(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouEphemerisReferenceTimePtr GetBeiDouEphemerisReferenceTime::create(int prn)
    {
      return GetBeiDouEphemerisReferenceTimePtr(new GetBeiDouEphemerisReferenceTime(prn));
    }

    GetBeiDouEphemerisReferenceTimePtr GetBeiDouEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisReferenceTime>(ptr);
    }

    bool GetBeiDouEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouEphemerisReferenceTime::documentation() const { return Documentation; }


    int GetBeiDouEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouEphemerisReferenceTime::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouEphemerisReferenceTime::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
