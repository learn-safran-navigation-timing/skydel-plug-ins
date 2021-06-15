#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoPerturbations
///
#include "gen/GetGalileoPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoPerturbations::CmdName = "GetGalileoPerturbations";
    const char* const GetGalileoPerturbations::Documentation = "Please note the command GetGalileoPerturbations is deprecated since 21.3. You may use GetPerturbations.\n\nGet GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(GetGalileoPerturbations);


    GetGalileoPerturbations::GetGalileoPerturbations()
      : CommandBase(CmdName)
    {}

    GetGalileoPerturbations::GetGalileoPerturbations(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGalileoPerturbationsPtr GetGalileoPerturbations::create(int prn)
    {
      return GetGalileoPerturbationsPtr(new GetGalileoPerturbations(prn));
    }

    GetGalileoPerturbationsPtr GetGalileoPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoPerturbations>(ptr);
    }

    bool GetGalileoPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGalileoPerturbations::documentation() const { return Documentation; }


    int GetGalileoPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
