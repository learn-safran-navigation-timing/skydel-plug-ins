#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsAntiSpoofingFlagForSVResult
///
#include "gen/GetGpsAntiSpoofingFlagForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsAntiSpoofingFlagForSVResult::CmdName = "GetGpsAntiSpoofingFlagForSVResult";
    const char* const GetGpsAntiSpoofingFlagForSVResult::Documentation = "Result of GetGpsAntiSpoofingFlagForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsAntiSpoofingFlagForSVResult);


    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsAntiSpoofingFlagForSVResult::GetGpsAntiSpoofingFlagForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setAntiSpoofing(antiSpoofing);
    }


    GetGpsAntiSpoofingFlagForSVResultPtr GetGpsAntiSpoofingFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing)
    {
      return GetGpsAntiSpoofingFlagForSVResultPtr(new GetGpsAntiSpoofingFlagForSVResult(relatedCommand, svId, antiSpoofing));
    }

    GetGpsAntiSpoofingFlagForSVResultPtr GetGpsAntiSpoofingFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsAntiSpoofingFlagForSVResult>(ptr);
    }

    bool GetGpsAntiSpoofingFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::GpsASFlag>::is_valid(m_values["AntiSpoofing"])
        ;

    }

    std::string GetGpsAntiSpoofingFlagForSVResult::documentation() const { return Documentation; }


    int GetGpsAntiSpoofingFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsAntiSpoofingFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GpsASFlag GetGpsAntiSpoofingFlagForSVResult::antiSpoofing() const
    {
      return parse_json<Sdx::GpsASFlag>::parse(m_values["AntiSpoofing"]);
    }

    void GetGpsAntiSpoofingFlagForSVResult::setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing)
    {
      m_values.AddMember("AntiSpoofing", parse_json<Sdx::GpsASFlag>::format(antiSpoofing, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
