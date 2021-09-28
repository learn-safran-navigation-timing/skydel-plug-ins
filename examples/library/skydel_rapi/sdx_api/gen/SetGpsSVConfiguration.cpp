#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSVConfiguration
///
#include "gen/SetGpsSVConfiguration.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSVConfiguration::CmdName = "SetGpsSVConfiguration";
    const char* const SetGpsSVConfiguration::Documentation = "Please note the command SetGpsSVConfiguration is deprecated since 21.3. You may use SetGpsConfigurationCodeForSV.\n\nSet GPS SV configuration flag for one PRN";

    REGISTER_COMMAND_FACTORY(SetGpsSVConfiguration);


    SetGpsSVConfiguration::SetGpsSVConfiguration()
      : CommandBase(CmdName)
    {}

    SetGpsSVConfiguration::SetGpsSVConfiguration(int prn, int svConfig)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSvConfig(svConfig);
    }


    SetGpsSVConfigurationPtr SetGpsSVConfiguration::create(int prn, int svConfig)
    {
      return SetGpsSVConfigurationPtr(new SetGpsSVConfiguration(prn, svConfig));
    }

    SetGpsSVConfigurationPtr SetGpsSVConfiguration::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSVConfiguration>(ptr);
    }

    bool SetGpsSVConfiguration::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["SvConfig"])
        ;

    }

    std::string SetGpsSVConfiguration::documentation() const { return Documentation; }


    int SetGpsSVConfiguration::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetGpsSVConfiguration::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSVConfiguration::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsSVConfiguration::svConfig() const
    {
      return parse_json<int>::parse(m_values["SvConfig"]);
    }

    void SetGpsSVConfiguration::setSvConfig(int svConfig)
    {
      m_values.AddMember("SvConfig", parse_json<int>::format(svConfig, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
