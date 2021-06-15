#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphemerisDoubleParam
///
#include "gen/SetBeiDouEphemerisDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphemerisDoubleParam::CmdName = "SetBeiDouEphemerisDoubleParam";
    const char* const SetBeiDouEphemerisDoubleParam::Documentation = "Please note the command SetBeiDouEphemerisDoubleParam is deprecated since 21.3. You may use SetBeiDouEphDoubleParamForSV.\n\nSet various parameters in the BeiDou ephemeris\n\n  ParamName         Unit\n  \"ClockBias\"       sec\n  \"ClockDrift\"      sec/sec\n  \"ClockDriftRate\"  sec/sec^2\n  \"Crs\"             meter\n  \"Crc\"             meter\n  \"Cis\"             rad\n  \"Cic\"             rad\n  \"Cus\"             rad\n  \"Cuc\"             rad\n  \"DeltaN\"          rad/sec\n  \"M0\"              rad\n  \"Eccentricity\"    -\n  \"SqrtA\"           sqrt(meter)\n  \"BigOmega\"        rad\n  \"I0\"              rad\n  \"LittleOmega\"     rad\n  \"BigOmegaDot\"     rad/sec\n  \"Idot\"            rad/sec\n  \"Accuracy\"        meter\n  \"Adot\"            meters/sec\n  \"DeltaN0dot\"      rad/sec^2\n  \"Tgd1\"            sec\n  \"Tgd2\"            sec\n  \"TgdB1Cp\"         sec\n  \"TgdB2Ap\"         sec";

    REGISTER_COMMAND_FACTORY(SetBeiDouEphemerisDoubleParam);


    SetBeiDouEphemerisDoubleParam::SetBeiDouEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    SetBeiDouEphemerisDoubleParam::SetBeiDouEphemerisDoubleParam(int prn, const std::string& paramName, double val)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    SetBeiDouEphemerisDoubleParamPtr SetBeiDouEphemerisDoubleParam::create(int prn, const std::string& paramName, double val)
    {
      return SetBeiDouEphemerisDoubleParamPtr(new SetBeiDouEphemerisDoubleParam(prn, paramName, val));
    }

    SetBeiDouEphemerisDoubleParamPtr SetBeiDouEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphemerisDoubleParam>(ptr);
    }

    bool SetBeiDouEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetBeiDouEphemerisDoubleParam::documentation() const { return Documentation; }


    int SetBeiDouEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetBeiDouEphemerisDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouEphemerisDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetBeiDouEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouEphemerisDoubleParam::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetBeiDouEphemerisDoubleParam::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
