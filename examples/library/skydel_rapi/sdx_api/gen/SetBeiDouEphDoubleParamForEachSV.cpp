#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphDoubleParamForEachSV
///
#include "gen/SetBeiDouEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphDoubleParamForEachSV::CmdName = "SetBeiDouEphDoubleParamForEachSV";
    const char* const SetBeiDouEphDoubleParamForEachSV::Documentation = "Please note the command SetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use SetBeiDouEphDoubleParamForEachSV.\n\nSet BeiDou ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetBeiDouEphDoubleParamForEachSV);


    SetBeiDouEphDoubleParamForEachSV::SetBeiDouEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouEphDoubleParamForEachSV::SetBeiDouEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    SetBeiDouEphDoubleParamForEachSVPtr SetBeiDouEphDoubleParamForEachSV::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return SetBeiDouEphDoubleParamForEachSVPtr(new SetBeiDouEphDoubleParamForEachSV(paramName, val, dataSetName));
    }

    SetBeiDouEphDoubleParamForEachSVPtr SetBeiDouEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphDoubleParamForEachSV>(ptr);
    }

    bool SetBeiDouEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int SetBeiDouEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetBeiDouEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetBeiDouEphDoubleParamForEachSV::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetBeiDouEphDoubleParamForEachSV::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
