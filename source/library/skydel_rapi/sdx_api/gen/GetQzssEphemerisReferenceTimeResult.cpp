#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisReferenceTimeResult
///
#include "gen/GetQzssEphemerisReferenceTimeResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisReferenceTimeResult::CmdName = "GetQzssEphemerisReferenceTimeResult";
    const char* const GetQzssEphemerisReferenceTimeResult::Documentation = "Result of GetQzssEphemerisReferenceTime.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssEphemerisReferenceTimeResult);


    GetQzssEphemerisReferenceTimeResult::GetQzssEphemerisReferenceTimeResult()
      : CommandResult(CmdName)
    {}

    GetQzssEphemerisReferenceTimeResult::GetQzssEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setTime(time);
    }


    GetQzssEphemerisReferenceTimeResultPtr GetQzssEphemerisReferenceTimeResult::create(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time)
    {
      return GetQzssEphemerisReferenceTimeResultPtr(new GetQzssEphemerisReferenceTimeResult(relatedCommand, svId, time));
    }

    GetQzssEphemerisReferenceTimeResultPtr GetQzssEphemerisReferenceTimeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisReferenceTimeResult>(ptr);
    }

    bool GetQzssEphemerisReferenceTimeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string GetQzssEphemerisReferenceTimeResult::documentation() const { return Documentation; }


    int GetQzssEphemerisReferenceTimeResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphemerisReferenceTimeResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetQzssEphemerisReferenceTimeResult::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void GetQzssEphemerisReferenceTimeResult::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
