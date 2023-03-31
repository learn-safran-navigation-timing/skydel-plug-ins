#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouPerturbations
///
#include "gen/SetBeiDouPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouPerturbations::CmdName = "SetBeiDouPerturbations";
    const char* const SetBeiDouPerturbations::Documentation = "Please note the command SetBeiDouPerturbations is deprecated since 21.3. You may use SetPerturbations.\n\nSet BeiDou orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(SetBeiDouPerturbations);


    SetBeiDouPerturbations::SetBeiDouPerturbations()
      : CommandBase(CmdName)
    {}

    SetBeiDouPerturbations::SetBeiDouPerturbations(int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
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


    SetBeiDouPerturbationsPtr SetBeiDouPerturbations::create(int prn, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return SetBeiDouPerturbationsPtr(new SetBeiDouPerturbations(prn, crs, crc, cis, cic, cus, cuc));
    }

    SetBeiDouPerturbationsPtr SetBeiDouPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouPerturbations>(ptr);
    }

    bool SetBeiDouPerturbations::isValid() const
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

    std::string SetBeiDouPerturbations::documentation() const { return Documentation; }


    int SetBeiDouPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetBeiDouPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouPerturbations::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void SetBeiDouPerturbations::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouPerturbations::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void SetBeiDouPerturbations::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouPerturbations::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void SetBeiDouPerturbations::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouPerturbations::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void SetBeiDouPerturbations::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouPerturbations::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void SetBeiDouPerturbations::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouPerturbations::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void SetBeiDouPerturbations::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
