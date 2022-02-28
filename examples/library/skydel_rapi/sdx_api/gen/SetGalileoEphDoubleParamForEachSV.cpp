#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoEphDoubleParamForEachSV
///
#include "gen/SetGalileoEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoEphDoubleParamForEachSV::CmdName = "SetGalileoEphDoubleParamForEachSV";
    const char* const SetGalileoEphDoubleParamForEachSV::Documentation = "Please note the command SetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use SetGalileoEphDoubleParamForEachSV.\n\nSet Galileo ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetGalileoEphDoubleParamForEachSV);


    SetGalileoEphDoubleParamForEachSV::SetGalileoEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetGalileoEphDoubleParamForEachSV::SetGalileoEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    SetGalileoEphDoubleParamForEachSVPtr SetGalileoEphDoubleParamForEachSV::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return SetGalileoEphDoubleParamForEachSVPtr(new SetGalileoEphDoubleParamForEachSV(paramName, val, dataSetName));
    }

    SetGalileoEphDoubleParamForEachSVPtr SetGalileoEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoEphDoubleParamForEachSV>(ptr);
    }

    bool SetGalileoEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGalileoEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int SetGalileoEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGalileoEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGalileoEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGalileoEphDoubleParamForEachSV::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetGalileoEphDoubleParamForEachSV::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGalileoEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGalileoEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
