#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphDoubleParamForSV
///
#include "gen/GetGalileoEphDoubleParamForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphDoubleParamForSV::CmdName = "GetGalileoEphDoubleParamForSV";
    const char* const GetGalileoEphDoubleParamForSV::Documentation = "Get various parameters in the Galileo ephemeris\n\n  ParamName         Unit\n  \"ClockBias\"       sec\n  \"ClockDrift\"      sec/sec\n  \"ClockDriftRate\"  sec/sec^2\n  \"Crs\"             meter\n  \"Crc\"             meter\n  \"Cis\"             rad\n  \"Cic\"             rad\n  \"Cus\"             rad\n  \"Cuc\"             rad\n  \"DeltaN\"          rad/sec\n  \"M0\"              rad\n  \"Eccentricity\"    -\n  \"SqrtA\"           sqrt(meter)\n  \"BigOmega\"        rad\n  \"I0\"              rad\n  \"LittleOmega\"     rad\n  \"BigOmegaDot\"     rad/sec\n  \"Idot\"            rad/sec\n  \"Accuracy\"        meter\n  \"Adot\"            meters/sec\n  \"DeltaN0dot\"      rad/sec^2\n  \"Tgd\"             sec\n  \"BgdE1E5a\"        ns\n  \"BgdE1E5b\"        ns";

    REGISTER_COMMAND_FACTORY(GetGalileoEphDoubleParamForSV);


    GetGalileoEphDoubleParamForSV::GetGalileoEphDoubleParamForSV()
      : CommandBase(CmdName)
    {}

    GetGalileoEphDoubleParamForSV::GetGalileoEphDoubleParamForSV(int svId, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
    }


    GetGalileoEphDoubleParamForSVPtr GetGalileoEphDoubleParamForSV::create(int svId, const std::string& paramName)
    {
      return GetGalileoEphDoubleParamForSVPtr(new GetGalileoEphDoubleParamForSV(svId, paramName));
    }

    GetGalileoEphDoubleParamForSVPtr GetGalileoEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphDoubleParamForSV>(ptr);
    }

    bool GetGalileoEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGalileoEphDoubleParamForSV::documentation() const { return Documentation; }


    int GetGalileoEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGalileoEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
