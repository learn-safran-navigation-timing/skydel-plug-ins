#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsPerturbationsResult
///
#include "gen/GetGpsPerturbationsResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsPerturbationsResult::CmdName = "GetGpsPerturbationsResult";
    const char* const GetGpsPerturbationsResult::Documentation = "Result of GetGpsPerturbations.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsPerturbationsResult);


    GetGpsPerturbationsResult::GetGpsPerturbationsResult()
      : CommandResult(CmdName)
    {}

    GetGpsPerturbationsResult::GetGpsPerturbationsResult(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    GetGpsPerturbationsResultPtr GetGpsPerturbationsResult::create(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return GetGpsPerturbationsResultPtr(new GetGpsPerturbationsResult(relatedCommand, prn, crs, crc, cis, cic, cus, cuc));
    }

    GetGpsPerturbationsResultPtr GetGpsPerturbationsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsPerturbationsResult>(ptr);
    }

    bool GetGpsPerturbationsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<double>::is_valid(m_values["Crs"])
          && parse_json<double>::is_valid(m_values["Crc"])
          && parse_json<double>::is_valid(m_values["Cis"])
          && parse_json<double>::is_valid(m_values["Cic"])
          && parse_json<double>::is_valid(m_values["Cus"])
          && parse_json<double>::is_valid(m_values["Cuc"])
        ;

    }

    std::string GetGpsPerturbationsResult::documentation() const { return Documentation; }


    int GetGpsPerturbationsResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsPerturbationsResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsPerturbationsResult::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void GetGpsPerturbationsResult::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsPerturbationsResult::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void GetGpsPerturbationsResult::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsPerturbationsResult::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void GetGpsPerturbationsResult::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsPerturbationsResult::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void GetGpsPerturbationsResult::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsPerturbationsResult::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void GetGpsPerturbationsResult::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsPerturbationsResult::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void GetGpsPerturbationsResult::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
