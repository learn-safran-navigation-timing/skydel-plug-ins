#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssPerturbationsForAllSat
///
#include "gen/GetQzssPerturbationsForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssPerturbationsForAllSat::CmdName = "GetQzssPerturbationsForAllSat";
    const char* const GetQzssPerturbationsForAllSat::Documentation = "Please note the command GetQzssPerturbationsForAllSat is deprecated since 20.9. You may use GetPerturbationsForAllSat.\n\nGet QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.\nAll parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";

    REGISTER_COMMAND_FACTORY(GetQzssPerturbationsForAllSat);


    GetQzssPerturbationsForAllSat::GetQzssPerturbationsForAllSat()
      : CommandBase(CmdName)
    {

    }


    GetQzssPerturbationsForAllSatPtr GetQzssPerturbationsForAllSat::create()
    {
      return GetQzssPerturbationsForAllSatPtr(new GetQzssPerturbationsForAllSat());
    }

    GetQzssPerturbationsForAllSatPtr GetQzssPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssPerturbationsForAllSat>(ptr);
    }

    bool GetQzssPerturbationsForAllSat::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetQzssPerturbationsForAllSat::documentation() const { return Documentation; }


    int GetQzssPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
