#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsPerturbations
///
#include "gen/GetGpsPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsPerturbations::CmdName = "GetGpsPerturbations";
    const char* const GetGpsPerturbations::Documentation = "Please note the command GetGpsPerturbations is deprecated since 21.3. You may use GetPerturbations.\n\nGet GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(GetGpsPerturbations);


    GetGpsPerturbations::GetGpsPerturbations()
      : CommandBase(CmdName)
    {}

    GetGpsPerturbations::GetGpsPerturbations(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsPerturbationsPtr GetGpsPerturbations::create(int prn)
    {
      return GetGpsPerturbationsPtr(new GetGpsPerturbations(prn));
    }

    GetGpsPerturbationsPtr GetGpsPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsPerturbations>(ptr);
    }

    bool GetGpsPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsPerturbations::documentation() const { return Documentation; }


    int GetGpsPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
