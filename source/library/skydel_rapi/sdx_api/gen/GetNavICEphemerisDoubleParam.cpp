
#include "GetNavICEphemerisDoubleParam.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICEphemerisDoubleParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICEphemerisDoubleParam::CmdName = "GetNavICEphemerisDoubleParam";
    const char* const GetNavICEphemerisDoubleParam::Documentation = "Please note the command GetNavICEphemerisDoubleParam is deprecated since 21.3. You may use GetNavICEphDoubleParamForSV.\n"
      "\n"
      "Please note the command GetNavICEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get various parameters in the NavIC ephemeris\n"
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
      "  \"Tgd\"             sec\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICEphemerisDoubleParam::TargetId = "";

    const char* const GetNavICEphemerisDoubleParam::Deprecated = "Please note the command GetNavICEphemerisDoubleParam is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICEphemerisDoubleParam);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICEphemerisDoubleParam);


    GetNavICEphemerisDoubleParam::GetNavICEphemerisDoubleParam()
      : CommandBase(CmdName, TargetId)
    {}

    GetNavICEphemerisDoubleParam::GetNavICEphemerisDoubleParam(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetNavICEphemerisDoubleParamPtr GetNavICEphemerisDoubleParam::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICEphemerisDoubleParam>(svId, paramName, dataSetName);
    }

    GetNavICEphemerisDoubleParamPtr GetNavICEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICEphemerisDoubleParam>(ptr);
    }

    bool GetNavICEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICEphemerisDoubleParam::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICEphemerisDoubleParam::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetNavICEphemerisDoubleParam::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetNavICEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICEphemerisDoubleParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICEphemerisDoubleParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetNavICEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetNavICEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICEphemerisDoubleParam::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICEphemerisDoubleParam::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
