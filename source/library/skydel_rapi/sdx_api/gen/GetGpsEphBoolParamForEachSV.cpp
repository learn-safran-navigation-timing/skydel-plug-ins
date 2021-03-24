#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForEachSV
///
#include "gen/GetGpsEphBoolParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForEachSV::CmdName = "GetGpsEphBoolParamForEachSV";
    const char* const GetGpsEphBoolParamForEachSV::Documentation = "Please note the command GetGpsEphemerisBoolParams is deprecated since 21.3. You may use GetGpsEphBoolParamForEachSV.\n\nGet GPS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetGpsEphBoolParamForEachSV);


    GetGpsEphBoolParamForEachSV::GetGpsEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetGpsEphBoolParamForEachSV::GetGpsEphBoolParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
    }


    GetGpsEphBoolParamForEachSVPtr GetGpsEphBoolParamForEachSV::create(const std::string& paramName)
    {
      return GetGpsEphBoolParamForEachSVPtr(new GetGpsEphBoolParamForEachSV(paramName));
    }

    GetGpsEphBoolParamForEachSVPtr GetGpsEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphBoolParamForEachSV>(ptr);
    }

    bool GetGpsEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGpsEphBoolParamForEachSV::documentation() const { return Documentation; }


    int GetGpsEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
