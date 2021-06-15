#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsPerturbationsForAllSat
///
#include "gen/GetGpsPerturbationsForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsPerturbationsForAllSat::CmdName = "GetGpsPerturbationsForAllSat";
    const char* const GetGpsPerturbationsForAllSat::Documentation = "Please note the command GetGpsPerturbationsForAllSat is deprecated since 21.3. You may use GetPerturbationsForAllSat.\n\nGet GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.\nAll parameters are zero based index (index 0 => PRN 1, index 1 => PRN 2, etc)";

    REGISTER_COMMAND_FACTORY(GetGpsPerturbationsForAllSat);


    GetGpsPerturbationsForAllSat::GetGpsPerturbationsForAllSat()
      : CommandBase(CmdName)
    {

    }


    GetGpsPerturbationsForAllSatPtr GetGpsPerturbationsForAllSat::create()
    {
      return GetGpsPerturbationsForAllSatPtr(new GetGpsPerturbationsForAllSat());
    }

    GetGpsPerturbationsForAllSatPtr GetGpsPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsPerturbationsForAllSat>(ptr);
    }

    bool GetGpsPerturbationsForAllSat::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGpsPerturbationsForAllSat::documentation() const { return Documentation; }


    int GetGpsPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
