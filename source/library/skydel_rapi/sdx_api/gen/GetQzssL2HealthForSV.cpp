#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL2HealthForSV
///
#include "gen/GetQzssL2HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL2HealthForSV::CmdName = "GetQzssL2HealthForSV";
    const char* const GetQzssL2HealthForSV::Documentation = "Please note the command GetQzssSatelliteL2Health is deprecated since 21.3. You may use GetQzssL2HealthForSV.\n\nGet QZSS L2 health (Health of L2C signal)";

    REGISTER_COMMAND_FACTORY(GetQzssL2HealthForSV);


    GetQzssL2HealthForSV::GetQzssL2HealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL2HealthForSV::GetQzssL2HealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssL2HealthForSVPtr GetQzssL2HealthForSV::create(int svId)
    {
      return GetQzssL2HealthForSVPtr(new GetQzssL2HealthForSV(svId));
    }

    GetQzssL2HealthForSVPtr GetQzssL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL2HealthForSV>(ptr);
    }

    bool GetQzssL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssL2HealthForSV::documentation() const { return Documentation; }


    int GetQzssL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
