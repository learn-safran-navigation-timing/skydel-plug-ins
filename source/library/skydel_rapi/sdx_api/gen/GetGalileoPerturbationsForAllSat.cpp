#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoPerturbationsForAllSat
///
#include "gen/GetGalileoPerturbationsForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoPerturbationsForAllSat::CmdName = "GetGalileoPerturbationsForAllSat";
    const char* const GetGalileoPerturbationsForAllSat::Documentation = "Please note the command GetGalileoPerturbationsForAllSat is deprecated since 21.3. You may use GetPerturbationsForAllSat.\n\nGet Galileo orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.\nAll parameters are zero based index (index 0 => PRN 1, index 1 => PRN 2, etc)";

    REGISTER_COMMAND_FACTORY(GetGalileoPerturbationsForAllSat);


    GetGalileoPerturbationsForAllSat::GetGalileoPerturbationsForAllSat()
      : CommandBase(CmdName)
    {

    }


    GetGalileoPerturbationsForAllSatPtr GetGalileoPerturbationsForAllSat::create()
    {
      return GetGalileoPerturbationsForAllSatPtr(new GetGalileoPerturbationsForAllSat());
    }

    GetGalileoPerturbationsForAllSatPtr GetGalileoPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoPerturbationsForAllSat>(ptr);
    }

    bool GetGalileoPerturbationsForAllSat::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGalileoPerturbationsForAllSat::documentation() const { return Documentation; }


    int GetGalileoPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
