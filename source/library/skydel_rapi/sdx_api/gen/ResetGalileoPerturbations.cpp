#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetGalileoPerturbations
///
#include "gen/ResetGalileoPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetGalileoPerturbations::CmdName = "ResetGalileoPerturbations";
    const char* const ResetGalileoPerturbations::Documentation = "Please note the command ResetGalileoPerturbations is deprecated since 21.3. You may use ResetPerturbations.\n\nSet Galileo orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero";

    REGISTER_COMMAND_FACTORY(ResetGalileoPerturbations);


    ResetGalileoPerturbations::ResetGalileoPerturbations()
      : CommandBase(CmdName)
    {}

    ResetGalileoPerturbations::ResetGalileoPerturbations(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    ResetGalileoPerturbationsPtr ResetGalileoPerturbations::create(int prn)
    {
      return ResetGalileoPerturbationsPtr(new ResetGalileoPerturbations(prn));
    }

    ResetGalileoPerturbationsPtr ResetGalileoPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetGalileoPerturbations>(ptr);
    }

    bool ResetGalileoPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string ResetGalileoPerturbations::documentation() const { return Documentation; }


    int ResetGalileoPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ResetGalileoPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void ResetGalileoPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
