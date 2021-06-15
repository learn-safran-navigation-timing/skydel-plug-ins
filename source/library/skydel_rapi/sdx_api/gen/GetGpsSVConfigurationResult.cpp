#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSVConfigurationResult
///
#include "gen/GetGpsSVConfigurationResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSVConfigurationResult::CmdName = "GetGpsSVConfigurationResult";
    const char* const GetGpsSVConfigurationResult::Documentation = "Result of GetGpsSVConfiguration.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSVConfigurationResult);


    GetGpsSVConfigurationResult::GetGpsSVConfigurationResult()
      : CommandResult(CmdName)
    {}

    GetGpsSVConfigurationResult::GetGpsSVConfigurationResult(CommandBasePtr relatedCommand, int prn, int svConfig)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setSvConfig(svConfig);
    }


    GetGpsSVConfigurationResultPtr GetGpsSVConfigurationResult::create(CommandBasePtr relatedCommand, int prn, int svConfig)
    {
      return GetGpsSVConfigurationResultPtr(new GetGpsSVConfigurationResult(relatedCommand, prn, svConfig));
    }

    GetGpsSVConfigurationResultPtr GetGpsSVConfigurationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSVConfigurationResult>(ptr);
    }

    bool GetGpsSVConfigurationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["SvConfig"])
        ;

    }

    std::string GetGpsSVConfigurationResult::documentation() const { return Documentation; }


    int GetGpsSVConfigurationResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSVConfigurationResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsSVConfigurationResult::svConfig() const
    {
      return parse_json<int>::parse(m_values["SvConfig"]);
    }

    void GetGpsSVConfigurationResult::setSvConfig(int svConfig)
    {
      m_values.AddMember("SvConfig", parse_json<int>::format(svConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
