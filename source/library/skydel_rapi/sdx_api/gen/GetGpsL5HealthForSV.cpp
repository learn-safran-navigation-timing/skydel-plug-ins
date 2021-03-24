#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL5HealthForSV
///
#include "gen/GetGpsL5HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL5HealthForSV::CmdName = "GetGpsL5HealthForSV";
    const char* const GetGpsL5HealthForSV::Documentation = "Get GPS L5 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(GetGpsL5HealthForSV);


    GetGpsL5HealthForSV::GetGpsL5HealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsL5HealthForSV::GetGpsL5HealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsL5HealthForSVPtr GetGpsL5HealthForSV::create(int svId)
    {
      return GetGpsL5HealthForSVPtr(new GetGpsL5HealthForSV(svId));
    }

    GetGpsL5HealthForSVPtr GetGpsL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL5HealthForSV>(ptr);
    }

    bool GetGpsL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsL5HealthForSV::documentation() const { return Documentation; }


    int GetGpsL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
