#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisDoubleParam
///
#include "gen/GetGpsEphemerisDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisDoubleParam::CmdName = "GetGpsEphemerisDoubleParam";
    const char* const GetGpsEphemerisDoubleParam::Documentation = "Please note the command GetGpsEphemerisDoubleParam is deprecated since 21.3. You may use GetGpsEphDoubleParamForSV.\n\nGet various parameters in the GPS ephemeris\n\n  ParamName         Unit\n  \"ClockBias\"       sec\n  \"ClockDrift\"      sec/sec\n  \"ClockDriftRate\"  sec/sec^2\n  \"Crs\"             meter\n  \"Crc\"             meter\n  \"Cis\"             rad\n  \"Cic\"             rad\n  \"Cus\"             rad\n  \"Cuc\"             rad\n  \"DeltaN\"          rad/sec\n  \"M0\"              rad\n  \"Eccentricity\"    -\n  \"SqrtA\"           sqrt(meter)\n  \"BigOmega\"        rad\n  \"I0\"              rad\n  \"LittleOmega\"     rad\n  \"BigOmegaDot\"     rad/sec\n  \"Idot\"            rad/sec\n  \"Accuracy\"        meter\n  \"Adot\"            meters/sec\n  \"DeltaN0dot\"      rad/sec^2\n  \"Tgd\"             sec\n  \"IscL1Ca\"         sec\n  \"IscL2C\"          sec\n  \"IscL5I5\"         sec\n  \"IscL5Q5\"         sec\n  \"IscL1CP\"         sec\n  \"IscL1CD\"         sec";

    REGISTER_COMMAND_FACTORY(GetGpsEphemerisDoubleParam);


    GetGpsEphemerisDoubleParam::GetGpsEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    GetGpsEphemerisDoubleParam::GetGpsEphemerisDoubleParam(int prn, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
    }


    GetGpsEphemerisDoubleParamPtr GetGpsEphemerisDoubleParam::create(int prn, const std::string& paramName)
    {
      return GetGpsEphemerisDoubleParamPtr(new GetGpsEphemerisDoubleParam(prn, paramName));
    }

    GetGpsEphemerisDoubleParamPtr GetGpsEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisDoubleParam>(ptr);
    }

    bool GetGpsEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGpsEphemerisDoubleParam::documentation() const { return Documentation; }


    int GetGpsEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsEphemerisDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsEphemerisDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
