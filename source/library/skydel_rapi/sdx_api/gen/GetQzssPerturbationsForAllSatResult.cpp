#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssPerturbationsForAllSatResult
///
#include "gen/GetQzssPerturbationsForAllSatResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssPerturbationsForAllSatResult::CmdName = "GetQzssPerturbationsForAllSatResult";
    const char* const GetQzssPerturbationsForAllSatResult::Documentation = "Result of GetQzssPerturbationsForAllSat.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssPerturbationsForAllSatResult);


    GetQzssPerturbationsForAllSatResult::GetQzssPerturbationsForAllSatResult()
      : CommandResult(CmdName)
    {}

    GetQzssPerturbationsForAllSatResult::GetQzssPerturbationsForAllSatResult(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
      : CommandResult(CmdName, relatedCommand)
    {

      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    GetQzssPerturbationsForAllSatResultPtr GetQzssPerturbationsForAllSatResult::create(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
    {
      return GetQzssPerturbationsForAllSatResultPtr(new GetQzssPerturbationsForAllSatResult(relatedCommand, crs, crc, cis, cic, cus, cuc));
    }

    GetQzssPerturbationsForAllSatResultPtr GetQzssPerturbationsForAllSatResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssPerturbationsForAllSatResult>(ptr);
    }

    bool GetQzssPerturbationsForAllSatResult::isValid() const
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

    std::string GetQzssPerturbationsForAllSatResult::documentation() const { return Documentation; }


    std::vector<double> GetQzssPerturbationsForAllSatResult::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void GetQzssPerturbationsForAllSatResult::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetQzssPerturbationsForAllSatResult::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void GetQzssPerturbationsForAllSatResult::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetQzssPerturbationsForAllSatResult::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void GetQzssPerturbationsForAllSatResult::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetQzssPerturbationsForAllSatResult::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void GetQzssPerturbationsForAllSatResult::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetQzssPerturbationsForAllSatResult::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void GetQzssPerturbationsForAllSatResult::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetQzssPerturbationsForAllSatResult::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void GetQzssPerturbationsForAllSatResult::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
