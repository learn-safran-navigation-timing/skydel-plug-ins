#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouPerturbationsResult
///
#include "gen/GetBeiDouPerturbationsResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouPerturbationsResult::CmdName = "GetBeiDouPerturbationsResult";
    const char* const GetBeiDouPerturbationsResult::Documentation = "Result of GetBeiDouPerturbations.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouPerturbationsResult);


    GetBeiDouPerturbationsResult::GetBeiDouPerturbationsResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouPerturbationsResult::GetBeiDouPerturbationsResult(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
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


    GetBeiDouPerturbationsResultPtr GetBeiDouPerturbationsResult::create(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return GetBeiDouPerturbationsResultPtr(new GetBeiDouPerturbationsResult(relatedCommand, prn, crs, crc, cis, cic, cus, cuc));
    }

    GetBeiDouPerturbationsResultPtr GetBeiDouPerturbationsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouPerturbationsResult>(ptr);
    }

    bool GetBeiDouPerturbationsResult::isValid() const
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

    std::string GetBeiDouPerturbationsResult::documentation() const { return Documentation; }


    int GetBeiDouPerturbationsResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouPerturbationsResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouPerturbationsResult::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void GetBeiDouPerturbationsResult::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouPerturbationsResult::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void GetBeiDouPerturbationsResult::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouPerturbationsResult::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void GetBeiDouPerturbationsResult::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouPerturbationsResult::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void GetBeiDouPerturbationsResult::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouPerturbationsResult::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void GetBeiDouPerturbationsResult::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouPerturbationsResult::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void GetBeiDouPerturbationsResult::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
