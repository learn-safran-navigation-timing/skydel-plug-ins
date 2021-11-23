#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisBoolParam
///
#include "gen/GetGpsEphemerisBoolParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisBoolParam::CmdName = "GetGpsEphemerisBoolParam";
    const char* const GetGpsEphemerisBoolParam::Documentation = "Please note the command GetGpsEphemerisBoolParam is deprecated since 21.3. You may use GetGpsEphBoolParamForSV.\n\nGet various boolean parameters in the GPS ephemeris\n\n  ParamName\n\"IscL1CaAvailable\"\n\"IscL2CAvailable\"\n\"IscL5I5Available\"\n\"IscL5Q5Available\"\n\"IscL1CPAvailable\"\n\"IscL1CDAvailable\"";

    REGISTER_COMMAND_FACTORY(GetGpsEphemerisBoolParam);


    GetGpsEphemerisBoolParam::GetGpsEphemerisBoolParam()
      : CommandBase(CmdName)
    {}

    GetGpsEphemerisBoolParam::GetGpsEphemerisBoolParam(int prn, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
    }


    GetGpsEphemerisBoolParamPtr GetGpsEphemerisBoolParam::create(int prn, const std::string& paramName)
    {
      return GetGpsEphemerisBoolParamPtr(new GetGpsEphemerisBoolParam(prn, paramName));
    }

    GetGpsEphemerisBoolParamPtr GetGpsEphemerisBoolParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisBoolParam>(ptr);
    }

    bool GetGpsEphemerisBoolParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGpsEphemerisBoolParam::documentation() const { return Documentation; }


    int GetGpsEphemerisBoolParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsEphemerisBoolParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsEphemerisBoolParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphemerisBoolParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphemerisBoolParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
