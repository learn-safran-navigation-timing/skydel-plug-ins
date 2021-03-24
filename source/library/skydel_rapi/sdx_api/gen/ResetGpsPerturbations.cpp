#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetGpsPerturbations
///
#include "gen/ResetGpsPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetGpsPerturbations::CmdName = "ResetGpsPerturbations";
    const char* const ResetGpsPerturbations::Documentation = "Please note the command ResetGpsPerturbations is deprecated since 21.3. You may use ResetPerturbations.\n\nSet GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero";

    REGISTER_COMMAND_FACTORY(ResetGpsPerturbations);


    ResetGpsPerturbations::ResetGpsPerturbations()
      : CommandBase(CmdName)
    {}

    ResetGpsPerturbations::ResetGpsPerturbations(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    ResetGpsPerturbationsPtr ResetGpsPerturbations::create(int prn)
    {
      return ResetGpsPerturbationsPtr(new ResetGpsPerturbations(prn));
    }

    ResetGpsPerturbationsPtr ResetGpsPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetGpsPerturbations>(ptr);
    }

    bool ResetGpsPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string ResetGpsPerturbations::documentation() const { return Documentation; }


    int ResetGpsPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ResetGpsPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void ResetGpsPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
