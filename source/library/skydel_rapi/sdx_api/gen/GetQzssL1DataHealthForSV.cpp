#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1DataHealthForSV
///
#include "gen/GetQzssL1DataHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1DataHealthForSV::CmdName = "GetQzssL1DataHealthForSV";
    const char* const GetQzssL1DataHealthForSV::Documentation = "Please note the command GetQzssSatelliteL1DataHealth is deprecated since 21.3. You may use GetQzssL1DataHealthForSV.\n\nGet QZSS L1 C/A nav data health";

    REGISTER_COMMAND_FACTORY(GetQzssL1DataHealthForSV);


    GetQzssL1DataHealthForSV::GetQzssL1DataHealthForSV()
      : CommandBase(CmdName)
    {}

    GetQzssL1DataHealthForSV::GetQzssL1DataHealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssL1DataHealthForSVPtr GetQzssL1DataHealthForSV::create(int svId)
    {
      return GetQzssL1DataHealthForSVPtr(new GetQzssL1DataHealthForSV(svId));
    }

    GetQzssL1DataHealthForSVPtr GetQzssL1DataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1DataHealthForSV>(ptr);
    }

    bool GetQzssL1DataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssL1DataHealthForSV::documentation() const { return Documentation; }


    int GetQzssL1DataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssL1DataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1DataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
