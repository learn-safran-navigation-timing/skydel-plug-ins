#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSatellitePseudorangeNoiseSineWave
///
#include "gen/SetSatellitePseudorangeNoiseSineWave.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSatellitePseudorangeNoiseSineWave::CmdName = "SetSatellitePseudorangeNoiseSineWave";
    const char* const SetSatellitePseudorangeNoiseSineWave::Documentation = "Please note the command SetSatellitePseudorangeNoiseSineWave is deprecated since 21.3. You may use SetPseudorangeNoiseSineWaveForSV.\n\nSet the satellite pseudorange noise sine wave attributes.";

    REGISTER_COMMAND_FACTORY(SetSatellitePseudorangeNoiseSineWave);


    SetSatellitePseudorangeNoiseSineWave::SetSatellitePseudorangeNoiseSineWave()
      : CommandBase(CmdName)
    {}

    SetSatellitePseudorangeNoiseSineWave::SetSatellitePseudorangeNoiseSineWave(const std::string& system, int prn, int sineWave, bool enabled, double amplitude, int period, double offset)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setSineWave(sineWave);
      setEnabled(enabled);
      setAmplitude(amplitude);
      setPeriod(period);
      setOffset(offset);
    }


    SetSatellitePseudorangeNoiseSineWavePtr SetSatellitePseudorangeNoiseSineWave::create(const std::string& system, int prn, int sineWave, bool enabled, double amplitude, int period, double offset)
    {
      return SetSatellitePseudorangeNoiseSineWavePtr(new SetSatellitePseudorangeNoiseSineWave(system, prn, sineWave, enabled, amplitude, period, offset));
    }

    SetSatellitePseudorangeNoiseSineWavePtr SetSatellitePseudorangeNoiseSineWave::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSatellitePseudorangeNoiseSineWave>(ptr);
    }

    bool SetSatellitePseudorangeNoiseSineWave::isValid() const
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

    std::string SetSatellitePseudorangeNoiseSineWave::documentation() const { return Documentation; }


    int SetSatellitePseudorangeNoiseSineWave::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSatellitePseudorangeNoiseSineWave::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSatellitePseudorangeNoiseSineWave::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePseudorangeNoiseSineWave::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSatellitePseudorangeNoiseSineWave::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePseudorangeNoiseSineWave::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void SetSatellitePseudorangeNoiseSineWave::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSatellitePseudorangeNoiseSineWave::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetSatellitePseudorangeNoiseSineWave::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatellitePseudorangeNoiseSineWave::amplitude() const
    {
      return parse_json<double>::parse(m_values["Amplitude"]);
    }

    void SetSatellitePseudorangeNoiseSineWave::setAmplitude(double amplitude)
    {
      m_values.AddMember("Amplitude", parse_json<double>::format(amplitude, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePseudorangeNoiseSineWave::period() const
    {
      return parse_json<int>::parse(m_values["Period"]);
    }

    void SetSatellitePseudorangeNoiseSineWave::setPeriod(int period)
    {
      m_values.AddMember("Period", parse_json<int>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatellitePseudorangeNoiseSineWave::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetSatellitePseudorangeNoiseSineWave::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
