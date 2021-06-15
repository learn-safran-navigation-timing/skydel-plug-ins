#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphemerisDoubleParam
///
#include "gen/SetGpsEphemerisDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphemerisDoubleParam::CmdName = "SetGpsEphemerisDoubleParam";
    const char* const SetGpsEphemerisDoubleParam::Documentation = "Please note the command SetGpsEphemerisDoubleParam is deprecated since 21.3. You may use SetGpsEphDoubleParamForSV.\n\nSet various parameters in the GPS ephemeris\n\n  ParamName         Unit\n  \"ClockBias\"       sec\n  \"ClockDrift\"      sec/sec\n  \"ClockDriftRate\"  sec/sec^2\n  \"Crs\"             meter\n  \"Crc\"             meter\n  \"Cis\"             rad\n  \"Cic\"             rad\n  \"Cus\"             rad\n  \"Cuc\"             rad\n  \"DeltaN\"          rad/sec\n  \"M0\"              rad\n  \"Eccentricity\"    -\n  \"SqrtA\"           sqrt(meter)\n  \"BigOmega\"        rad\n  \"I0\"              rad\n  \"LittleOmega\"     rad\n  \"BigOmegaDot\"     rad/sec\n  \"Idot\"            rad/sec\n  \"Accuracy\"        meter\n  \"Adot\"            meters/sec\n  \"DeltaN0dot\"      rad/sec^2\n  \"Tgd\"             sec\n  \"IscL1Ca\"         sec\n  \"IscL2C\"          sec\n  \"IscL5I5\"         sec\n  \"IscL5Q5\"         sec\n  \"IscL1CP\"         sec\n  \"IscL1CD\"         sec";

    REGISTER_COMMAND_FACTORY(SetGpsEphemerisDoubleParam);


    SetGpsEphemerisDoubleParam::SetGpsEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    SetGpsEphemerisDoubleParam::SetGpsEphemerisDoubleParam(int prn, const std::string& paramName, double val)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    SetGpsEphemerisDoubleParamPtr SetGpsEphemerisDoubleParam::create(int prn, const std::string& paramName, double val)
    {
      return SetGpsEphemerisDoubleParamPtr(new SetGpsEphemerisDoubleParam(prn, paramName, val));
    }

    SetGpsEphemerisDoubleParamPtr SetGpsEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphemerisDoubleParam>(ptr);
    }

    bool SetGpsEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGpsEphemerisDoubleParam::documentation() const { return Documentation; }


    int SetGpsEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsEphemerisDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsEphemerisDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGpsEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsEphemerisDoubleParam::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetGpsEphemerisDoubleParam::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
