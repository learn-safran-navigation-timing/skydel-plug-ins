#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasEphemerisParam
///
#include "gen/GetSbasEphemerisParam.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasEphemerisParam::CmdName = "GetSbasEphemerisParam";
    const char* const GetSbasEphemerisParam::Documentation = "Please note the command GetSbasEphemerisParam is deprecated since 21.3. You may use GetSbasEphParamsForSV.\n\nGet parameters for a SBAS satellite ephemeris";

    REGISTER_COMMAND_FACTORY(GetSbasEphemerisParam);


    GetSbasEphemerisParam::GetSbasEphemerisParam()
      : CommandBase(CmdName)
    {}

    GetSbasEphemerisParam::GetSbasEphemerisParam(int prn, const std::string& parameter)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParameter(parameter);
    }


    GetSbasEphemerisParamPtr GetSbasEphemerisParam::create(int prn, const std::string& parameter)
    {
      return GetSbasEphemerisParamPtr(new GetSbasEphemerisParam(prn, parameter));
    }

    GetSbasEphemerisParamPtr GetSbasEphemerisParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasEphemerisParam>(ptr);
    }

    bool GetSbasEphemerisParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Parameter"])
        ;

    }

    std::string GetSbasEphemerisParam::documentation() const { return Documentation; }


    int GetSbasEphemerisParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetSbasEphemerisParam::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSbasEphemerisParam::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSbasEphemerisParam::parameter() const
    {
      return parse_json<std::string>::parse(m_values["Parameter"]);
    }

    void GetSbasEphemerisParam::setParameter(const std::string& parameter)
    {
      m_values.AddMember("Parameter", parse_json<std::string>::format(parameter, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
