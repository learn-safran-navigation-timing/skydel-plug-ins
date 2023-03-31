#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePseudorangeNoiseGaussMarkov
///
#include "gen/GetSatellitePseudorangeNoiseGaussMarkov.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePseudorangeNoiseGaussMarkov::CmdName = "GetSatellitePseudorangeNoiseGaussMarkov";
    const char* const GetSatellitePseudorangeNoiseGaussMarkov::Documentation = "Please note the command GetSatellitePseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use GetPseudorangeNoiseGaussMarkovForSV.\n\nGet the satellite pseudorange noise Gauss-Markov process attributes.";

    REGISTER_COMMAND_FACTORY(GetSatellitePseudorangeNoiseGaussMarkov);


    GetSatellitePseudorangeNoiseGaussMarkov::GetSatellitePseudorangeNoiseGaussMarkov()
      : CommandBase(CmdName)
    {}

    GetSatellitePseudorangeNoiseGaussMarkov::GetSatellitePseudorangeNoiseGaussMarkov(const std::string& system, int prn, int process)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setProcess(process);
    }


    GetSatellitePseudorangeNoiseGaussMarkovPtr GetSatellitePseudorangeNoiseGaussMarkov::create(const std::string& system, int prn, int process)
    {
      return GetSatellitePseudorangeNoiseGaussMarkovPtr(new GetSatellitePseudorangeNoiseGaussMarkov(system, prn, process));
    }

    GetSatellitePseudorangeNoiseGaussMarkovPtr GetSatellitePseudorangeNoiseGaussMarkov::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePseudorangeNoiseGaussMarkov>(ptr);
    }

    bool GetSatellitePseudorangeNoiseGaussMarkov::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Process"])
        ;

    }

    std::string GetSatellitePseudorangeNoiseGaussMarkov::documentation() const { return Documentation; }


    int GetSatellitePseudorangeNoiseGaussMarkov::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSatellitePseudorangeNoiseGaussMarkov::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkov::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseGaussMarkov::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkov::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseGaussMarkov::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetSatellitePseudorangeNoiseGaussMarkov::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
