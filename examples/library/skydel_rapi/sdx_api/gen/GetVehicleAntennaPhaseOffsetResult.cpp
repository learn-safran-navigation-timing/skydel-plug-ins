#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaPhaseOffsetResult
///
#include "gen/GetVehicleAntennaPhaseOffsetResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaPhaseOffsetResult::CmdName = "GetVehicleAntennaPhaseOffsetResult";
    const char* const GetVehicleAntennaPhaseOffsetResult::Documentation = "Result of GetVehicleAntennaPhaseOffset.";

    REGISTER_COMMAND_RESULT_FACTORY(GetVehicleAntennaPhaseOffsetResult);


    GetVehicleAntennaPhaseOffsetResult::GetVehicleAntennaPhaseOffsetResult()
      : CommandResult(CmdName)
    {}

    GetVehicleAntennaPhaseOffsetResult::GetVehicleAntennaPhaseOffsetResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName, relatedCommand)
    {

      setPhaseOffset(phaseOffset);
      setType(type);
      setBand(band);
      setName(name);
    }


    GetVehicleAntennaPhaseOffsetResultPtr GetVehicleAntennaPhaseOffsetResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return GetVehicleAntennaPhaseOffsetResultPtr(new GetVehicleAntennaPhaseOffsetResult(relatedCommand, phaseOffset, type, band, name));
    }

    GetVehicleAntennaPhaseOffsetResultPtr GetVehicleAntennaPhaseOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaPhaseOffsetResult>(ptr);
    }

    bool GetVehicleAntennaPhaseOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffset"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaPhaseOffsetResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetVehicleAntennaPhaseOffsetResult::phaseOffset() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffset"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<std::vector<std::vector<double>>>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaPhaseOffsetResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand GetVehicleAntennaPhaseOffsetResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetVehicleAntennaPhaseOffsetResult::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaPhaseOffsetResult::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
