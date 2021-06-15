#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePseudorangeNoiseOffset
///
#include "gen/GetSatellitePseudorangeNoiseOffset.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePseudorangeNoiseOffset::CmdName = "GetSatellitePseudorangeNoiseOffset";
    const char* const GetSatellitePseudorangeNoiseOffset::Documentation = "Please note the command GetSatellitePseudorangeNoiseOffset is deprecated since 21.3. You may use GetPseudorangeNoiseOffsetForSV.\n\nGet the satellite pseudorange noise constant offset.";

    REGISTER_COMMAND_FACTORY(GetSatellitePseudorangeNoiseOffset);


    GetSatellitePseudorangeNoiseOffset::GetSatellitePseudorangeNoiseOffset()
      : CommandBase(CmdName)
    {}

    GetSatellitePseudorangeNoiseOffset::GetSatellitePseudorangeNoiseOffset(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    GetSatellitePseudorangeNoiseOffsetPtr GetSatellitePseudorangeNoiseOffset::create(const std::string& system, int prn)
    {
      return GetSatellitePseudorangeNoiseOffsetPtr(new GetSatellitePseudorangeNoiseOffset(system, prn));
    }

    GetSatellitePseudorangeNoiseOffsetPtr GetSatellitePseudorangeNoiseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePseudorangeNoiseOffset>(ptr);
    }

    bool GetSatellitePseudorangeNoiseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetSatellitePseudorangeNoiseOffset::documentation() const { return Documentation; }


    int GetSatellitePseudorangeNoiseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSatellitePseudorangeNoiseOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatellitePseudorangeNoiseOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatellitePseudorangeNoiseOffset::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatellitePseudorangeNoiseOffset::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
