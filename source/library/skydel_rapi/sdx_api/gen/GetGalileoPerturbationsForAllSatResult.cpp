#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoPerturbationsForAllSatResult
///
#include "gen/GetGalileoPerturbationsForAllSatResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoPerturbationsForAllSatResult::CmdName = "GetGalileoPerturbationsForAllSatResult";
    const char* const GetGalileoPerturbationsForAllSatResult::Documentation = "Result of GetGalileoPerturbationsForAllSat.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoPerturbationsForAllSatResult);


    GetGalileoPerturbationsForAllSatResult::GetGalileoPerturbationsForAllSatResult()
      : CommandResult(CmdName)
    {}

    GetGalileoPerturbationsForAllSatResult::GetGalileoPerturbationsForAllSatResult(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
      : CommandResult(CmdName, relatedCommand)
    {

      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    GetGalileoPerturbationsForAllSatResultPtr GetGalileoPerturbationsForAllSatResult::create(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
    {
      return GetGalileoPerturbationsForAllSatResultPtr(new GetGalileoPerturbationsForAllSatResult(relatedCommand, crs, crc, cis, cic, cus, cuc));
    }

    GetGalileoPerturbationsForAllSatResultPtr GetGalileoPerturbationsForAllSatResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoPerturbationsForAllSatResult>(ptr);
    }

    bool GetGalileoPerturbationsForAllSatResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<double>>::is_valid(m_values["Crs"])
          && parse_json<std::vector<double>>::is_valid(m_values["Crc"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cis"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cic"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cus"])
          && parse_json<std::vector<double>>::is_valid(m_values["Cuc"])
        ;

    }

    std::string GetGalileoPerturbationsForAllSatResult::documentation() const { return Documentation; }


    std::vector<double> GetGalileoPerturbationsForAllSatResult::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void GetGalileoPerturbationsForAllSatResult::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGalileoPerturbationsForAllSatResult::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void GetGalileoPerturbationsForAllSatResult::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGalileoPerturbationsForAllSatResult::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void GetGalileoPerturbationsForAllSatResult::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGalileoPerturbationsForAllSatResult::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void GetGalileoPerturbationsForAllSatResult::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGalileoPerturbationsForAllSatResult::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void GetGalileoPerturbationsForAllSatResult::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGalileoPerturbationsForAllSatResult::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void GetGalileoPerturbationsForAllSatResult::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
