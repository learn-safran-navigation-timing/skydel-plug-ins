#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssPerturbations
///
#include "gen/GetQzssPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssPerturbations::CmdName = "GetQzssPerturbations";
    const char* const GetQzssPerturbations::Documentation = "Please note the command GetQzssPerturbations is deprecated since 20.9. You may use GetPerturbations.\n\nGet QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(GetQzssPerturbations);


    GetQzssPerturbations::GetQzssPerturbations()
      : CommandBase(CmdName)
    {}

    GetQzssPerturbations::GetQzssPerturbations(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetQzssPerturbationsPtr GetQzssPerturbations::create(int svId)
    {
      return GetQzssPerturbationsPtr(new GetQzssPerturbations(svId));
    }

    GetQzssPerturbationsPtr GetQzssPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssPerturbations>(ptr);
    }

    bool GetQzssPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetQzssPerturbations::documentation() const { return Documentation; }


    int GetQzssPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssPerturbations::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssPerturbations::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
