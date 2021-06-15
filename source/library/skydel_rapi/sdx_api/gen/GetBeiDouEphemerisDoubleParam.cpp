#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisDoubleParam
///
#include "gen/GetBeiDouEphemerisDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisDoubleParam::CmdName = "GetBeiDouEphemerisDoubleParam";
    const char* const GetBeiDouEphemerisDoubleParam::Documentation = "Please note the command GetBeiDouEphemerisDoubleParam is deprecated since 21.3. You may use GetBeiDouEphDoubleParamForSV.\n\nGet various parameters in the BeiDou ephemeris\n\n  ParamName         Unit\n  \"ClockBias\"       sec\n  \"ClockDrift\"      sec/sec\n  \"ClockDriftRate\"  sec/sec^2\n  \"Crs\"             meter\n  \"Crc\"             meter\n  \"Cis\"             rad\n  \"Cic\"             rad\n  \"Cus\"             rad\n  \"Cuc\"             rad\n  \"DeltaN\"          rad/sec\n  \"M0\"              rad\n  \"Eccentricity\"    -\n  \"SqrtA\"           sqrt(meter)\n  \"BigOmega\"        rad\n  \"I0\"              rad\n  \"LittleOmega\"     rad\n  \"BigOmegaDot\"     rad/sec\n  \"Idot\"            rad/sec\n  \"Accuracy\"        meter\n  \"Adot\"            meters/sec\n  \"DeltaN0dot\"      rad/sec^2\n  \"Tgd1\"            sec\n  \"Tgd2\"            sec\n  \"TgdB1Cp\"         sec\n  \"TgdB2Ap\"         sec";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphemerisDoubleParam);


    GetBeiDouEphemerisDoubleParam::GetBeiDouEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphemerisDoubleParam::GetBeiDouEphemerisDoubleParam(int prn, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
    }


    GetBeiDouEphemerisDoubleParamPtr GetBeiDouEphemerisDoubleParam::create(int prn, const std::string& paramName)
    {
      return GetBeiDouEphemerisDoubleParamPtr(new GetBeiDouEphemerisDoubleParam(prn, paramName));
    }

    GetBeiDouEphemerisDoubleParamPtr GetBeiDouEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisDoubleParam>(ptr);
    }

    bool GetBeiDouEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetBeiDouEphemerisDoubleParam::documentation() const { return Documentation; }


    int GetBeiDouEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouEphemerisDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouEphemerisDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
