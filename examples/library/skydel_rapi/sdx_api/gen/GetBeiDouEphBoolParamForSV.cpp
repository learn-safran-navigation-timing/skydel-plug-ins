#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphBoolParamForSV
///
#include "gen/GetBeiDouEphBoolParamForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphBoolParamForSV::CmdName = "GetBeiDouEphBoolParamForSV";
    const char* const GetBeiDouEphBoolParamForSV::Documentation = "Get various boolean parameters in the BeiDou ephemeris\n\n  ParamName\n\"IscB1CdAvailable\"\n\"IscB2adAvailable\"";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphBoolParamForSV);


    GetBeiDouEphBoolParamForSV::GetBeiDouEphBoolParamForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphBoolParamForSV::GetBeiDouEphBoolParamForSV(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }


    GetBeiDouEphBoolParamForSVPtr GetBeiDouEphBoolParamForSV::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphBoolParamForSV>(svId, paramName, dataSetName);
    }

    GetBeiDouEphBoolParamForSVPtr GetBeiDouEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphBoolParamForSV>(ptr);
    }

    bool GetBeiDouEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphBoolParamForSV::documentation() const { return Documentation; }


    int GetBeiDouEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphBoolParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphBoolParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
