#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPerturbationsForAllSat
///
#include "gen/GetPerturbationsForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPerturbationsForAllSat::CmdName = "GetPerturbationsForAllSat";
    const char* const GetPerturbationsForAllSat::Documentation = "Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..\nAll parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";

    REGISTER_COMMAND_FACTORY(GetPerturbationsForAllSat);


    GetPerturbationsForAllSat::GetPerturbationsForAllSat()
      : CommandBase(CmdName)
    {}

    GetPerturbationsForAllSat::GetPerturbationsForAllSat(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }


    GetPerturbationsForAllSatPtr GetPerturbationsForAllSat::create(const std::string& system)
    {
      return GetPerturbationsForAllSatPtr(new GetPerturbationsForAllSat(system));
    }

    GetPerturbationsForAllSatPtr GetPerturbationsForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPerturbationsForAllSat>(ptr);
    }

    bool GetPerturbationsForAllSat::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetPerturbationsForAllSat::documentation() const { return Documentation; }


    int GetPerturbationsForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPerturbationsForAllSat::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPerturbationsForAllSat::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
