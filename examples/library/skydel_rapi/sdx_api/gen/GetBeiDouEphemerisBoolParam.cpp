#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisBoolParam
///
#include "gen/GetBeiDouEphemerisBoolParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisBoolParam::CmdName = "GetBeiDouEphemerisBoolParam";
    const char* const GetBeiDouEphemerisBoolParam::Documentation = "Please note the command GetBeiDouEphemerisBoolParam is deprecated since 21.3. You may use GetBeiDouEphBoolParamForSV.\n\nGet various boolean parameters in the BeiDou ephemeris\n\n  ParamName\n\"IscB1CdAvailable\"\n\"IscB2adAvailable\"";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphemerisBoolParam);


    GetBeiDouEphemerisBoolParam::GetBeiDouEphemerisBoolParam()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphemerisBoolParam::GetBeiDouEphemerisBoolParam(int prn, const std::string& paramName)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
    }


    GetBeiDouEphemerisBoolParamPtr GetBeiDouEphemerisBoolParam::create(int prn, const std::string& paramName)
    {
      return GetBeiDouEphemerisBoolParamPtr(new GetBeiDouEphemerisBoolParam(prn, paramName));
    }

    GetBeiDouEphemerisBoolParamPtr GetBeiDouEphemerisBoolParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisBoolParam>(ptr);
    }

    bool GetBeiDouEphemerisBoolParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetBeiDouEphemerisBoolParam::documentation() const { return Documentation; }


    int GetBeiDouEphemerisBoolParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouEphemerisBoolParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouEphemerisBoolParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphemerisBoolParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphemerisBoolParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
