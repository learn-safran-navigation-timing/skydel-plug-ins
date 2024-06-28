
#include "GetPerturbationsForAllSatResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPerturbationsForAllSatResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPerturbationsForAllSatResult::CmdName = "GetPerturbationsForAllSatResult";
    const char* const GetPerturbationsForAllSatResult::Documentation = "Result of GetPerturbationsForAllSat.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Crs         array double    Crs (meter)\n"
      "Crc         array double    Crc (meter)\n"
      "Cis         array double    Cis (rad)\n"
      "Cic         array double    Cic (rad)\n"
      "Cus         array double    Cus (rad)\n"
      "Cuc         array double    Cuc (rad)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPerturbationsForAllSatResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPerturbationsForAllSatResult);


    GetPerturbationsForAllSatResult::GetPerturbationsForAllSatResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPerturbationsForAllSatResult::GetPerturbationsForAllSatResult(const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
      setDataSetName(dataSetName);
    }

    GetPerturbationsForAllSatResult::GetPerturbationsForAllSatResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
      setDataSetName(dataSetName);
    }


    GetPerturbationsForAllSatResultPtr GetPerturbationsForAllSatResult::create(const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPerturbationsForAllSatResult>(system, crs, crc, cis, cic, cus, cuc, dataSetName);
    }

    GetPerturbationsForAllSatResultPtr GetPerturbationsForAllSatResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPerturbationsForAllSatResult>(relatedCommand, system, crs, crc, cis, cic, cus, cuc, dataSetName);
    }

    GetPerturbationsForAllSatResultPtr GetPerturbationsForAllSatResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPerturbationsForAllSatResult>(ptr);
    }

    bool GetPerturbationsForAllSatResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<double>>::is_valid(m_values["Crs"])
          && parse_json<std::vector<double>>::is_valid(m_values["Crc"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cis"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cic"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cus"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cuc"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPerturbationsForAllSatResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPerturbationsForAllSatResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Crs", "Crc", "Cis", "Cic", "Cus", "Cuc", "DataSetName"}; 
      return names; 
    }


    std::string GetPerturbationsForAllSatResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPerturbationsForAllSatResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPerturbationsForAllSatResult::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void GetPerturbationsForAllSatResult::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPerturbationsForAllSatResult::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void GetPerturbationsForAllSatResult::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPerturbationsForAllSatResult::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void GetPerturbationsForAllSatResult::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPerturbationsForAllSatResult::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void GetPerturbationsForAllSatResult::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPerturbationsForAllSatResult::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void GetPerturbationsForAllSatResult::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPerturbationsForAllSatResult::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void GetPerturbationsForAllSatResult::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPerturbationsForAllSatResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPerturbationsForAllSatResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
