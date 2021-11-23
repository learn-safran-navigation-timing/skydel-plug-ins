#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePseudorangeNoiseSineWaveResult
///
#include "gen/GetSatellitePseudorangeNoiseSineWaveResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePseudorangeNoiseSineWaveResult::CmdName = "GetSatellitePseudorangeNoiseSineWaveResult";
    const char* const GetSatellitePseudorangeNoiseSineWaveResult::Documentation = "Result of GetSatellitePseudorangeNoiseSineWave.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSatellitePseudorangeNoiseSineWaveResult);


    GetSatellitePseudorangeNoiseSineWaveResult::GetSatellitePseudorangeNoiseSineWaveResult()
      : CommandResult(CmdName)
    {}

    GetSatellitePseudorangeNoiseSineWaveResult::GetSatellitePseudorangeNoiseSineWaveResult(CommandBasePtr relatedCommand, const std::string& system, int prn, int sineWave, bool enabled, double amplitude, int period, double offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }


    GetSatellitePseudorangeNoiseSineWaveResultPtr GetSatellitePseudorangeNoiseSineWaveResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, int sineWave, bool enabled, double amplitude, int period, double offset)
    {
      return GetSatellitePseudorangeNoiseSineWaveResultPtr(new GetSatellitePseudorangeNoiseSineWaveResult(relatedCommand, system, prn, sineWave, enabled, amplitude, period, offset));
    }

    GetSatellitePseudorangeNoiseSineWaveResultPtr GetSatellitePseudorangeNoiseSineWaveResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePseudorangeNoiseSineWaveResult>(ptr);
    }

    bool GetSatellitePseudorangeNoiseSineWaveResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["SineWave"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Amplitude"])
          && parse_json<int>::is_valid(m_values["Period"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetSatellitePseudorangeNoiseSineWaveResult::documentation() const { return Documentation; }


    std::string GetSatellitePseudorangeNoiseSineWaveResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatellitePseudorangeNoiseSineWaveResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseSineWaveResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatellitePseudorangeNoiseSineWaveResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseSineWaveResult::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void GetSatellitePseudorangeNoiseSineWaveResult::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetSatellitePseudorangeNoiseSineWaveResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetSatellitePseudorangeNoiseSineWaveResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePseudorangeNoiseSineWaveResult::amplitude() const
    {
      return parse_json<double>::parse(m_values["Amplitude"]);
    }

    void GetSatellitePseudorangeNoiseSineWaveResult::setAmplitude(double amplitude)
    {
      m_values.AddMember("Amplitude", parse_json<double>::format(amplitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseSineWaveResult::period() const
    {
      return parse_json<int>::parse(m_values["Period"]);
    }

    void GetSatellitePseudorangeNoiseSineWaveResult::setPeriod(int period)
    {
      m_values.AddMember("Period", parse_json<int>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePseudorangeNoiseSineWaveResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetSatellitePseudorangeNoiseSineWaveResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
