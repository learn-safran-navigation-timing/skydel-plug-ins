#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoPerturbationsResult
///
#include "gen/GetGalileoPerturbationsResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoPerturbationsResult::CmdName = "GetGalileoPerturbationsResult";
    const char* const GetGalileoPerturbationsResult::Documentation = "Result of GetGalileoPerturbations.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoPerturbationsResult);


    GetGalileoPerturbationsResult::GetGalileoPerturbationsResult()
      : CommandResult(CmdName)
    {}

    GetGalileoPerturbationsResult::GetGalileoPerturbationsResult(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
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


    GetGalileoPerturbationsResultPtr GetGalileoPerturbationsResult::create(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return GetGalileoPerturbationsResultPtr(new GetGalileoPerturbationsResult(relatedCommand, prn, crs, crc, cis, cic, cus, cuc));
    }

    GetGalileoPerturbationsResultPtr GetGalileoPerturbationsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoPerturbationsResult>(ptr);
    }

    bool GetGalileoPerturbationsResult::isValid() const
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

    std::string GetGalileoPerturbationsResult::documentation() const { return Documentation; }


    int GetGalileoPerturbationsResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoPerturbationsResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoPerturbationsResult::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void GetGalileoPerturbationsResult::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoPerturbationsResult::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void GetGalileoPerturbationsResult::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoPerturbationsResult::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void GetGalileoPerturbationsResult::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoPerturbationsResult::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void GetGalileoPerturbationsResult::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoPerturbationsResult::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void GetGalileoPerturbationsResult::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGalileoPerturbationsResult::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void GetGalileoPerturbationsResult::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
