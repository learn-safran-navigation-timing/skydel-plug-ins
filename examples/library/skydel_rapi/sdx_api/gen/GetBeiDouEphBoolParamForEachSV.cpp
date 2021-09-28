#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphBoolParamForEachSV
///
#include "gen/GetBeiDouEphBoolParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphBoolParamForEachSV::CmdName = "GetBeiDouEphBoolParamForEachSV";
    const char* const GetBeiDouEphBoolParamForEachSV::Documentation = "Please note the command GetBeiDouEphemerisBoolParams is deprecated since 21.3. You may use GetBeiDouEphBoolParamForEachSV.\n\nGet BeiDou ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphBoolParamForEachSV);


    GetBeiDouEphBoolParamForEachSV::GetBeiDouEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphBoolParamForEachSV::GetBeiDouEphBoolParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
    }


    GetBeiDouEphBoolParamForEachSVPtr GetBeiDouEphBoolParamForEachSV::create(const std::string& paramName)
    {
      return GetBeiDouEphBoolParamForEachSVPtr(new GetBeiDouEphBoolParamForEachSV(paramName));
    }

    GetBeiDouEphBoolParamForEachSVPtr GetBeiDouEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphBoolParamForEachSV>(ptr);
    }

    bool GetBeiDouEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetBeiDouEphBoolParamForEachSV::documentation() const { return Documentation; }


    int GetBeiDouEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
