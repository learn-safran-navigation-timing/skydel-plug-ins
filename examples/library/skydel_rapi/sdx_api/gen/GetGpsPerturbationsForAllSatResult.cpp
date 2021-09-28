#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsPerturbationsForAllSatResult
///
#include "gen/GetGpsPerturbationsForAllSatResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsPerturbationsForAllSatResult::CmdName = "GetGpsPerturbationsForAllSatResult";
    const char* const GetGpsPerturbationsForAllSatResult::Documentation = "Result of GetGpsPerturbationsForAllSat.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsPerturbationsForAllSatResult);


    GetGpsPerturbationsForAllSatResult::GetGpsPerturbationsForAllSatResult()
      : CommandResult(CmdName)
    {}

    GetGpsPerturbationsForAllSatResult::GetGpsPerturbationsForAllSatResult(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
      : CommandResult(CmdName, relatedCommand)
    {

      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    GetGpsPerturbationsForAllSatResultPtr GetGpsPerturbationsForAllSatResult::create(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
    {
      return GetGpsPerturbationsForAllSatResultPtr(new GetGpsPerturbationsForAllSatResult(relatedCommand, crs, crc, cis, cic, cus, cuc));
    }

    GetGpsPerturbationsForAllSatResultPtr GetGpsPerturbationsForAllSatResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsPerturbationsForAllSatResult>(ptr);
    }

    bool GetGpsPerturbationsForAllSatResult::isValid() const
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

    std::string GetGpsPerturbationsForAllSatResult::documentation() const { return Documentation; }


    std::vector<double> GetGpsPerturbationsForAllSatResult::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void GetGpsPerturbationsForAllSatResult::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGpsPerturbationsForAllSatResult::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void GetGpsPerturbationsForAllSatResult::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGpsPerturbationsForAllSatResult::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void GetGpsPerturbationsForAllSatResult::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGpsPerturbationsForAllSatResult::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void GetGpsPerturbationsForAllSatResult::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGpsPerturbationsForAllSatResult::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void GetGpsPerturbationsForAllSatResult::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGpsPerturbationsForAllSatResult::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void GetGpsPerturbationsForAllSatResult::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
