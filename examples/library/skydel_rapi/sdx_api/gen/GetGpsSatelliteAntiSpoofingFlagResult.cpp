#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteAntiSpoofingFlagResult
///
#include "gen/GetGpsSatelliteAntiSpoofingFlagResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteAntiSpoofingFlagResult::CmdName = "GetGpsSatelliteAntiSpoofingFlagResult";
    const char* const GetGpsSatelliteAntiSpoofingFlagResult::Documentation = "Result of GetGpsSatelliteAntiSpoofingFlag.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSatelliteAntiSpoofingFlagResult);


    GetGpsSatelliteAntiSpoofingFlagResult::GetGpsSatelliteAntiSpoofingFlagResult()
      : CommandResult(CmdName)
    {}

    GetGpsSatelliteAntiSpoofingFlagResult::GetGpsSatelliteAntiSpoofingFlagResult(CommandBasePtr relatedCommand, int prn, const Sdx::GpsASFlag& antiSpoofing)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setAntiSpoofing(antiSpoofing);
    }


    GetGpsSatelliteAntiSpoofingFlagResultPtr GetGpsSatelliteAntiSpoofingFlagResult::create(CommandBasePtr relatedCommand, int prn, const Sdx::GpsASFlag& antiSpoofing)
    {
      return GetGpsSatelliteAntiSpoofingFlagResultPtr(new GetGpsSatelliteAntiSpoofingFlagResult(relatedCommand, prn, antiSpoofing));
    }

    GetGpsSatelliteAntiSpoofingFlagResultPtr GetGpsSatelliteAntiSpoofingFlagResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteAntiSpoofingFlagResult>(ptr);
    }

    bool GetGpsSatelliteAntiSpoofingFlagResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::GpsASFlag>::is_valid(m_values["AntiSpoofing"])
        ;

    }

    std::string GetGpsSatelliteAntiSpoofingFlagResult::documentation() const { return Documentation; }


    int GetGpsSatelliteAntiSpoofingFlagResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteAntiSpoofingFlagResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GpsASFlag GetGpsSatelliteAntiSpoofingFlagResult::antiSpoofing() const
    {
      return parse_json<Sdx::GpsASFlag>::parse(m_values["AntiSpoofing"]);
    }

    void GetGpsSatelliteAntiSpoofingFlagResult::setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing)
    {
      m_values.AddMember("AntiSpoofing", parse_json<Sdx::GpsASFlag>::format(antiSpoofing, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
