#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatelliteEphemerisErrorResult
///
#include "gen/GetSatelliteEphemerisErrorResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatelliteEphemerisErrorResult::CmdName = "GetSatelliteEphemerisErrorResult";
    const char* const GetSatelliteEphemerisErrorResult::Documentation = "Result of GetSatelliteEphemerisError.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSatelliteEphemerisErrorResult);


    GetSatelliteEphemerisErrorResult::GetSatelliteEphemerisErrorResult()
      : CommandResult(CmdName)
    {}

    GetSatelliteEphemerisErrorResult::GetSatelliteEphemerisErrorResult(CommandBasePtr relatedCommand, const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setOrbit(orbit);
      setDeltaAf0(deltaAf0);
      setDeltaAf1(deltaAf1);
    }


    GetSatelliteEphemerisErrorResultPtr GetSatelliteEphemerisErrorResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
    {
      return GetSatelliteEphemerisErrorResultPtr(new GetSatelliteEphemerisErrorResult(relatedCommand, system, prn, orbit, deltaAf0, deltaAf1));
    }

    GetSatelliteEphemerisErrorResultPtr GetSatelliteEphemerisErrorResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatelliteEphemerisErrorResult>(ptr);
    }

    bool GetSatelliteEphemerisErrorResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::RIC>::is_valid(m_values["Orbit"])
          && parse_json<double>::is_valid(m_values["DeltaAf0"])
          && parse_json<double>::is_valid(m_values["DeltaAf1"])
        ;

    }

    std::string GetSatelliteEphemerisErrorResult::documentation() const { return Documentation; }


    std::string GetSatelliteEphemerisErrorResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSatelliteEphemerisErrorResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSatelliteEphemerisErrorResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSatelliteEphemerisErrorResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::RIC GetSatelliteEphemerisErrorResult::orbit() const
    {
      return parse_json<Sdx::RIC>::parse(m_values["Orbit"]);
    }

    void GetSatelliteEphemerisErrorResult::setOrbit(const Sdx::RIC& orbit)
    {
      m_values.AddMember("Orbit", parse_json<Sdx::RIC>::format(orbit, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatelliteEphemerisErrorResult::deltaAf0() const
    {
      return parse_json<double>::parse(m_values["DeltaAf0"]);
    }

    void GetSatelliteEphemerisErrorResult::setDeltaAf0(double deltaAf0)
    {
      m_values.AddMember("DeltaAf0", parse_json<double>::format(deltaAf0, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatelliteEphemerisErrorResult::deltaAf1() const
    {
      return parse_json<double>::parse(m_values["DeltaAf1"]);
    }

    void GetSatelliteEphemerisErrorResult::setDeltaAf1(double deltaAf1)
    {
      m_values.AddMember("DeltaAf1", parse_json<double>::format(deltaAf1, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
