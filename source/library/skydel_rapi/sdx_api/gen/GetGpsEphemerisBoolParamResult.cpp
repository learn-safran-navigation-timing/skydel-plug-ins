#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisBoolParamResult
///
#include "gen/GetGpsEphemerisBoolParamResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisBoolParamResult::CmdName = "GetGpsEphemerisBoolParamResult";
    const char* const GetGpsEphemerisBoolParamResult::Documentation = "Result of GetGpsEphemerisBoolParam.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsEphemerisBoolParamResult);


    GetGpsEphemerisBoolParamResult::GetGpsEphemerisBoolParamResult()
      : CommandResult(CmdName)
    {}

    GetGpsEphemerisBoolParamResult::GetGpsEphemerisBoolParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    GetGpsEphemerisBoolParamResultPtr GetGpsEphemerisBoolParamResult::create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val)
    {
      return GetGpsEphemerisBoolParamResultPtr(new GetGpsEphemerisBoolParamResult(relatedCommand, prn, paramName, val));
    }

    GetGpsEphemerisBoolParamResultPtr GetGpsEphemerisBoolParamResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisBoolParamResult>(ptr);
    }

    bool GetGpsEphemerisBoolParamResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
        ;

    }

    std::string GetGpsEphemerisBoolParamResult::documentation() const { return Documentation; }


    int GetGpsEphemerisBoolParamResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsEphemerisBoolParamResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphemerisBoolParamResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphemerisBoolParamResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsEphemerisBoolParamResult::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void GetGpsEphemerisBoolParamResult::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
