#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoPerturbations
///
#include "gen/SetGalileoPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoPerturbations::CmdName = "SetGalileoPerturbations";
    const char* const SetGalileoPerturbations::Documentation = "Please note the command SetGalileoPerturbations is deprecated since 21.3. You may use SetPerturbations.\n\nSet GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(SetGalileoPerturbations);


    SetGalileoPerturbations::SetGalileoPerturbations()
      : CommandBase(CmdName)
    {}

    SetGalileoPerturbations::SetGalileoPerturbations(int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
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


    SetGalileoPerturbationsPtr SetGalileoPerturbations::create(int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return SetGalileoPerturbationsPtr(new SetGalileoPerturbations(prn, crs, crc, cis, cic, cus, cuc));
    }

    SetGalileoPerturbationsPtr SetGalileoPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoPerturbations>(ptr);
    }

    bool SetGalileoPerturbations::isValid() const
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

    std::string SetGalileoPerturbations::documentation() const { return Documentation; }


    int SetGalileoPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGalileoPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGalileoPerturbations::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void SetGalileoPerturbations::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGalileoPerturbations::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void SetGalileoPerturbations::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGalileoPerturbations::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void SetGalileoPerturbations::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGalileoPerturbations::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void SetGalileoPerturbations::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGalileoPerturbations::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void SetGalileoPerturbations::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGalileoPerturbations::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void SetGalileoPerturbations::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
