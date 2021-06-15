#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisDoubleParamResult
///
#include "gen/GetGpsEphemerisDoubleParamResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisDoubleParamResult::CmdName = "GetGpsEphemerisDoubleParamResult";
    const char* const GetGpsEphemerisDoubleParamResult::Documentation = "Result of GetGpsEphemerisDoubleParam.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsEphemerisDoubleParamResult);


    GetGpsEphemerisDoubleParamResult::GetGpsEphemerisDoubleParamResult()
      : CommandResult(CmdName)
    {}

    GetGpsEphemerisDoubleParamResult::GetGpsEphemerisDoubleParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    GetGpsEphemerisDoubleParamResultPtr GetGpsEphemerisDoubleParamResult::create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
    {
      return GetGpsEphemerisDoubleParamResultPtr(new GetGpsEphemerisDoubleParamResult(relatedCommand, prn, paramName, val));
    }

    GetGpsEphemerisDoubleParamResultPtr GetGpsEphemerisDoubleParamResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisDoubleParamResult>(ptr);
    }

    bool GetGpsEphemerisDoubleParamResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetGpsEphemerisDoubleParamResult::documentation() const { return Documentation; }


    int GetGpsEphemerisDoubleParamResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsEphemerisDoubleParamResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphemerisDoubleParamResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphemerisDoubleParamResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsEphemerisDoubleParamResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetGpsEphemerisDoubleParamResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
