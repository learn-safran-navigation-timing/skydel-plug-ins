#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePseudorangeNoiseGaussMarkovResult
///
#include "gen/GetSatellitePseudorangeNoiseGaussMarkovResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePseudorangeNoiseGaussMarkovResult::CmdName = "GetSatellitePseudorangeNoiseGaussMarkovResult";
    const char* const GetSatellitePseudorangeNoiseGaussMarkovResult::Documentation = "Result of GetSatellitePseudorangeNoiseGaussMarkov.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSatellitePseudorangeNoiseGaussMarkovResult);


    GetSatellitePseudorangeNoiseGaussMarkovResult::GetSatellitePseudorangeNoiseGaussMarkovResult()
      : CommandResult(CmdName)
    {}

    GetSatellitePseudorangeNoiseGaussMarkovResult::GetSatellitePseudorangeNoiseGaussMarkovResult(CommandBasePtr relatedCommand, const std::string& system, int prn, int process, bool enabled, double sigma, double time, int seed)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setProcess(process);
      setEnabled(enabled);
      setSigma(sigma);
      setTime(time);
      setSeed(seed);
    }


    GetSatellitePseudorangeNoiseGaussMarkovResultPtr GetSatellitePseudorangeNoiseGaussMarkovResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, int process, bool enabled, double sigma, double time, int seed)
    {
      return GetSatellitePseudorangeNoiseGaussMarkovResultPtr(new GetSatellitePseudorangeNoiseGaussMarkovResult(relatedCommand, system, prn, process, enabled, sigma, time, seed));
    }

    GetSatellitePseudorangeNoiseGaussMarkovResultPtr GetSatellitePseudorangeNoiseGaussMarkovResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePseudorangeNoiseGaussMarkovResult>(ptr);
    }

    bool GetSatellitePseudorangeNoiseGaussMarkovResult::isValid() const
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

    std::string GetSatellitePseudorangeNoiseGaussMarkovResult::documentation() const { return Documentation; }


    std::string GetSatellitePseudorangeNoiseGaussMarkovResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkovResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseGaussMarkovResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkovResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseGaussMarkovResult::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkovResult::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetSatellitePseudorangeNoiseGaussMarkovResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkovResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePseudorangeNoiseGaussMarkovResult::sigma() const
    {
      return parse_json<double>::parse(m_values["Sigma"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkovResult::setSigma(double sigma)
    {
      m_values.AddMember("Sigma", parse_json<double>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePseudorangeNoiseGaussMarkovResult::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkovResult::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseGaussMarkovResult::seed() const
    {
      return parse_json<int>::parse(m_values["Seed"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkovResult::setSeed(int seed)
    {
      m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
