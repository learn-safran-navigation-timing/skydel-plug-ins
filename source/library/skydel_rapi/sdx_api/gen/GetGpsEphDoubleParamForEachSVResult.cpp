#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphDoubleParamForEachSVResult
///
#include "gen/GetGpsEphDoubleParamForEachSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphDoubleParamForEachSVResult::CmdName = "GetGpsEphDoubleParamForEachSVResult";
    const char* const GetGpsEphDoubleParamForEachSVResult::Documentation = "Result of GetGpsEphDoubleParamForEachSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsEphDoubleParamForEachSVResult);


    GetGpsEphDoubleParamForEachSVResult::GetGpsEphDoubleParamForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsEphDoubleParamForEachSVResult::GetGpsEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val)
      : CommandResult(CmdName, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
    }


    GetGpsEphDoubleParamForEachSVResultPtr GetGpsEphDoubleParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val)
    {
      return GetGpsEphDoubleParamForEachSVResultPtr(new GetGpsEphDoubleParamForEachSVResult(relatedCommand, paramName, val));
    }

    GetGpsEphDoubleParamForEachSVResultPtr GetGpsEphDoubleParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphDoubleParamForEachSVResult>(ptr);
    }

    bool GetGpsEphDoubleParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
        ;

    }

    std::string GetGpsEphDoubleParamForEachSVResult::documentation() const { return Documentation; }


    std::string GetGpsEphDoubleParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphDoubleParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGpsEphDoubleParamForEachSVResult::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void GetGpsEphDoubleParamForEachSVResult::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
