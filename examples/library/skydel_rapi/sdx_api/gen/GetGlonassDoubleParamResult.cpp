#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassDoubleParamResult
///
#include "gen/GetGlonassDoubleParamResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassDoubleParamResult::CmdName = "GetGlonassDoubleParamResult";
    const char* const GetGlonassDoubleParamResult::Documentation = "Result of GetGlonassDoubleParam.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGlonassDoubleParamResult);


    GetGlonassDoubleParamResult::GetGlonassDoubleParamResult()
      : CommandResult(CmdName)
    {}

    GetGlonassDoubleParamResult::GetGlonassDoubleParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    GetGlonassDoubleParamResultPtr GetGlonassDoubleParamResult::create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val)
    {
      return GetGlonassDoubleParamResultPtr(new GetGlonassDoubleParamResult(relatedCommand, prn, paramName, val));
    }

    GetGlonassDoubleParamResultPtr GetGlonassDoubleParamResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassDoubleParamResult>(ptr);
    }

    bool GetGlonassDoubleParamResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetGlonassDoubleParamResult::documentation() const { return Documentation; }


    int GetGlonassDoubleParamResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassDoubleParamResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGlonassDoubleParamResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGlonassDoubleParamResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGlonassDoubleParamResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetGlonassDoubleParamResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
