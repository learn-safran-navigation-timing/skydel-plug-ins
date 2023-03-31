#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSisaE1E5bIndex
///
#include "gen/SetGalileoSisaE1E5bIndex.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSisaE1E5bIndex::CmdName = "SetGalileoSisaE1E5bIndex";
    const char* const SetGalileoSisaE1E5bIndex::Documentation = "Please note the command SetGalileoSisaE1E5bIndex is deprecated since 21.3. You may use SetGalileoSisaE1E5bIndexForSV.\n\nSet the SISA(E1,E5b) index of a Galileo satellite";

    REGISTER_COMMAND_FACTORY(SetGalileoSisaE1E5bIndex);


    SetGalileoSisaE1E5bIndex::SetGalileoSisaE1E5bIndex()
      : CommandBase(CmdName)
    {}

    SetGalileoSisaE1E5bIndex::SetGalileoSisaE1E5bIndex(int prn, int sisai)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSisai(sisai);
    }


    SetGalileoSisaE1E5bIndexPtr SetGalileoSisaE1E5bIndex::create(int prn, int sisai)
    {
      return SetGalileoSisaE1E5bIndexPtr(new SetGalileoSisaE1E5bIndex(prn, sisai));
    }

    SetGalileoSisaE1E5bIndexPtr SetGalileoSisaE1E5bIndex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSisaE1E5bIndex>(ptr);
    }

    bool SetGalileoSisaE1E5bIndex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Sisai"])
        ;

    }

    std::string SetGalileoSisaE1E5bIndex::documentation() const { return Documentation; }


    int SetGalileoSisaE1E5bIndex::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetGalileoSisaE1E5bIndex::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoSisaE1E5bIndex::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoSisaE1E5bIndex::sisai() const
    {
      return parse_json<int>::parse(m_values["Sisai"]);
    }

    void SetGalileoSisaE1E5bIndex::setSisai(int sisai)
    {
      m_values.AddMember("Sisai", parse_json<int>::format(sisai, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
