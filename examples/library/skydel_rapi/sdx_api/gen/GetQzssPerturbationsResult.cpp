#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssPerturbationsResult
///
#include "gen/GetQzssPerturbationsResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssPerturbationsResult::CmdName = "GetQzssPerturbationsResult";
    const char* const GetQzssPerturbationsResult::Documentation = "Result of GetQzssPerturbations.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssPerturbationsResult);


    GetQzssPerturbationsResult::GetQzssPerturbationsResult()
      : CommandResult(CmdName)
    {}

    GetQzssPerturbationsResult::GetQzssPerturbationsResult(CommandBasePtr relatedCommand, int svId, double crs, double crc, double cis, double cic, double cus, double cuc)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    GetQzssPerturbationsResultPtr GetQzssPerturbationsResult::create(CommandBasePtr relatedCommand, int svId, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return GetQzssPerturbationsResultPtr(new GetQzssPerturbationsResult(relatedCommand, svId, crs, crc, cis, cic, cus, cuc));
    }

    GetQzssPerturbationsResultPtr GetQzssPerturbationsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssPerturbationsResult>(ptr);
    }

    bool GetQzssPerturbationsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["Crs"])
          && parse_json<double>::is_valid(m_values["Crc"])
          && parse_json<double>::is_valid(m_values["Cis"])
          && parse_json<double>::is_valid(m_values["Cic"])
          && parse_json<double>::is_valid(m_values["Cus"])
          && parse_json<double>::is_valid(m_values["Cuc"])
        ;

    }

    std::string GetQzssPerturbationsResult::documentation() const { return Documentation; }


    int GetQzssPerturbationsResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssPerturbationsResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssPerturbationsResult::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void GetQzssPerturbationsResult::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssPerturbationsResult::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void GetQzssPerturbationsResult::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssPerturbationsResult::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void GetQzssPerturbationsResult::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssPerturbationsResult::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void GetQzssPerturbationsResult::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssPerturbationsResult::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void GetQzssPerturbationsResult::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssPerturbationsResult::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void GetQzssPerturbationsResult::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
