#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetBeiDouPerturbations
///
#include "gen/ResetBeiDouPerturbations.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetBeiDouPerturbations::CmdName = "ResetBeiDouPerturbations";
    const char* const ResetBeiDouPerturbations::Documentation = "Please note the command ResetBeiDouPerturbations is deprecated since 21.3. You may use ResetPerturbations.\n\nSet BeiDou orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero";

    REGISTER_COMMAND_FACTORY(ResetBeiDouPerturbations);


    ResetBeiDouPerturbations::ResetBeiDouPerturbations()
      : CommandBase(CmdName)
    {}

    ResetBeiDouPerturbations::ResetBeiDouPerturbations(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    ResetBeiDouPerturbationsPtr ResetBeiDouPerturbations::create(int prn)
    {
      return ResetBeiDouPerturbationsPtr(new ResetBeiDouPerturbations(prn));
    }

    ResetBeiDouPerturbationsPtr ResetBeiDouPerturbations::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetBeiDouPerturbations>(ptr);
    }

    bool ResetBeiDouPerturbations::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string ResetBeiDouPerturbations::documentation() const { return Documentation; }


    int ResetBeiDouPerturbations::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ResetBeiDouPerturbations::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void ResetBeiDouPerturbations::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
