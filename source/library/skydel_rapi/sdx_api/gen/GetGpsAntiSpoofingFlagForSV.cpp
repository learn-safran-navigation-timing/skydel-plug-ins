#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsAntiSpoofingFlagForSV
///
#include "gen/GetGpsAntiSpoofingFlagForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsAntiSpoofingFlagForSV::CmdName = "GetGpsAntiSpoofingFlagForSV";
    const char* const GetGpsAntiSpoofingFlagForSV::Documentation = "Get GPS Anti-Spoofing Flag";

    REGISTER_COMMAND_FACTORY(GetGpsAntiSpoofingFlagForSV);


    GetGpsAntiSpoofingFlagForSV::GetGpsAntiSpoofingFlagForSV()
      : CommandBase(CmdName)
    {}

    GetGpsAntiSpoofingFlagForSV::GetGpsAntiSpoofingFlagForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsAntiSpoofingFlagForSVPtr GetGpsAntiSpoofingFlagForSV::create(int svId)
    {
      return GetGpsAntiSpoofingFlagForSVPtr(new GetGpsAntiSpoofingFlagForSV(svId));
    }

    GetGpsAntiSpoofingFlagForSVPtr GetGpsAntiSpoofingFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsAntiSpoofingFlagForSV>(ptr);
    }

    bool GetGpsAntiSpoofingFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsAntiSpoofingFlagForSV::documentation() const { return Documentation; }


    int GetGpsAntiSpoofingFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsAntiSpoofingFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsAntiSpoofingFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
