#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsPerturbations
///
#include "gen/SetGpsPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsPerturbations::CmdName = "SetGpsPerturbations";
    const char* const SetGpsPerturbations::Documentation = "Please note the command SetGpsPerturbations is deprecated since 21.3. You may use SetPerturbations.\n\nSet GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(SetGpsPerturbations);


    SetGpsPerturbations::SetGpsPerturbations()
      : CommandBase(CmdName)
    {}

    SetGpsPerturbations::SetGpsPerturbations(int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    SetGpsPerturbationsPtr SetGpsPerturbations::create(int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return SetGpsPerturbationsPtr(new SetGpsPerturbations(prn, crs, crc, cis, cic, cus, cuc));
    }

    SetGpsPerturbationsPtr SetGpsPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsPerturbations>(ptr);
    }

    bool SetGpsPerturbations::isValid() const
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

    std::string SetGpsPerturbations::documentation() const { return Documentation; }


    int SetGpsPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsPerturbations::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void SetGpsPerturbations::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsPerturbations::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void SetGpsPerturbations::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsPerturbations::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void SetGpsPerturbations::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsPerturbations::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void SetGpsPerturbations::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsPerturbations::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void SetGpsPerturbations::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsPerturbations::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void SetGpsPerturbations::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
