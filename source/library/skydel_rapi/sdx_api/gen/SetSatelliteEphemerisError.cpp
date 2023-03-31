#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSatelliteEphemerisError
///
#include "gen/SetSatelliteEphemerisError.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSatelliteEphemerisError::CmdName = "SetSatelliteEphemerisError";
    const char* const SetSatelliteEphemerisError::Documentation = "Please note the command SetSatelliteEphemerisError is deprecated since 21.3. You may use SetEphemerisErrorForSV.\n\nSet the satellite ephemeris error.";

    REGISTER_COMMAND_FACTORY(SetSatelliteEphemerisError);


    SetSatelliteEphemerisError::SetSatelliteEphemerisError()
      : CommandBase(CmdName)
    {}

    SetSatelliteEphemerisError::SetSatelliteEphemerisError(const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setOrbit(orbit);
      setDeltaAf0(deltaAf0);
      setDeltaAf1(deltaAf1);
    }


    SetSatelliteEphemerisErrorPtr SetSatelliteEphemerisError::create(const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
    {
      return SetSatelliteEphemerisErrorPtr(new SetSatelliteEphemerisError(system, prn, orbit, deltaAf0, deltaAf1));
    }

    SetSatelliteEphemerisErrorPtr SetSatelliteEphemerisError::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSatelliteEphemerisError>(ptr);
    }

    bool SetSatelliteEphemerisError::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::RIC>::is_valid(m_values["Orbit"])
          && parse_json<double>::is_valid(m_values["DeltaAf0"])
          && parse_json<double>::is_valid(m_values["DeltaAf1"])
        ;

    }

    std::string SetSatelliteEphemerisError::documentation() const { return Documentation; }


    int SetSatelliteEphemerisError::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSatelliteEphemerisError::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSatelliteEphemerisError::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatelliteEphemerisError::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSatelliteEphemerisError::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::RIC SetSatelliteEphemerisError::orbit() const
    {
      return parse_json<Sdx::RIC>::parse(m_values["Orbit"]);
    }

    void SetSatelliteEphemerisError::setOrbit(const Sdx::RIC& orbit)
    {
      m_values.AddMember("Orbit", parse_json<Sdx::RIC>::format(orbit, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatelliteEphemerisError::deltaAf0() const
    {
      return parse_json<double>::parse(m_values["DeltaAf0"]);
    }

    void SetSatelliteEphemerisError::setDeltaAf0(double deltaAf0)
    {
      m_values.AddMember("DeltaAf0", parse_json<double>::format(deltaAf0, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatelliteEphemerisError::deltaAf1() const
    {
      return parse_json<double>::parse(m_values["DeltaAf1"]);
    }

    void SetSatelliteEphemerisError::setDeltaAf1(double deltaAf1)
    {
      m_values.AddMember("DeltaAf1", parse_json<double>::format(deltaAf1, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
