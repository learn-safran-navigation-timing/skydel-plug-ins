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

    GetGpsEphDoubleParamForEachSV::GetGpsEphDoubleParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
    }


    GetGpsEphDoubleParamForEachSVPtr GetGpsEphDoubleParamForEachSV::create(const std::string& paramName)
    {
      return GetGpsEphDoubleParamForEachSVPtr(new GetGpsEphDoubleParamForEachSV(paramName));
    }

    GetGpsEphDoubleParamForEachSVPtr GetGpsEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphDoubleParamForEachSV>(ptr);
    }

    bool GetGpsEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
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


  }
}
