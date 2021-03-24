#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasEphemerisParamResult
///
#include "gen/GetSbasEphemerisParamResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasEphemerisParamResult::CmdName = "GetSbasEphemerisParamResult";
    const char* const GetSbasEphemerisParamResult::Documentation = "Result of GetSbasEphemerisParam.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSbasEphemerisParamResult);


    GetSbasEphemerisParamResult::GetSbasEphemerisParamResult()
      : CommandResult(CmdName)
    {}

    GetSbasEphemerisParamResult::GetSbasEphemerisParamResult(CommandBasePtr relatedCommand, int prn, const std::string& parameter, const std::string& valueParam)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setParameter(parameter);
      setValueParam(valueParam);
    }


    GetSbasEphemerisParamResultPtr GetSbasEphemerisParamResult::create(CommandBasePtr relatedCommand, int prn, const std::string& parameter, const std::string& valueParam)
    {
      return GetSbasEphemerisParamResultPtr(new GetSbasEphemerisParamResult(relatedCommand, prn, parameter, valueParam));
    }

    GetSbasEphemerisParamResultPtr GetSbasEphemerisParamResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasEphemerisParamResult>(ptr);
    }

    bool GetSbasEphemerisParamResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Parameter"])
          && parse_json<std::string>::is_valid(m_values["ValueParam"])
        ;

    }

    std::string GetSbasEphemerisParamResult::documentation() const { return Documentation; }


    int GetSbasEphemerisParamResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSbasEphemerisParamResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSbasEphemerisParamResult::parameter() const
    {
      return parse_json<std::string>::parse(m_values["Parameter"]);
    }

    void GetSbasEphemerisParamResult::setParameter(const std::string& parameter)
    {
      m_values.AddMember("Parameter", parse_json<std::string>::format(parameter, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSbasEphemerisParamResult::valueParam() const
    {
      return parse_json<std::string>::parse(m_values["ValueParam"]);
    }

    void GetSbasEphemerisParamResult::setValueParam(const std::string& valueParam)
    {
      m_values.AddMember("ValueParam", parse_json<std::string>::format(valueParam, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
