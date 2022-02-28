#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseGaussMarkovForEachSV
///
#include "gen/GetPseudorangeNoiseGaussMarkovForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseGaussMarkovForEachSV::CmdName = "GetPseudorangeNoiseGaussMarkovForEachSV";
    const char* const GetPseudorangeNoiseGaussMarkovForEachSV::Documentation = "Please note the command GetAllSatellitesPseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use GetPseudorangeNoiseGaussMarkovForEachSV.\n\nGet the satellite pseudorange noise Gauss-Markov process attributes for all satellites.";

    REGISTER_COMMAND_FACTORY(GetPseudorangeNoiseGaussMarkovForEachSV);


    GetPseudorangeNoiseGaussMarkovForEachSV::GetPseudorangeNoiseGaussMarkovForEachSV()
      : CommandBase(CmdName)
    {}

    GetPseudorangeNoiseGaussMarkovForEachSV::GetPseudorangeNoiseGaussMarkovForEachSV(const std::string& system, int process)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setProcess(process);
    }


    GetPseudorangeNoiseGaussMarkovForEachSVPtr GetPseudorangeNoiseGaussMarkovForEachSV::create(const std::string& system, int process)
    {
      return GetPseudorangeNoiseGaussMarkovForEachSVPtr(new GetPseudorangeNoiseGaussMarkovForEachSV(system, process));
    }

    GetPseudorangeNoiseGaussMarkovForEachSVPtr GetPseudorangeNoiseGaussMarkovForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseGaussMarkovForEachSV>(ptr);
    }

    bool GetPseudorangeNoiseGaussMarkovForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Process"])
        ;

    }

    std::string GetPseudorangeNoiseGaussMarkovForEachSV::documentation() const { return Documentation; }


    int GetPseudorangeNoiseGaussMarkovForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseGaussMarkovForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseGaussMarkovForEachSV::process() const
    {
      return parse_json<int>::parse(m_values["Process"]);
    }

    void GetPseudorangeNoiseGaussMarkovForEachSV::setProcess(int process)
    {
      m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
