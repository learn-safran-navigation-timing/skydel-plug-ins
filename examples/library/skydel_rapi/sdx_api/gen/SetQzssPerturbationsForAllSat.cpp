#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssPerturbationsForAllSat
///
#include "gen/SetQzssPerturbationsForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssPerturbationsForAllSat::CmdName = "SetQzssPerturbationsForAllSat";
    const char* const SetQzssPerturbationsForAllSat::Documentation = "Please note the command SetQzssPerturbationsForAllSat is deprecated since 20.9. You may use SetPerturbationsForAllSat.\n\nSet QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.\nAll parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";

    REGISTER_COMMAND_FACTORY(SetQzssPerturbationsForAllSat);


    SetQzssPerturbationsForAllSat::SetQzssPerturbationsForAllSat()
      : CommandBase(CmdName)
    {}

    SetQzssPerturbationsForAllSat::SetQzssPerturbationsForAllSat(const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
      : CommandBase(CmdName)
    {

      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    SetQzssPerturbationsForAllSatPtr SetQzssPerturbationsForAllSat::create(const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
    {
      return SetQzssPerturbationsForAllSatPtr(new SetQzssPerturbationsForAllSat(crs, crc, cis, cic, cus, cuc));
    }

    SetQzssPerturbationsForAllSatPtr SetQzssPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssPerturbationsForAllSat>(ptr);
    }

    bool SetQzssPerturbationsForAllSat::isValid() const
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

    std::string SetQzssPerturbationsForAllSat::documentation() const { return Documentation; }


    int SetQzssPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<double> SetQzssPerturbationsForAllSat::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void SetQzssPerturbationsForAllSat::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetQzssPerturbationsForAllSat::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void SetQzssPerturbationsForAllSat::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetQzssPerturbationsForAllSat::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void SetQzssPerturbationsForAllSat::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetQzssPerturbationsForAllSat::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void SetQzssPerturbationsForAllSat::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetQzssPerturbationsForAllSat::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void SetQzssPerturbationsForAllSat::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetQzssPerturbationsForAllSat::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void SetQzssPerturbationsForAllSat::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
