
#include "GetBeiDouEphDoubleParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphDoubleParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphDoubleParamForSV::CmdName = "GetBeiDouEphDoubleParamForSV";
    const char* const GetBeiDouEphDoubleParamForSV::Documentation = "Please note the command GetBeiDouEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get various parameters in the BeiDou ephemeris\n"
      "\n"
      "  ParamName         Unit\n"
      "  \"ClockBias\"       sec\n"
      "  \"ClockDrift\"      sec/sec\n"
      "  \"ClockDriftRate\"  sec/sec^2\n"
      "  \"Crs\"             meter\n"
      "  \"Crc\"             meter\n"
      "  \"Cis\"             rad\n"
      "  \"Cic\"             rad\n"
      "  \"Cus\"             rad\n"
      "  \"Cuc\"             rad\n"
      "  \"DeltaN\"          rad/sec\n"
      "  \"M0\"              rad\n"
      "  \"Eccentricity\"    -\n"
      "  \"SqrtA\"           sqrt(meter)\n"
      "  \"BigOmega\"        rad\n"
      "  \"I0\"              rad\n"
      "  \"LittleOmega\"     rad\n"
      "  \"BigOmegaDot\"     rad/sec\n"
      "  \"Idot\"            rad/sec\n"
      "  \"Accuracy\"        meter\n"
      "  \"Adot\"            meters/sec\n"
      "  \"DeltaN0dot\"      rad/sec^2\n"
      "  \"Tgd1\"            sec\n"
      "  \"Tgd2\"            sec\n"
      "  \"TgdB1Cp\"         sec\n"
      "  \"TgdB2Ap\"         sec\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouEphDoubleParamForSV::TargetId = "";

    const char* const GetBeiDouEphDoubleParamForSV::Deprecated = "Please note the command GetBeiDouEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouEphDoubleParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouEphDoubleParamForSV);


    GetBeiDouEphDoubleParamForSV::GetBeiDouEphDoubleParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetBeiDouEphDoubleParamForSV::GetBeiDouEphDoubleParamForSV(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphDoubleParamForSVPtr GetBeiDouEphDoubleParamForSV::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphDoubleParamForSV>(svId, paramName, dataSetName);
    }

    GetBeiDouEphDoubleParamForSVPtr GetBeiDouEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphDoubleParamForSV>(ptr);
    }

    bool GetBeiDouEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphDoubleParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouEphDoubleParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetBeiDouEphDoubleParamForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetBeiDouEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphDoubleParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphDoubleParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
