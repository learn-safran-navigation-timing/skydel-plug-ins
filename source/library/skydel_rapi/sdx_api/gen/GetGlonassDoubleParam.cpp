#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassDoubleParam
///
#include "gen/GetGlonassDoubleParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassDoubleParam::CmdName = "GetGlonassDoubleParam";
    const char* const GetGlonassDoubleParam::Documentation = "Please note the command GetGlonassDoubleParam is deprecated since 21.3. You may use GetGlonassEphDoubleParamForSV.\n\nGet various parameters for GLONASS\n\n  ParamName       Unit               Range          Description\n  \"TauC\"          sec                +/- 1          GLONASS time scale correction to UTC(SU) time\n  \"TauGps\"        day                +/- 1.9x10^-3  Correction to GPS time relative to GLONASS time\n  \"TauN\"          sec                +/- 1.9x10^-3  Coarse value of satellite time correction to GLONASS time\n  \"TLambda\"       sec                0..44100       Time of the first ascending node passage\n  \"Lambda\"        semicircle         +/- 1          Longitude of the first ascending node\n  \"DeltaI\"        semicircle         +/- 0.067      Correction to the mean value of inclination\n  \"Omega\"         semicircle         +/- 1          Argument of perigee\n  \"Eccentricity\"  -                  0..0.03        Eccentricity\n  \"DeltaT\"        sec/orb. period    +/- 3.6x10^3   Correction to the mean value of Draconian period\n  \"DeltaTRate\"    sec/orb. period^2  +/- 2^-8       Rate of change of Draconian period";

    REGISTER_COMMAND_FACTORY(GetGlonassDoubleParam);


    GetGlonassDoubleParam::GetGlonassDoubleParam()
      : CommandBase(CmdName)
    {}

    GetGlonassDoubleParam::GetGlonassDoubleParam(int prn, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
    }


    GetGlonassDoubleParamPtr GetGlonassDoubleParam::create(int prn, const std::string& paramName)
    {
      return GetGlonassDoubleParamPtr(new GetGlonassDoubleParam(prn, paramName));
    }

    GetGlonassDoubleParamPtr GetGlonassDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassDoubleParam>(ptr);
    }

    bool GetGlonassDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGlonassDoubleParam::documentation() const { return Documentation; }


    int GetGlonassDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGlonassDoubleParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassDoubleParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGlonassDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGlonassDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
