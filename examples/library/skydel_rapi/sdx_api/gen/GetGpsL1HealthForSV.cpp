#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL1HealthForSV
///
#include "gen/GetGpsL1HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL1HealthForSV::CmdName = "GetGpsL1HealthForSV";
    const char* const GetGpsL1HealthForSV::Documentation = "Get GPS L1 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsL1HealthForSV);


    GetGpsL1HealthForSV::GetGpsL1HealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsL1HealthForSV::GetGpsL1HealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsL1HealthForSVPtr GetGpsL1HealthForSV::create(int svId)
    {
      return GetGpsL1HealthForSVPtr(new GetGpsL1HealthForSV(svId));
    }

    GetGpsL1HealthForSVPtr GetGpsL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL1HealthForSV>(ptr);
    }

    bool GetGpsL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsL1HealthForSV::documentation() const { return Documentation; }


    int GetGpsL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
