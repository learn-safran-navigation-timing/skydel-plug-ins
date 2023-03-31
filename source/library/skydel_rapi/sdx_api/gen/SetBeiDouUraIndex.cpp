#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouUraIndex
///
#include "gen/SetBeiDouUraIndex.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouUraIndex::CmdName = "SetBeiDouUraIndex";
    const char* const SetBeiDouUraIndex::Documentation = "Please note the command SetBeiDouUraIndex is deprecated since 21.3. You may use SetBeiDouUraIndexForSV.\n\nSet the ura index of a BeiDou satellite";

    REGISTER_COMMAND_FACTORY(SetBeiDouUraIndex);


    SetBeiDouUraIndex::SetBeiDouUraIndex()
      : CommandBase(CmdName)
    {}

    SetBeiDouUraIndex::SetBeiDouUraIndex(int prn, int urai)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setUrai(urai);
    }


    SetBeiDouUraIndexPtr SetBeiDouUraIndex::create(int prn, int urai)
    {
      return SetBeiDouUraIndexPtr(new SetBeiDouUraIndex(prn, urai));
    }

    SetBeiDouUraIndexPtr SetBeiDouUraIndex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouUraIndex>(ptr);
    }

    bool SetBeiDouUraIndex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Urai"])
        ;

    }

    std::string SetBeiDouUraIndex::documentation() const { return Documentation; }


    int SetBeiDouUraIndex::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetBeiDouUraIndex::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetBeiDouUraIndex::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouUraIndex::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetBeiDouUraIndex::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
