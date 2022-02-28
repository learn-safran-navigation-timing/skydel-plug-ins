#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaGainResult
///
#include "gen/GetSVAntennaGainResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaGainResult::CmdName = "GetSVAntennaGainResult";
    const char* const GetSVAntennaGainResult::Documentation = "Result of GetSVAntennaGain.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSVAntennaGainResult);


    GetSVAntennaGainResult::GetSVAntennaGainResult()
      : CommandResult(CmdName)
    {}

    GetSVAntennaGainResult::GetSVAntennaGainResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandResult(CmdName, relatedCommand)
    {

      setGain(gain);
      setType(type);
      setBand(band);
      setSystem(system);
      setName(name);
    }


    GetSVAntennaGainResultPtr GetSVAntennaGainResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetSVAntennaGainResult>(relatedCommand, gain, type, band, system, name);
    }

    GetSVAntennaGainResultPtr GetSVAntennaGainResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaGainResult>(ptr);
    }

    bool GetSVAntennaGainResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetSVAntennaGainResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetSVAntennaGainResult::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void GetSVAntennaGainResult::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetSVAntennaGainResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetSVAntennaGainResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand GetSVAntennaGainResult::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVAntennaGainResult::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaGainResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaGainResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetSVAntennaGainResult::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetSVAntennaGainResult::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
