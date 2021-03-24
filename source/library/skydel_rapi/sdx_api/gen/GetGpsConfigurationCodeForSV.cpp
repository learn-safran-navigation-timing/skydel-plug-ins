#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationCodeForSV
///
#include "gen/GetGpsConfigurationCodeForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationCodeForSV::CmdName = "GetGpsConfigurationCodeForSV";
    const char* const GetGpsConfigurationCodeForSV::Documentation = "Get GPS SV configuration flag for one satellite";

    REGISTER_COMMAND_FACTORY(GetGpsConfigurationCodeForSV);


    GetGpsConfigurationCodeForSV::GetGpsConfigurationCodeForSV()
      : CommandBase(CmdName)
    {}

    GetGpsConfigurationCodeForSV::GetGpsConfigurationCodeForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsConfigurationCodeForSVPtr GetGpsConfigurationCodeForSV::create(int svId)
    {
      return GetGpsConfigurationCodeForSVPtr(new GetGpsConfigurationCodeForSV(svId));
    }

    GetGpsConfigurationCodeForSVPtr GetGpsConfigurationCodeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationCodeForSV>(ptr);
    }

    bool GetGpsConfigurationCodeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsConfigurationCodeForSV::documentation() const { return Documentation; }


    int GetGpsConfigurationCodeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsConfigurationCodeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsConfigurationCodeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
