#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForEachSVResult
///
#include "gen/GetQzssEphBoolParamForEachSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForEachSVResult::CmdName = "GetQzssEphBoolParamForEachSVResult";
    const char* const GetQzssEphBoolParamForEachSVResult::Documentation = "Result of GetQzssEphBoolParamForEachSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssEphBoolParamForEachSVResult);


    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val)
      : CommandResult(CmdName, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
    }


    GetQzssEphBoolParamForEachSVResultPtr GetQzssEphBoolParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val)
    {
      return GetQzssEphBoolParamForEachSVResultPtr(new GetQzssEphBoolParamForEachSVResult(relatedCommand, paramName, val));
    }

    GetQzssEphBoolParamForEachSVResultPtr GetQzssEphBoolParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForEachSVResult>(ptr);
    }

    bool GetQzssEphBoolParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
        ;

    }

    std::string GetQzssEphBoolParamForEachSVResult::documentation() const { return Documentation; }


    std::string GetQzssEphBoolParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetQzssEphBoolParamForEachSVResult::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void GetQzssEphBoolParamForEachSVResult::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
