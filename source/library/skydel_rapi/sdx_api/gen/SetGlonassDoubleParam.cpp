#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassDoubleParam
///
#include "gen/SetGlonassDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassDoubleParam::CmdName = "SetGlonassDoubleParam";
    const char* const SetGlonassDoubleParam::Documentation = "Please note the command SetGlonassDoubleParam is deprecated since 21.3. You may use SetGlonassEphDoubleParamForSV.\n\nSet various parameters for GLONASS\n\n  ParamName       Unit               Range          Description\n  \"TauC\"          sec                +/- 1          GLONASS time scale correction to UTC(SU) time\n  \"TauGps\"        day                +/- 1.9x10^-3  Correction to GPS time relative to GLONASS time\n  \"TauN\"          sec                +/- 1.9x10^-3  Coarse value of satellite time correction to GLONASS time\n  \"TLambda\"       sec                0..44100       Time of the first ascending node passage\n  \"Lambda\"        semicircle         +/- 1          Longitude of the first ascending node\n  \"DeltaI\"        semicircle         +/- 0.067      Correction to the mean value of inclination\n  \"Omega\"         semicircle         +/- 1          Argument of perigee\n  \"Eccentricity\"  -                  0..0.03        Eccentricity\n  \"DeltaT\"        sec/orb. period    +/- 3.6x10^3   Correction to the mean value of Draconian period\n  \"DeltaTRate\"    sec/orb. period^2  +/- 2^-8       Rate of change of Draconian period";

    REGISTER_COMMAND_FACTORY(SetGlonassDoubleParam);


    SetGlonassDoubleParam::SetGlonassDoubleParam()
      : CommandBase(CmdName)
    {}

    SetGlonassDoubleParam::SetGlonassDoubleParam(int prn, const std::string& paramName, double val)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    SetGlonassDoubleParamPtr SetGlonassDoubleParam::create(int prn, const std::string& paramName, double val)
    {
      return SetGlonassDoubleParamPtr(new SetGlonassDoubleParam(prn, paramName, val));
    }

    SetGlonassDoubleParamPtr SetGlonassDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlonassDoubleParam>(ptr);
    }

    bool SetGlonassDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGlonassDoubleParam::documentation() const { return Documentation; }


    int SetGlonassDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGlonassDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGlonassDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGlonassDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGlonassDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGlonassDoubleParam::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetGlonassDoubleParam::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
