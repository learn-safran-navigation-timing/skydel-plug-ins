#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL2HealthForSV
///
#include "gen/GetGpsL2HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL2HealthForSV::CmdName = "GetGpsL2HealthForSV";
    const char* const GetGpsL2HealthForSV::Documentation = "Get GPS L2 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsL2HealthForSV);


    GetGpsL2HealthForSV::GetGpsL2HealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsL2HealthForSV::GetGpsL2HealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsL2HealthForSVPtr GetGpsL2HealthForSV::create(int svId)
    {
      return GetGpsL2HealthForSVPtr(new GetGpsL2HealthForSV(svId));
    }

    GetGpsL2HealthForSVPtr GetGpsL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL2HealthForSV>(ptr);
    }

    bool GetGpsL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsL2HealthForSV::documentation() const { return Documentation; }


    int GetGpsL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
