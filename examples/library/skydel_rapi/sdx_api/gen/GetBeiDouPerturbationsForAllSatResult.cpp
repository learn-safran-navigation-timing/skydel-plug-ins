#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouPerturbationsForAllSatResult
///
#include "gen/GetBeiDouPerturbationsForAllSatResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouPerturbationsForAllSatResult::CmdName = "GetBeiDouPerturbationsForAllSatResult";
    const char* const GetBeiDouPerturbationsForAllSatResult::Documentation = "Result of GetBeiDouPerturbationsForAllSat.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouPerturbationsForAllSatResult);


    GetBeiDouPerturbationsForAllSatResult::GetBeiDouPerturbationsForAllSatResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouPerturbationsForAllSatResult::GetBeiDouPerturbationsForAllSatResult(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
      : CommandResult(CmdName, relatedCommand)
    {

      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    GetBeiDouPerturbationsForAllSatResultPtr GetBeiDouPerturbationsForAllSatResult::create(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
    {
      return GetBeiDouPerturbationsForAllSatResultPtr(new GetBeiDouPerturbationsForAllSatResult(relatedCommand, crs, crc, cis, cic, cus, cuc));
    }

    GetBeiDouPerturbationsForAllSatResultPtr GetBeiDouPerturbationsForAllSatResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouPerturbationsForAllSatResult>(ptr);
    }

    bool GetBeiDouPerturbationsForAllSatResult::isValid() const
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

    std::string GetBeiDouPerturbationsForAllSatResult::documentation() const { return Documentation; }


    std::vector<double> GetBeiDouPerturbationsForAllSatResult::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void GetBeiDouPerturbationsForAllSatResult::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetBeiDouPerturbationsForAllSatResult::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void GetBeiDouPerturbationsForAllSatResult::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetBeiDouPerturbationsForAllSatResult::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void GetBeiDouPerturbationsForAllSatResult::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetBeiDouPerturbationsForAllSatResult::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void GetBeiDouPerturbationsForAllSatResult::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetBeiDouPerturbationsForAllSatResult::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void GetBeiDouPerturbationsForAllSatResult::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetBeiDouPerturbationsForAllSatResult::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void GetBeiDouPerturbationsForAllSatResult::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
