
#include "gen/SetSVAntennaPhaseOffsetCSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaPhaseOffsetCSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaPhaseOffsetCSV::CmdName = "SetSVAntennaPhaseOffsetCSV";
    const char* const SetSVAntennaPhaseOffsetCSV::Documentation = "Set space vehicle phase offset antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic SV Antenna.";

    REGISTER_COMMAND_FACTORY(SetSVAntennaPhaseOffsetCSV);


    SetSVAntennaPhaseOffsetCSV::SetSVAntennaPhaseOffsetCSV()
      : CommandBase(CmdName)
    {}

    SetSVAntennaPhaseOffsetCSV::SetSVAntennaPhaseOffsetCSV(const std::string& filePath, const Sdx::AntennaPatternFileType& fileFormat, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setFilePath(filePath);
      setFileFormat(fileFormat);
      setType(type);
      setBand(band);
      setSystem(system);
      setName(name);
    }

    SetSVAntennaPhaseOffsetCSVPtr SetSVAntennaPhaseOffsetCSV::create(const std::string& filePath, const Sdx::AntennaPatternFileType& fileFormat, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<SetSVAntennaPhaseOffsetCSV>(filePath, fileFormat, type, band, system, name);
    }

    SetSVAntennaPhaseOffsetCSVPtr SetSVAntennaPhaseOffsetCSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaPhaseOffsetCSV>(ptr);
    }

    bool SetSVAntennaPhaseOffsetCSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<Sdx::AntennaPatternFileType>::is_valid(m_values["FileFormat"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string SetSVAntennaPhaseOffsetCSV::documentation() const { return Documentation; }


    int SetSVAntennaPhaseOffsetCSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSVAntennaPhaseOffsetCSV::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void SetSVAntennaPhaseOffsetCSV::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternFileType SetSVAntennaPhaseOffsetCSV::fileFormat() const
    {
      return parse_json<Sdx::AntennaPatternFileType>::parse(m_values["FileFormat"]);
    }

    void SetSVAntennaPhaseOffsetCSV::setFileFormat(const Sdx::AntennaPatternFileType& fileFormat)
    {
      m_values.AddMember("FileFormat", parse_json<Sdx::AntennaPatternFileType>::format(fileFormat, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetSVAntennaPhaseOffsetCSV::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetSVAntennaPhaseOffsetCSV::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GNSSBand SetSVAntennaPhaseOffsetCSV::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void SetSVAntennaPhaseOffsetCSV::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaPhaseOffsetCSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaPhaseOffsetCSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetSVAntennaPhaseOffsetCSV::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void SetSVAntennaPhaseOffsetCSV::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
