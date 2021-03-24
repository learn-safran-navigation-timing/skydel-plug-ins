#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetQzssPerturbations
///
#include "gen/ResetQzssPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetQzssPerturbations::CmdName = "ResetQzssPerturbations";
    const char* const ResetQzssPerturbations::Documentation = "Please note the command ResetQzssPerturbations is deprecated since 20.9. You may use ResetPerturbations.\n\nSet QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero";

    REGISTER_COMMAND_FACTORY(ResetQzssPerturbations);


    ResetQzssPerturbations::ResetQzssPerturbations()
      : CommandBase(CmdName)
    {}

    ResetQzssPerturbations::ResetQzssPerturbations(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    ResetQzssPerturbationsPtr ResetQzssPerturbations::create(int svId)
    {
      return ResetQzssPerturbationsPtr(new ResetQzssPerturbations(svId));
    }

    ResetQzssPerturbationsPtr ResetQzssPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetQzssPerturbations>(ptr);
    }

    bool ResetQzssPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string ResetQzssPerturbations::documentation() const { return Documentation; }


    int ResetQzssPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ResetQzssPerturbations::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void ResetQzssPerturbations::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
