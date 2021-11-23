#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatelliteEphemerisError
///
#include "gen/GetSatelliteEphemerisError.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatelliteEphemerisError::CmdName = "GetSatelliteEphemerisError";
    const char* const GetSatelliteEphemerisError::Documentation = "Please note the command GetSatelliteEphemerisError is deprecated since 21.3. You may use GetEphemerisErrorForSV.\n\nGet the satellite ephemeris error.";

    REGISTER_COMMAND_FACTORY(GetSatelliteEphemerisError);


    GetSatelliteEphemerisError::GetSatelliteEphemerisError()
      : CommandBase(CmdName)
    {}

    GetSatelliteEphemerisError::GetSatelliteEphemerisError(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    GetSatelliteEphemerisErrorPtr GetSatelliteEphemerisError::create(const std::string& system, int prn)
    {
      return GetSatelliteEphemerisErrorPtr(new GetSatelliteEphemerisError(system, prn));
    }

    GetSatelliteEphemerisErrorPtr GetSatelliteEphemerisError::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatelliteEphemerisError>(ptr);
    }

    bool GetSatelliteEphemerisError::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetSatelliteEphemerisError::documentation() const { return Documentation; }


    int GetSatelliteEphemerisError::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSatelliteEphemerisError::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatelliteEphemerisError::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatelliteEphemerisError::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatelliteEphemerisError::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
