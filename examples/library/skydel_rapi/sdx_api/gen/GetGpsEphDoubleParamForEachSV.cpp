#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphDoubleParamForEachSV
///
#include "gen/GetGpsEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphDoubleParamForEachSV::CmdName = "GetGpsEphDoubleParamForEachSV";
    const char* const GetGpsEphDoubleParamForEachSV::Documentation = "Please note the command GetGpsEphemerisDoubleParams is deprecated since 21.3. You may use GetGpsEphDoubleParamForEachSV.\n\nGet GPS ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetGpsEphDoubleParamForEachSV);


    GetGpsEphDoubleParamForEachSV::GetGpsEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetGpsEphDoubleParamForEachSV::GetGpsEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }


    GetGpsEphDoubleParamForEachSVPtr GetGpsEphDoubleParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return GetGpsEphDoubleParamForEachSVPtr(new GetGpsEphDoubleParamForEachSV(paramName, dataSetName));
    }

    GetGpsEphDoubleParamForEachSVPtr GetGpsEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphDoubleParamForEachSV>(ptr);
    }

    bool GetGpsEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int GetGpsEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
