#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphemerisDoubleParamResult
///
#include "gen/GetGalileoEphemerisDoubleParamResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphemerisDoubleParamResult::CmdName = "GetGalileoEphemerisDoubleParamResult";
    const char* const GetGalileoEphemerisDoubleParamResult::Documentation = "Result of GetGalileoEphemerisDoubleParam.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoEphemerisDoubleParamResult);


    GetGalileoEphemerisDoubleParamResult::GetGalileoEphemerisDoubleParamResult()
      : CommandResult(CmdName)
    {}

    GetGalileoEphemerisDoubleParamResult::GetGalileoEphemerisDoubleParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    GetGalileoEphemerisDoubleParamResultPtr GetGalileoEphemerisDoubleParamResult::create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
    {
      return GetGalileoEphemerisDoubleParamResultPtr(new GetGalileoEphemerisDoubleParamResult(relatedCommand, prn, paramName, val));
    }

    GetGalileoEphemerisDoubleParamResultPtr GetGalileoEphemerisDoubleParamResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphemerisDoubleParamResult>(ptr);
    }

    bool GetGalileoEphemerisDoubleParamResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetGalileoEphemerisDoubleParamResult::documentation() const { return Documentation; }


    int GetGalileoEphemerisDoubleParamResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoEphemerisDoubleParamResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoEphemerisDoubleParamResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphemerisDoubleParamResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoEphemerisDoubleParamResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetGalileoEphemerisDoubleParamResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
