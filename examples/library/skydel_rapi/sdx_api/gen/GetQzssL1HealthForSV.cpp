#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1HealthForSV
///
#include "gen/GetQzssL1HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1HealthForSV::CmdName = "GetQzssL1HealthForSV";
    const char* const GetQzssL1HealthForSV::Documentation = "Please note the command GetQzssSatelliteL1Health is deprecated since 21.3. You may use GetQzssL1HealthForSV.\n\nGet QZSS L1 health (Health of L1C/A signal)";

    REGISTER_COMMAND_FACTORY(GetQzssL1HealthForSV);


    GetQzssL1HealthForSV::GetQzssL1HealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL1HealthForSV::GetQzssL1HealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssL1HealthForSVPtr GetQzssL1HealthForSV::create(int svId)
    {
      return GetQzssL1HealthForSVPtr(new GetQzssL1HealthForSV(svId));
    }

    GetQzssL1HealthForSVPtr GetQzssL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1HealthForSV>(ptr);
    }

    bool GetQzssL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssL1HealthForSV::documentation() const { return Documentation; }


    int GetQzssL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
