#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphDoubleParamForSV
///
#include "gen/GetQzssEphDoubleParamForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphDoubleParamForSV::CmdName = "GetQzssEphDoubleParamForSV";
    const char* const GetQzssEphDoubleParamForSV::Documentation = "Please note the command GetQzssEphemerisDoubleParam is deprecated since 21.3. You may use GetQzssEphDoubleParamForSV.\n\nGet various parameters in the QZSS ephemeris.";

    REGISTER_COMMAND_FACTORY(GetQzssEphDoubleParamForSV);


    GetQzssEphDoubleParamForSV::GetQzssEphDoubleParamForSV()
      : CommandBase(CmdName)
    {}

    GetQzssEphDoubleParamForSV::GetQzssEphDoubleParamForSV(int svId, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
    }


    GetQzssEphDoubleParamForSVPtr GetQzssEphDoubleParamForSV::create(int svId, const std::string& paramName)
    {
      return GetQzssEphDoubleParamForSVPtr(new GetQzssEphDoubleParamForSV(svId, paramName));
    }

    GetQzssEphDoubleParamForSVPtr GetQzssEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphDoubleParamForSV>(ptr);
    }

    bool GetQzssEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetQzssEphDoubleParamForSV::documentation() const { return Documentation; }


    int GetQzssEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
