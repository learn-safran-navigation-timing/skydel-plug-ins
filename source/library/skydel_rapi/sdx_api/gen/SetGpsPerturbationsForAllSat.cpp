#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsPerturbationsForAllSat
///
#include "gen/SetGpsPerturbationsForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsPerturbationsForAllSat::CmdName = "SetGpsPerturbationsForAllSat";
    const char* const SetGpsPerturbationsForAllSat::Documentation = "Please note the command SetGpsPerturbationsForAllSat is deprecated since 21.3. You may use SetPerturbationsForAllSat.\n\nSet GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.\nAll parameters are zero based index (index 0 => PRN 1, index 1 => PRN 2, etc)";

    REGISTER_COMMAND_FACTORY(SetGpsPerturbationsForAllSat);


    SetGpsPerturbationsForAllSat::SetGpsPerturbationsForAllSat()
      : CommandBase(CmdName)
    {}

    SetGpsPerturbationsForAllSat::SetGpsPerturbationsForAllSat(const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
      : CommandBase(CmdName)
    {

      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    SetGpsPerturbationsForAllSatPtr SetGpsPerturbationsForAllSat::create(const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc)
    {
      return SetGpsPerturbationsForAllSatPtr(new SetGpsPerturbationsForAllSat(crs, crc, cis, cic, cus, cuc));
    }

    SetGpsPerturbationsForAllSatPtr SetGpsPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsPerturbationsForAllSat>(ptr);
    }

    bool SetGpsPerturbationsForAllSat::isValid() const
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

    std::string SetGpsPerturbationsForAllSat::documentation() const { return Documentation; }


    int SetGpsPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<double> SetGpsPerturbationsForAllSat::crs() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crs"]);
    }

    void SetGpsPerturbationsForAllSat::setCrs(const std::vector<double>& crs)
    {
      m_values.AddMember("Crs", parse_json<std::vector<double>>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGpsPerturbationsForAllSat::crc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Crc"]);
    }

    void SetGpsPerturbationsForAllSat::setCrc(const std::vector<double>& crc)
    {
      m_values.AddMember("Crc", parse_json<std::vector<double>>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGpsPerturbationsForAllSat::cis() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cis"]);
    }

    void SetGpsPerturbationsForAllSat::setCis(const std::vector<double>& cis)
    {
      m_values.AddMember("Cis", parse_json<std::vector<double>>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGpsPerturbationsForAllSat::cic() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cic"]);
    }

    void SetGpsPerturbationsForAllSat::setCic(const std::vector<double>& cic)
    {
      m_values.AddMember("Cic", parse_json<std::vector<double>>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGpsPerturbationsForAllSat::cus() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cus"]);
    }

    void SetGpsPerturbationsForAllSat::setCus(const std::vector<double>& cus)
    {
      m_values.AddMember("Cus", parse_json<std::vector<double>>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGpsPerturbationsForAllSat::cuc() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Cuc"]);
    }

    void SetGpsPerturbationsForAllSat::setCuc(const std::vector<double>& cuc)
    {
      m_values.AddMember("Cuc", parse_json<std::vector<double>>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
