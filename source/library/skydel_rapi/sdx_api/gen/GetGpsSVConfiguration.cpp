#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSVConfiguration
///
#include "gen/GetGpsSVConfiguration.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSVConfiguration::CmdName = "GetGpsSVConfiguration";
    const char* const GetGpsSVConfiguration::Documentation = "Please note the command GetGpsSVConfiguration is deprecated since 21.3. You may use GetGpsConfigurationCodeForSV.\n\nGet GPS SV configuration flag for one PRN";

    REGISTER_COMMAND_FACTORY(GetGpsSVConfiguration);


    GetGpsSVConfiguration::GetGpsSVConfiguration()
      : CommandBase(CmdName)
    {}

    GetGpsSVConfiguration::GetGpsSVConfiguration(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSVConfigurationPtr GetGpsSVConfiguration::create(int prn)
    {
      return GetGpsSVConfigurationPtr(new GetGpsSVConfiguration(prn));
    }

    GetGpsSVConfigurationPtr GetGpsSVConfiguration::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSVConfiguration>(ptr);
    }

    bool GetGpsSVConfiguration::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSVConfiguration::documentation() const { return Documentation; }


    int GetGpsSVConfiguration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSVConfiguration::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSVConfiguration::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
