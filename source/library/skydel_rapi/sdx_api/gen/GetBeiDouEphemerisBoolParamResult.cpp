#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisBoolParamResult
///
#include "gen/GetBeiDouEphemerisBoolParamResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisBoolParamResult::CmdName = "GetBeiDouEphemerisBoolParamResult";
    const char* const GetBeiDouEphemerisBoolParamResult::Documentation = "Result of GetBeiDouEphemerisBoolParam.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouEphemerisBoolParamResult);


    GetBeiDouEphemerisBoolParamResult::GetBeiDouEphemerisBoolParamResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouEphemerisBoolParamResult::GetBeiDouEphemerisBoolParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    GetBeiDouEphemerisBoolParamResultPtr GetBeiDouEphemerisBoolParamResult::create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val)
    {
      return GetBeiDouEphemerisBoolParamResultPtr(new GetBeiDouEphemerisBoolParamResult(relatedCommand, prn, paramName, val));
    }

    GetBeiDouEphemerisBoolParamResultPtr GetBeiDouEphemerisBoolParamResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisBoolParamResult>(ptr);
    }

    bool GetBeiDouEphemerisBoolParamResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
        ;

    }

    std::string GetBeiDouEphemerisBoolParamResult::documentation() const { return Documentation; }


    int GetBeiDouEphemerisBoolParamResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouEphemerisBoolParamResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphemerisBoolParamResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphemerisBoolParamResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouEphemerisBoolParamResult::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void GetBeiDouEphemerisBoolParamResult::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
