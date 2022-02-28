#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeNoiseSineWaveForEachSV
///
#include "gen/SetPseudorangeNoiseSineWaveForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeNoiseSineWaveForEachSV::CmdName = "SetPseudorangeNoiseSineWaveForEachSV";
    const char* const SetPseudorangeNoiseSineWaveForEachSV::Documentation = "Please note the command SetAllSatellitesPseudorangeNoiseSineWave is deprecated since 21.3. You may use SetPseudorangeNoiseSineWaveForEachSV.\n\nSet the satellite pseudorange noise sine wave attributes for all satellites.";

    REGISTER_COMMAND_FACTORY(SetPseudorangeNoiseSineWaveForEachSV);


    SetPseudorangeNoiseSineWaveForEachSV::SetPseudorangeNoiseSineWaveForEachSV()
      : CommandBase(CmdName)
    {}

    SetPseudorangeNoiseSineWaveForEachSV::SetPseudorangeNoiseSineWaveForEachSV(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }


    SetPseudorangeNoiseSineWaveForEachSVPtr SetPseudorangeNoiseSineWaveForEachSV::create(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset)
    {
      return SetPseudorangeNoiseSineWaveForEachSVPtr(new SetPseudorangeNoiseSineWaveForEachSV(system, sineWave, enabled, amplitude, period, offset));
    }

    SetPseudorangeNoiseSineWaveForEachSVPtr SetPseudorangeNoiseSineWaveForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeNoiseSineWaveForEachSV>(ptr);
    }

    bool SetPseudorangeNoiseSineWaveForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SineWave"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
          && parse_json<std::vector<double>>::is_valid(m_values["Amplitude"])
          && parse_json<std::vector<int>>::is_valid(m_values["Period"])
          && parse_json<std::vector<double>>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetPseudorangeNoiseSineWaveForEachSV::documentation() const { return Documentation; }


    int SetPseudorangeNoiseSineWaveForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeNoiseSineWaveForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeNoiseSineWaveForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseSineWaveForEachSV::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void SetPseudorangeNoiseSineWaveForEachSV::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetPseudorangeNoiseSineWaveForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void SetPseudorangeNoiseSineWaveForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPseudorangeNoiseSineWaveForEachSV::amplitude() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Amplitude"]);
    }

    void SetPseudorangeNoiseSineWaveForEachSV::setAmplitude(const std::vector<double>& amplitude)
    {
      m_values.AddMember("Amplitude", parse_json<std::vector<double>>::format(amplitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> SetPseudorangeNoiseSineWaveForEachSV::period() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Period"]);
    }

    void SetPseudorangeNoiseSineWaveForEachSV::setPeriod(const std::vector<int>& period)
    {
      m_values.AddMember("Period", parse_json<std::vector<int>>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetPseudorangeNoiseSineWaveForEachSV::offset() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Offset"]);
    }

    void SetPseudorangeNoiseSineWaveForEachSV::setOffset(const std::vector<double>& offset)
    {
      m_values.AddMember("Offset", parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
