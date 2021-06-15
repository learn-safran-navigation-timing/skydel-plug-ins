#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisReferenceTimeResult
///
#include "gen/GetBeiDouEphemerisReferenceTimeResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisReferenceTimeResult::CmdName = "GetBeiDouEphemerisReferenceTimeResult";
    const char* const GetBeiDouEphemerisReferenceTimeResult::Documentation = "Result of GetBeiDouEphemerisReferenceTime.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouEphemerisReferenceTimeResult);


    GetBeiDouEphemerisReferenceTimeResult::GetBeiDouEphemerisReferenceTimeResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouEphemerisReferenceTimeResult::GetBeiDouEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setTime(time);
    }


    GetBeiDouEphemerisReferenceTimeResultPtr GetBeiDouEphemerisReferenceTimeResult::create(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time)
    {
      return GetBeiDouEphemerisReferenceTimeResultPtr(new GetBeiDouEphemerisReferenceTimeResult(relatedCommand, prn, time));
    }

    GetBeiDouEphemerisReferenceTimeResultPtr GetBeiDouEphemerisReferenceTimeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisReferenceTimeResult>(ptr);
    }

    bool GetBeiDouEphemerisReferenceTimeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string GetBeiDouEphemerisReferenceTimeResult::documentation() const { return Documentation; }


    int GetBeiDouEphemerisReferenceTimeResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouEphemerisReferenceTimeResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetBeiDouEphemerisReferenceTimeResult::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void GetBeiDouEphemerisReferenceTimeResult::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
