#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSatellitePseudorangeNoiseGaussMarkov
///
#include "gen/SetSatellitePseudorangeNoiseGaussMarkov.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSatellitePseudorangeNoiseGaussMarkov::CmdName = "SetSatellitePseudorangeNoiseGaussMarkov";
    const char* const SetSatellitePseudorangeNoiseGaussMarkov::Documentation = "Please note the command SetSatellitePseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use SetPseudorangeNoiseGaussMarkovForSV.\n\nSet the satellite pseudorange noise Gauss-Markov process attributes.";

    REGISTER_COMMAND_FACTORY(SetSatellitePseudorangeNoiseGaussMarkov);


    SetSatellitePseudorangeNoiseGaussMarkov::SetSatellitePseudorangeNoiseGaussMarkov()
      : CommandBase(CmdName)
    {}

    SetSatellitePseudorangeNoiseGaussMarkov::SetSatellitePseudorangeNoiseGaussMarkov(const std::string& system, int prn, int process, bool enabled, double sigma, double time, int seed)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }


    SetSatellitePseudorangeNoiseGaussMarkovPtr SetSatellitePseudorangeNoiseGaussMarkov::create(const std::string& system, int prn, int process, bool enabled, double sigma, double time, int seed)
    {
      return SetSatellitePseudorangeNoiseGaussMarkovPtr(new SetSatellitePseudorangeNoiseGaussMarkov(system, prn, process, enabled, sigma, time, seed));
    }

    SetSatellitePseudorangeNoiseGaussMarkovPtr SetSatellitePseudorangeNoiseGaussMarkov::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSatellitePseudorangeNoiseGaussMarkov>(ptr);
    }

    bool SetSatellitePseudorangeNoiseGaussMarkov::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Process"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Sigma"])
          && parse_json<double>::is_valid(m_values["Time"])
          && parse_json<int>::is_valid(m_values["Seed"])
        ;

    }

    std::string SetSatellitePseudorangeNoiseGaussMarkov::documentation() const { return Documentation; }


    int SetSatellitePseudorangeNoiseGaussMarkov::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSatellitePseudorangeNoiseGaussMarkov::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSatellitePseudorangeNoiseGaussMarkov::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePseudorangeNoiseGaussMarkov::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSatellitePseudorangeNoiseGaussMarkov::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePseudorangeNoiseGaussMarkov::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void SetSatellitePseudorangeNoiseGaussMarkov::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSatellitePseudorangeNoiseGaussMarkov::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetSatellitePseudorangeNoiseGaussMarkov::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatellitePseudorangeNoiseGaussMarkov::sigma() const
    {
      return parse_json<double>::parse(m_values["Sigma"]);
    }

    void SetSatellitePseudorangeNoiseGaussMarkov::setSigma(double sigma)
    {
      m_values.AddMember("Sigma", parse_json<double>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatellitePseudorangeNoiseGaussMarkov::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void SetSatellitePseudorangeNoiseGaussMarkov::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePseudorangeNoiseGaussMarkov::seed() const
    {
      return parse_json<int>::parse(m_values["Seed"]);
    }

    void SetSatellitePseudorangeNoiseGaussMarkov::setSeed(int seed)
    {
      m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
