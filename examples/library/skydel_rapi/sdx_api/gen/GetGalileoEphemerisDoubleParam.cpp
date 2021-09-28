#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphemerisDoubleParam
///
#include "gen/GetGalileoEphemerisDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphemerisDoubleParam::CmdName = "GetGalileoEphemerisDoubleParam";
    const char* const GetGalileoEphemerisDoubleParam::Documentation = "Please note the command GetGalileoEphemerisDoubleParam is deprecated since 21.3. You may use GetGalileoEphDoubleParamForSV.\n\nGet various parameters in the Galileo ephemeris\n\n  ParamName         Unit\n  \"ClockBias\"       sec\n  \"ClockDrift\"      sec/sec\n  \"ClockDriftRate\"  sec/sec^2\n  \"Crs\"             meter\n  \"Crc\"             meter\n  \"Cis\"             rad\n  \"Cic\"             rad\n  \"Cus\"             rad\n  \"Cuc\"             rad\n  \"DeltaN\"          rad/sec\n  \"M0\"              rad\n  \"Eccentricity\"    -\n  \"SqrtA\"           sqrt(meter)\n  \"BigOmega\"        rad\n  \"I0\"              rad\n  \"LittleOmega\"     rad\n  \"BigOmegaDot\"     rad/sec\n  \"Idot\"            rad/sec\n  \"Accuracy\"        meter\n  \"Adot\"            meters/sec\n  \"DeltaN0dot\"      rad/sec^2\n  \"Tgd\"             sec\n  \"BgdE1E5a\"        ns\n  \"BgdE1E5b\"        ns";

    REGISTER_COMMAND_FACTORY(GetGalileoEphemerisDoubleParam);


    GetGalileoEphemerisDoubleParam::GetGalileoEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    GetGalileoEphemerisDoubleParam::GetGalileoEphemerisDoubleParam(int prn, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
    }


    GetGalileoEphemerisDoubleParamPtr GetGalileoEphemerisDoubleParam::create(int prn, const std::string& paramName)
    {
      return GetGalileoEphemerisDoubleParamPtr(new GetGalileoEphemerisDoubleParam(prn, paramName));
    }

    GetGalileoEphemerisDoubleParamPtr GetGalileoEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphemerisDoubleParam>(ptr);
    }

    bool GetGalileoEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGalileoEphemerisDoubleParam::documentation() const { return Documentation; }


    int GetGalileoEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoEphemerisDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoEphemerisDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
