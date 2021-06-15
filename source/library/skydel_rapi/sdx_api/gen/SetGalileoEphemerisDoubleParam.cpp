#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoEphemerisDoubleParam
///
#include "gen/SetGalileoEphemerisDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoEphemerisDoubleParam::CmdName = "SetGalileoEphemerisDoubleParam";
    const char* const SetGalileoEphemerisDoubleParam::Documentation = "Please note the command SetGalileoEphemerisDoubleParam is deprecated since 21.3. You may use SetGalileoEphDoubleParamForSV.\n\nSet various parameters in the Galileo ephemeris\n\n  ParamName         Unit\n  \"ClockBias\"       sec\n  \"ClockDrift\"      sec/sec\n  \"ClockDriftRate\"  sec/sec^2\n  \"Crs\"             meter\n  \"Crc\"             meter\n  \"Cis\"             rad\n  \"Cic\"             rad\n  \"Cus\"             rad\n  \"Cuc\"             rad\n  \"DeltaN\"          rad/sec\n  \"M0\"              rad\n  \"Eccentricity\"    -\n  \"SqrtA\"           sqrt(meter)\n  \"BigOmega\"        rad\n  \"I0\"              rad\n  \"LittleOmega\"     rad\n  \"BigOmegaDot\"     rad/sec\n  \"Idot\"            rad/sec\n  \"Accuracy\"        meter\n  \"Adot\"            meters/sec\n  \"DeltaN0dot\"      rad/sec^2\n  \"Tgd\"             sec\n  \"BgdE1E5a\"        ns\n  \"BgdE1E5b\"        ns";

    REGISTER_COMMAND_FACTORY(SetGalileoEphemerisDoubleParam);


    SetGalileoEphemerisDoubleParam::SetGalileoEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    SetGalileoEphemerisDoubleParam::SetGalileoEphemerisDoubleParam(int prn, const std::string& paramName, double val)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    SetGalileoEphemerisDoubleParamPtr SetGalileoEphemerisDoubleParam::create(int prn, const std::string& paramName, double val)
    {
      return SetGalileoEphemerisDoubleParamPtr(new SetGalileoEphemerisDoubleParam(prn, paramName, val));
    }

    SetGalileoEphemerisDoubleParamPtr SetGalileoEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoEphemerisDoubleParam>(ptr);
    }

    bool SetGalileoEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGalileoEphemerisDoubleParam::documentation() const { return Documentation; }


    int SetGalileoEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGalileoEphemerisDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoEphemerisDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGalileoEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGalileoEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGalileoEphemerisDoubleParam::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetGalileoEphemerisDoubleParam::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
