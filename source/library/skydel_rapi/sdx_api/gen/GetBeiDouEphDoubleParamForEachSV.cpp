#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphDoubleParamForEachSV
///
#include "gen/GetBeiDouEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphDoubleParamForEachSV::CmdName = "GetBeiDouEphDoubleParamForEachSV";
    const char* const GetBeiDouEphDoubleParamForEachSV::Documentation = "Please note the command GetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use GetBeiDouEphDoubleParamForEachSV.\n\nGet BeiDou ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphDoubleParamForEachSV);


    GetBeiDouEphDoubleParamForEachSV::GetBeiDouEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphDoubleParamForEachSV::GetBeiDouEphDoubleParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
    }


    GetBeiDouEphDoubleParamForEachSVPtr GetBeiDouEphDoubleParamForEachSV::create(const std::string& paramName)
    {
      return GetBeiDouEphDoubleParamForEachSVPtr(new GetBeiDouEphDoubleParamForEachSV(paramName));
    }

    GetBeiDouEphDoubleParamForEachSVPtr GetBeiDouEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphDoubleParamForEachSV>(ptr);
    }

    bool GetBeiDouEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetBeiDouEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int GetBeiDouEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
