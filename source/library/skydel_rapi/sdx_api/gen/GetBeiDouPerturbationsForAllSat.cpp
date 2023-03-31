#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouPerturbationsForAllSat
///
#include "gen/GetBeiDouPerturbationsForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouPerturbationsForAllSat::CmdName = "GetBeiDouPerturbationsForAllSat";
    const char* const GetBeiDouPerturbationsForAllSat::Documentation = "Please note the command GetBeiDouPerturbationsForAllSat is deprecated since 21.3. You may use GetPerturbationsForAllSat.\n\nGet BeiDou orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.\nAll parameters are zero based index (index 0 => PRN 1, index 1 => PRN 2, etc)";

    REGISTER_COMMAND_FACTORY(GetBeiDouPerturbationsForAllSat);


    GetBeiDouPerturbationsForAllSat::GetBeiDouPerturbationsForAllSat()
      : CommandBase(CmdName)
    {

    }


    GetBeiDouPerturbationsForAllSatPtr GetBeiDouPerturbationsForAllSat::create()
    {
      return GetBeiDouPerturbationsForAllSatPtr(new GetBeiDouPerturbationsForAllSat());
    }

    GetBeiDouPerturbationsForAllSatPtr GetBeiDouPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouPerturbationsForAllSat>(ptr);
    }

    bool GetBeiDouPerturbationsForAllSat::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetBeiDouPerturbationsForAllSat::documentation() const { return Documentation; }


    int GetBeiDouPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
