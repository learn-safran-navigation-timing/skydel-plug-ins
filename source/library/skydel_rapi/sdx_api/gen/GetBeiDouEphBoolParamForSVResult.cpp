#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphBoolParamForSVResult
///
#include "gen/GetBeiDouEphBoolParamForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphBoolParamForSVResult::CmdName = "GetBeiDouEphBoolParamForSVResult";
    const char* const GetBeiDouEphBoolParamForSVResult::Documentation = "Result of GetBeiDouEphBoolParamForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouEphBoolParamForSVResult);


    GetBeiDouEphBoolParamForSVResult::GetBeiDouEphBoolParamForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouEphBoolParamForSVResult::GetBeiDouEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
    }


    GetBeiDouEphBoolParamForSVResultPtr GetBeiDouEphBoolParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val)
    {
      return GetBeiDouEphBoolParamForSVResultPtr(new GetBeiDouEphBoolParamForSVResult(relatedCommand, svId, paramName, val));
    }

    GetBeiDouEphBoolParamForSVResultPtr GetBeiDouEphBoolParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphBoolParamForSVResult>(ptr);
    }

    bool GetBeiDouEphBoolParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
        ;

    }

    std::string GetBeiDouEphBoolParamForSVResult::documentation() const { return Documentation; }


    int GetBeiDouEphBoolParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouEphBoolParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphBoolParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphBoolParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouEphBoolParamForSVResult::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void GetBeiDouEphBoolParamForSVResult::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
