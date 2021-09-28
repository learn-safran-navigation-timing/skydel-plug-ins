#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisDoubleParamResult
///
#include "gen/GetBeiDouEphemerisDoubleParamResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisDoubleParamResult::CmdName = "GetBeiDouEphemerisDoubleParamResult";
    const char* const GetBeiDouEphemerisDoubleParamResult::Documentation = "Result of GetBeiDouEphemerisDoubleParam.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouEphemerisDoubleParamResult);


    GetBeiDouEphemerisDoubleParamResult::GetBeiDouEphemerisDoubleParamResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouEphemerisDoubleParamResult::GetBeiDouEphemerisDoubleParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    GetBeiDouEphemerisDoubleParamResultPtr GetBeiDouEphemerisDoubleParamResult::create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
    {
      return GetBeiDouEphemerisDoubleParamResultPtr(new GetBeiDouEphemerisDoubleParamResult(relatedCommand, prn, paramName, val));
    }

    GetBeiDouEphemerisDoubleParamResultPtr GetBeiDouEphemerisDoubleParamResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisDoubleParamResult>(ptr);
    }

    bool GetBeiDouEphemerisDoubleParamResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetBeiDouEphemerisDoubleParamResult::documentation() const { return Documentation; }


    int GetBeiDouEphemerisDoubleParamResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouEphemerisDoubleParamResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphemerisDoubleParamResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphemerisDoubleParamResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouEphemerisDoubleParamResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetBeiDouEphemerisDoubleParamResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
