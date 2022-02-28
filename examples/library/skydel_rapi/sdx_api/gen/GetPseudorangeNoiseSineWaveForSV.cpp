#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseSineWaveForSV
///
#include "gen/GetPseudorangeNoiseSineWaveForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseSineWaveForSV::CmdName = "GetPseudorangeNoiseSineWaveForSV";
    const char* const GetPseudorangeNoiseSineWaveForSV::Documentation = "Get the satellite pseudorange noise sine wave attributes.";

    REGISTER_COMMAND_FACTORY(GetPseudorangeNoiseSineWaveForSV);


    GetPseudorangeNoiseSineWaveForSV::GetPseudorangeNoiseSineWaveForSV()
      : CommandBase(CmdName)
    {}

    GetPseudorangeNoiseSineWaveForSV::GetPseudorangeNoiseSineWaveForSV(const std::string& system, int svId, int sineWave)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setSineWave(sineWave);
    }


    GetPseudorangeNoiseSineWaveForSVPtr GetPseudorangeNoiseSineWaveForSV::create(const std::string& system, int svId, int sineWave)
    {
      return std::make_shared<GetPseudorangeNoiseSineWaveForSV>(system, svId, sineWave);
    }

    GetPseudorangeNoiseSineWaveForSVPtr GetPseudorangeNoiseSineWaveForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseSineWaveForSV>(ptr);
    }

    bool GetPseudorangeNoiseSineWaveForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["SineWave"])
        ;

    }

    std::string GetPseudorangeNoiseSineWaveForSV::documentation() const { return Documentation; }


    int GetPseudorangeNoiseSineWaveForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseSineWaveForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseSineWaveForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseSineWaveForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPseudorangeNoiseSineWaveForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseSineWaveForSV::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void GetPseudorangeNoiseSineWaveForSV::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
