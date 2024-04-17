
#include "GetGalileoEphDoubleParamForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphDoubleParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphDoubleParamForSVResult::CmdName = "GetGalileoEphDoubleParamForSVResult";
    const char* const GetGalileoEphDoubleParamForSVResult::Documentation = "Result of GetGalileoEphDoubleParamForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..36, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         double          Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGalileoEphDoubleParamForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGalileoEphDoubleParamForSVResult);


    GetGalileoEphDoubleParamForSVResult::GetGalileoEphDoubleParamForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGalileoEphDoubleParamForSVResult::GetGalileoEphDoubleParamForSVResult(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetGalileoEphDoubleParamForSVResult::GetGalileoEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetGalileoEphDoubleParamForSVResultPtr GetGalileoEphDoubleParamForSVResult::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoEphDoubleParamForSVResult>(svId, paramName, val, dataSetName);
    }

    GetGalileoEphDoubleParamForSVResultPtr GetGalileoEphDoubleParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoEphDoubleParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
    }

    GetGalileoEphDoubleParamForSVResultPtr GetGalileoEphDoubleParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphDoubleParamForSVResult>(ptr);
    }

    bool GetGalileoEphDoubleParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoEphDoubleParamForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGalileoEphDoubleParamForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    int GetGalileoEphDoubleParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGalileoEphDoubleParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoEphDoubleParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphDoubleParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoEphDoubleParamForSVResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetGalileoEphDoubleParamForSVResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGalileoEphDoubleParamForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoEphDoubleParamForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
