#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePseudorangeNoiseOffsetResult
///
#include "gen/GetSatellitePseudorangeNoiseOffsetResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePseudorangeNoiseOffsetResult::CmdName = "GetSatellitePseudorangeNoiseOffsetResult";
    const char* const GetSatellitePseudorangeNoiseOffsetResult::Documentation = "Result of GetSatellitePseudorangeNoiseOffset.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSatellitePseudorangeNoiseOffsetResult);


    GetSatellitePseudorangeNoiseOffsetResult::GetSatellitePseudorangeNoiseOffsetResult()
      : CommandResult(CmdName)
    {}

    GetSatellitePseudorangeNoiseOffsetResult::GetSatellitePseudorangeNoiseOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled, double offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setEnabled(enabled);
      setOffset(offset);
    }


    GetSatellitePseudorangeNoiseOffsetResultPtr GetSatellitePseudorangeNoiseOffsetResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled, double offset)
    {
      return GetSatellitePseudorangeNoiseOffsetResultPtr(new GetSatellitePseudorangeNoiseOffsetResult(relatedCommand, system, prn, enabled, offset));
    }

    GetSatellitePseudorangeNoiseOffsetResultPtr GetSatellitePseudorangeNoiseOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePseudorangeNoiseOffsetResult>(ptr);
    }

    bool GetSatellitePseudorangeNoiseOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetSatellitePseudorangeNoiseOffsetResult::documentation() const { return Documentation; }


    std::string GetSatellitePseudorangeNoiseOffsetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatellitePseudorangeNoiseOffsetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseOffsetResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatellitePseudorangeNoiseOffsetResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetSatellitePseudorangeNoiseOffsetResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetSatellitePseudorangeNoiseOffsetResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePseudorangeNoiseOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetSatellitePseudorangeNoiseOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
