#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphemerisReferenceTimeResult
///
#include "gen/GetGalileoEphemerisReferenceTimeResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphemerisReferenceTimeResult::CmdName = "GetGalileoEphemerisReferenceTimeResult";
    const char* const GetGalileoEphemerisReferenceTimeResult::Documentation = "Result of GetGalileoEphemerisReferenceTime.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoEphemerisReferenceTimeResult);


    GetGalileoEphemerisReferenceTimeResult::GetGalileoEphemerisReferenceTimeResult()
      : CommandResult(CmdName)
    {}

    GetGalileoEphemerisReferenceTimeResult::GetGalileoEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setTime(time);
    }


    GetGalileoEphemerisReferenceTimeResultPtr GetGalileoEphemerisReferenceTimeResult::create(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time)
    {
      return GetGalileoEphemerisReferenceTimeResultPtr(new GetGalileoEphemerisReferenceTimeResult(relatedCommand, prn, time));
    }

    GetGalileoEphemerisReferenceTimeResultPtr GetGalileoEphemerisReferenceTimeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphemerisReferenceTimeResult>(ptr);
    }

    bool GetGalileoEphemerisReferenceTimeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string GetGalileoEphemerisReferenceTimeResult::documentation() const { return Documentation; }


    int GetGalileoEphemerisReferenceTimeResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoEphemerisReferenceTimeResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetGalileoEphemerisReferenceTimeResult::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void GetGalileoEphemerisReferenceTimeResult::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
