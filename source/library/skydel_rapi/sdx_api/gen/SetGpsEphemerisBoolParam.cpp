#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphemerisBoolParam
///
#include "gen/SetGpsEphemerisBoolParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphemerisBoolParam::CmdName = "SetGpsEphemerisBoolParam";
    const char* const SetGpsEphemerisBoolParam::Documentation = "Please note the command SetGpsEphemerisBoolParam is deprecated since 21.3. You may use SetGpsEphBoolParamForSV.\n\nSet various boolean parameters in the GPS ephemeris\n\n  ParamName\n\"IscL1CaAvailable\"\n\"IscL2CAvailable\"\n\"IscL5I5Available\"\n\"IscL5Q5Available\"\n\"IscL1CPAvailable\"\n\"IscL1CDAvailable\"";

    REGISTER_COMMAND_FACTORY(SetGpsEphemerisBoolParam);


    SetGpsEphemerisBoolParam::SetGpsEphemerisBoolParam()
      : CommandBase(CmdName)
    {}

    SetGpsEphemerisBoolParam::SetGpsEphemerisBoolParam(int prn, const std::string& paramName, bool val)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParamName(paramName);
      setVal(val);
    }


    SetGpsEphemerisBoolParamPtr SetGpsEphemerisBoolParam::create(int prn, const std::string& paramName, bool val)
    {
      return SetGpsEphemerisBoolParamPtr(new SetGpsEphemerisBoolParam(prn, paramName, val));
    }

    SetGpsEphemerisBoolParamPtr SetGpsEphemerisBoolParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphemerisBoolParam>(ptr);
    }

    bool SetGpsEphemerisBoolParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGpsEphemerisBoolParam::documentation() const { return Documentation; }


    int SetGpsEphemerisBoolParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsEphemerisBoolParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsEphemerisBoolParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGpsEphemerisBoolParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphemerisBoolParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsEphemerisBoolParam::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void SetGpsEphemerisBoolParam::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
