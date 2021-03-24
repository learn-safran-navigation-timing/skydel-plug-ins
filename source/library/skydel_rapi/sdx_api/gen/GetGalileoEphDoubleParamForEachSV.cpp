#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphDoubleParamForEachSV
///
#include "gen/GetGalileoEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphDoubleParamForEachSV::CmdName = "GetGalileoEphDoubleParamForEachSV";
    const char* const GetGalileoEphDoubleParamForEachSV::Documentation = "Please note the command GetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use GetGalileoEphDoubleParamForEachSV.\n\nGet Galileo ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetGalileoEphDoubleParamForEachSV);


    GetGalileoEphDoubleParamForEachSV::GetGalileoEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetGalileoEphDoubleParamForEachSV::GetGalileoEphDoubleParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
    }


    GetGalileoEphDoubleParamForEachSVPtr GetGalileoEphDoubleParamForEachSV::create(const std::string& paramName)
    {
      return GetGalileoEphDoubleParamForEachSVPtr(new GetGalileoEphDoubleParamForEachSV(paramName));
    }

    GetGalileoEphDoubleParamForEachSVPtr GetGalileoEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphDoubleParamForEachSV>(ptr);
    }

    bool GetGalileoEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGalileoEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int GetGalileoEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGalileoEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
