#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouPerturbations
///
#include "gen/GetBeiDouPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouPerturbations::CmdName = "GetBeiDouPerturbations";
    const char* const GetBeiDouPerturbations::Documentation = "Please note the command GetBeiDouPerturbations is deprecated since 21.3. You may use GetPerturbations.\n\nGet BeiDou orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)";

    REGISTER_COMMAND_FACTORY(GetBeiDouPerturbations);


    GetBeiDouPerturbations::GetBeiDouPerturbations()
      : CommandBase(CmdName)
    {}

    GetBeiDouPerturbations::GetBeiDouPerturbations(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouPerturbationsPtr GetBeiDouPerturbations::create(int prn)
    {
      return GetBeiDouPerturbationsPtr(new GetBeiDouPerturbations(prn));
    }

    GetBeiDouPerturbationsPtr GetBeiDouPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouPerturbations>(ptr);
    }

    bool GetBeiDouPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouPerturbations::documentation() const { return Documentation; }


    int GetBeiDouPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
