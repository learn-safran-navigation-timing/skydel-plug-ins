#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsUraIndex
///
#include "gen/SetGpsUraIndex.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsUraIndex::CmdName = "SetGpsUraIndex";
    const char* const SetGpsUraIndex::Documentation = "Please note the command SetGpsUraIndex is deprecated since 21.3. You may use SetGpsUraIndexForSV.\n\nSet the ura index of a GPS satellite";

    REGISTER_COMMAND_FACTORY(SetGpsUraIndex);


    SetGpsUraIndex::SetGpsUraIndex()
      : CommandBase(CmdName)
    {}

    SetGpsUraIndex::SetGpsUraIndex(int prn, int urai)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setUrai(urai);
    }


    SetGpsUraIndexPtr SetGpsUraIndex::create(int prn, int urai)
    {
      return SetGpsUraIndexPtr(new SetGpsUraIndex(prn, urai));
    }

    SetGpsUraIndexPtr SetGpsUraIndex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsUraIndex>(ptr);
    }

    bool SetGpsUraIndex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Urai"])
        ;

    }

    std::string SetGpsUraIndex::documentation() const { return Documentation; }


    int SetGpsUraIndex::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetGpsUraIndex::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsUraIndex::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsUraIndex::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetGpsUraIndex::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
