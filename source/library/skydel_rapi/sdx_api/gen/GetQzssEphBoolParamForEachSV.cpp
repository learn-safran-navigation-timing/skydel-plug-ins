
#include "GetQzssEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForEachSV::CmdName = "GetQzssEphBoolParamForEachSV";
    const char* const GetQzssEphBoolParamForEachSV::Documentation = "Please note the command GetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get QZSS ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphBoolParamForEachSV::TargetId = "";

    const char* const GetQzssEphBoolParamForEachSV::Deprecated = "Please note the command GetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphBoolParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphBoolParamForEachSV);


    GetQzssEphBoolParamForEachSV::GetQzssEphBoolParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphBoolParamForEachSV::GetQzssEphBoolParamForEachSV(const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphBoolParamForEachSVPtr GetQzssEphBoolParamForEachSV::create(const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphBoolParamForEachSV>(paramName, dataSetName);
    }

    GetQzssEphBoolParamForEachSVPtr GetQzssEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForEachSV>(ptr);
    }

    bool GetQzssEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphBoolParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphBoolParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetQzssEphBoolParamForEachSV::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetQzssEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphBoolParamForEachSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
