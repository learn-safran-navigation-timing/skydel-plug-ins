#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphDoubleParamForEachSV
///
#include "gen/SetQzssEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphDoubleParamForEachSV::CmdName = "SetQzssEphDoubleParamForEachSV";
    const char* const SetQzssEphDoubleParamForEachSV::Documentation = "Please note the command SetQzssEphemerisDoubleParams is deprecated since 21.3. You may use SetQzssEphDoubleParamForEachSV.\n\nSet QZSS ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetQzssEphDoubleParamForEachSV);


    SetQzssEphDoubleParamForEachSV::SetQzssEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetQzssEphDoubleParamForEachSV::SetQzssEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    SetQzssEphDoubleParamForEachSVPtr SetQzssEphDoubleParamForEachSV::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphDoubleParamForEachSV>(paramName, val, dataSetName);
    }

    SetQzssEphDoubleParamForEachSVPtr SetQzssEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphDoubleParamForEachSV>(ptr);
    }

    bool SetQzssEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int SetQzssEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetQzssEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetQzssEphDoubleParamForEachSV::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetQzssEphDoubleParamForEachSV::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
