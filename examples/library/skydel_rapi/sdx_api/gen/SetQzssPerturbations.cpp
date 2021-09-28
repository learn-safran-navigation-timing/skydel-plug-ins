#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssPerturbations
///
#include "gen/SetQzssPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssPerturbations::CmdName = "SetQzssPerturbations";
    const char* const SetQzssPerturbations::Documentation = "Please note the command SetQzssPerturbations is deprecated since 20.9. You may use SetPerturbations.\n\nSet QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(SetQzssPerturbations);


    SetQzssPerturbations::SetQzssPerturbations()
      : CommandBase(CmdName)
    {}

    SetQzssPerturbations::SetQzssPerturbations(int svId, double crs, double crc, double cis, double cic, double cus, double cuc)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setCrs(crs);
      setCrc(crc);
      setCis(cis);
      setCic(cic);
      setCus(cus);
      setCuc(cuc);
    }


    SetQzssPerturbationsPtr SetQzssPerturbations::create(int svId, double crs, double crc, double cis, double cic, double cus, double cuc)
    {
      return SetQzssPerturbationsPtr(new SetQzssPerturbations(svId, crs, crc, cis, cic, cus, cuc));
    }

    SetQzssPerturbationsPtr SetQzssPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssPerturbations>(ptr);
    }

    bool SetQzssPerturbations::isValid() const
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

    std::string SetQzssPerturbations::documentation() const { return Documentation; }


    int SetQzssPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssPerturbations::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssPerturbations::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssPerturbations::crs() const
    {
      return parse_json<double>::parse(m_values["Crs"]);
    }

    void SetQzssPerturbations::setCrs(double crs)
    {
      m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssPerturbations::crc() const
    {
      return parse_json<double>::parse(m_values["Crc"]);
    }

    void SetQzssPerturbations::setCrc(double crc)
    {
      m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssPerturbations::cis() const
    {
      return parse_json<double>::parse(m_values["Cis"]);
    }

    void SetQzssPerturbations::setCis(double cis)
    {
      m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssPerturbations::cic() const
    {
      return parse_json<double>::parse(m_values["Cic"]);
    }

    void SetQzssPerturbations::setCic(double cic)
    {
      m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssPerturbations::cus() const
    {
      return parse_json<double>::parse(m_values["Cus"]);
    }

    void SetQzssPerturbations::setCus(double cus)
    {
      m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssPerturbations::cuc() const
    {
      return parse_json<double>::parse(m_values["Cuc"]);
    }

    void SetQzssPerturbations::setCuc(double cuc)
    {
      m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
