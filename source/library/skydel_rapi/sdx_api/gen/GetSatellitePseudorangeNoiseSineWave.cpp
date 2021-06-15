#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePseudorangeNoiseSineWave
///
#include "gen/GetSatellitePseudorangeNoiseSineWave.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePseudorangeNoiseSineWave::CmdName = "GetSatellitePseudorangeNoiseSineWave";
    const char* const GetSatellitePseudorangeNoiseSineWave::Documentation = "Please note the command GetSatellitePseudorangeNoiseSineWave is deprecated since 21.3. You may use GetPseudorangeNoiseSineWaveForSV.\n\nGet the satellite pseudorange noise sine wave attributes.";

    REGISTER_COMMAND_FACTORY(GetSatellitePseudorangeNoiseSineWave);


    GetSatellitePseudorangeNoiseSineWave::GetSatellitePseudorangeNoiseSineWave()
      : CommandBase(CmdName)
    {}

    GetSatellitePseudorangeNoiseSineWave::GetSatellitePseudorangeNoiseSineWave(const std::string& system, int prn, int sineWave)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setSineWave(sineWave);
    }


    GetSatellitePseudorangeNoiseSineWavePtr GetSatellitePseudorangeNoiseSineWave::create(const std::string& system, int prn, int sineWave)
    {
      return GetSatellitePseudorangeNoiseSineWavePtr(new GetSatellitePseudorangeNoiseSineWave(system, prn, sineWave));
    }

    GetSatellitePseudorangeNoiseSineWavePtr GetSatellitePseudorangeNoiseSineWave::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePseudorangeNoiseSineWave>(ptr);
    }

    bool GetSatellitePseudorangeNoiseSineWave::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["SineWave"])
        ;

    }

    std::string GetSatellitePseudorangeNoiseSineWave::documentation() const { return Documentation; }


    int GetSatellitePseudorangeNoiseSineWave::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSatellitePseudorangeNoiseSineWave::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatellitePseudorangeNoiseSineWave::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseSineWave::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatellitePseudorangeNoiseSineWave::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseSineWave::sineWave() const
    {
      return parse_json<int>::parse(m_values["SineWave"]);
    }

    void GetSatellitePseudorangeNoiseSineWave::setSineWave(int sineWave)
    {
      m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
