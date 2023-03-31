#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisReferenceTimeResult
///
#include "gen/GetGpsEphemerisReferenceTimeResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisReferenceTimeResult::CmdName = "GetGpsEphemerisReferenceTimeResult";
    const char* const GetGpsEphemerisReferenceTimeResult::Documentation = "Result of GetGpsEphemerisReferenceTime.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsEphemerisReferenceTimeResult);


    GetGpsEphemerisReferenceTimeResult::GetGpsEphemerisReferenceTimeResult()
      : CommandResult(CmdName)
    {}

    GetGpsEphemerisReferenceTimeResult::GetGpsEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setTime(time);
    }


    GetGpsEphemerisReferenceTimeResultPtr GetGpsEphemerisReferenceTimeResult::create(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time)
    {
      return GetGpsEphemerisReferenceTimeResultPtr(new GetGpsEphemerisReferenceTimeResult(relatedCommand, prn, time));
    }

    GetGpsEphemerisReferenceTimeResultPtr GetGpsEphemerisReferenceTimeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisReferenceTimeResult>(ptr);
    }

    bool GetGpsEphemerisReferenceTimeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string GetGpsEphemerisReferenceTimeResult::documentation() const { return Documentation; }


    int GetGpsEphemerisReferenceTimeResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsEphemerisReferenceTimeResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetGpsEphemerisReferenceTimeResult::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void GetGpsEphemerisReferenceTimeResult::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
