
#include "PushDynamicSVData.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushDynamicSVData
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushDynamicSVData::CmdName = "PushDynamicSVData";
    const char* const PushDynamicSVData::Documentation = "Push a block of data defining the orbit, clock, and other parameters for one SV.\n"
      "  ParamName           Unit\n"
      "  \"Time of ephemeris\" sec (of GPS week)\n"
      "  \"Week Number\"       week\n"
      "  \"Transmission Time\" sec (of GPS week)\n"
      "  \"ClockBias\"         sec\n"
      "  \"ClockDrift\"        sec/sec\n"
      "  \"ClockDriftRate\"    sec/sec^2\n"
      "  \"Crs\"               meter\n"
      "  \"Crc\"               meter\n"
      "  \"Cis\"               rad\n"
      "  \"Cic\"               rad\n"
      "  \"Cus\"               rad\n"
      "  \"Cuc\"               rad\n"
      "  \"DeltaN\"            rad/sec\n"
      "  \"M0\"                rad\n"
      "  \"Eccentricity\"      -\n"
      "  \"SqrtA\"             sqrt(meter)\n"
      "  \"BigOmega\"          rad\n"
      "  \"I0\"                rad\n"
      "  \"LittleOmega\"       rad\n"
      "  \"BigOmegaDot\"       rad/sec\n"
      "  \"Idot\"              rad/sec\n"
      "  \"Accuracy\"          meter\n"
      "  \"Adot\"              meters/sec\n"
      "  \"DeltaN0dot\"        rad/sec^2\n"
      "\n"
      "After a block is pushed for a SV, no other block can be pushed for that SV until the interpolation period is over.\n"
      "  Constellation   Interpolation period (sec)\n"
      "  GPS             3600\n"
      "  Galileo         300\n"
      "  BeiDou          1800\n"
      "  QZSS            1800\n"
      "  NavIC           2400\n"
      "\n"
      "\n"
      "Name           Type                  Description\n"
      "-------------- --------------------- ---------------------------------------------------------------------------------------\n"
      "System         string                \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId           int                   Satellite's SV ID.\n"
      "Toc            datetime              Time of Clock.\n"
      "ParametersDict dict string:double    A dictionary of parameters pairs.\n"
      "                                     Accepted keys are: \"Time of ephemeris\", \"Week Number\", \"Transmission Time\",\n"
      "                                                        \"ClockBias\", \"ClockDrift\", \"ClockDriftRate\", \"Crs\", \"Crc\",\n"
      "                                                        \"Cis\", \"Cic\", \"Cus\", \"Cuc\", \"DeltaN\", \"M0\", \"Eccentricity\",\n"
      "                                                        \"SqrtA\", \"BigOmega\", \"I0\", \"LittleOmega\", \"BigOmegaDot\",\n"
      "                                                        \"Idot\", \"Adot\", \"DeltaN0dot\", \"UraIndex\", \"IODE\", \"IODNAV\",\n"
      "                                                        \"IODEC\", \"IODC\", \"Tgd\", \"IscL1CA\", \"IscL2C\", \"IscL5I5\",\n"
      "                                                        \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\", \"BgdE1E5a\", \"BgdE1E5b\",\n"
      "                                                        \"Tgd1\", \"Tgd2\", \"TgdB1Cp\", \"TgdB2ap\", \"IscB1Cd\", \"IscB2ad\",\n"
      "                                                        \"SisaE1E5a\" and \"SisaE1E5b\"\n"
      "DataSetTypes   optional array string Optional data set type array: \"Ephemeris\" or \"Orbit\". If not provided, applies to both.";
    const char* const PushDynamicSVData::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(PushDynamicSVData);
    REGISTER_COMMAND_TO_FACTORY_IMPL(PushDynamicSVData);


    PushDynamicSVData::PushDynamicSVData()
      : CommandBase(CmdName, TargetId)
    {}

    PushDynamicSVData::PushDynamicSVData(const std::string& system, int svId, const Sdx::DateTime& toc, const std::map<std::string, double>& parametersDict, const Sdx::optional<std::vector<std::string>>& dataSetTypes)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setToc(toc);
      setParametersDict(parametersDict);
      setDataSetTypes(dataSetTypes);
    }

    PushDynamicSVDataPtr PushDynamicSVData::create(const std::string& system, int svId, const Sdx::DateTime& toc, const std::map<std::string, double>& parametersDict, const Sdx::optional<std::vector<std::string>>& dataSetTypes)
    {
      return std::make_shared<PushDynamicSVData>(system, svId, toc, parametersDict, dataSetTypes);
    }

    PushDynamicSVDataPtr PushDynamicSVData::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushDynamicSVData>(ptr);
    }

    bool PushDynamicSVData::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Toc"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["ParametersDict"])
          && parse_json<Sdx::optional<std::vector<std::string>>>::is_valid(m_values["DataSetTypes"])
        ;

    }

    std::string PushDynamicSVData::documentation() const { return Documentation; }

    const std::vector<std::string>& PushDynamicSVData::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Toc", "ParametersDict", "DataSetTypes"}; 
      return names; 
    }


    int PushDynamicSVData::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string PushDynamicSVData::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void PushDynamicSVData::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int PushDynamicSVData::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void PushDynamicSVData::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime PushDynamicSVData::toc() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Toc"]);
    }

    void PushDynamicSVData::setToc(const Sdx::DateTime& toc)
    {
      m_values.AddMember("Toc", parse_json<Sdx::DateTime>::format(toc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> PushDynamicSVData::parametersDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["ParametersDict"]);
    }

    void PushDynamicSVData::setParametersDict(const std::map<std::string, double>& parametersDict)
    {
      m_values.AddMember("ParametersDict", parse_json<std::map<std::string, double>>::format(parametersDict, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::vector<std::string>> PushDynamicSVData::dataSetTypes() const
    {
      return parse_json<Sdx::optional<std::vector<std::string>>>::parse(m_values["DataSetTypes"]);
    }

    void PushDynamicSVData::setDataSetTypes(const Sdx::optional<std::vector<std::string>>& dataSetTypes)
    {
      m_values.AddMember("DataSetTypes", parse_json<Sdx::optional<std::vector<std::string>>>::format(dataSetTypes, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
