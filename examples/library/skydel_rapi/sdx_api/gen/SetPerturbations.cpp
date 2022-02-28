#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPerturbations
///
#include "gen/SetPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPerturbations::CmdName = "SetPerturbations";
    const char* const SetPerturbations::Documentation = "Set orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for the specified constellation.";

    REGISTER_COMMAND_FACTORY(SetPerturbations);


    SetPerturbations::SetPerturbations()
      : CommandBase(CmdName)
    {}

    SetPerturbations::SetPerturbations(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
      setDataSetName(dataSetName);
    }


    SetPerturbationsPtr SetPerturbations::create(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetPerturbations>(system, svId, crs, crc, cis, cic, cus, cuc, dataSetName);
    }

    SetPerturbationsPtr SetPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPerturbations>(ptr);
    }

    bool SetPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["Crs"])
          && parse_json<double>::is_valid(m_values["Crc"])
          && parse_json<double>::is_valid(m_values["Cis"])
          && parse_json<double>::is_valid(m_values["Cic"])
          && parse_json<double>::is_valid(m_values["Cus"])
          && parse_json<double>::is_valid(m_values["Cuc"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetPerturbations::documentation() const { return Documentation; }


    int SetPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPerturbations::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPerturbations::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPerturbations::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPerturbations::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPerturbations::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void SetPerturbations::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPerturbations::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void SetPerturbations::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPerturbations::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void SetPerturbations::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPerturbations::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void SetPerturbations::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPerturbations::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void SetPerturbations::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPerturbations::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void SetPerturbations::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetPerturbations::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetPerturbations::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
