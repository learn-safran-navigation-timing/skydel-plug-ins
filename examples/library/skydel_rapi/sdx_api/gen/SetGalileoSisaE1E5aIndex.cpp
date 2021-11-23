#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSisaE1E5aIndex
///
#include "gen/SetGalileoSisaE1E5aIndex.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSisaE1E5aIndex::CmdName = "SetGalileoSisaE1E5aIndex";
    const char* const SetGalileoSisaE1E5aIndex::Documentation = "Please note the command SetGalileoSisaE1E5aIndex is deprecated since 21.3. You may use SetGalileoSisaE1E5aIndexForSV.\n\nSet the SISA(E1,E5a) index of a Galileo satellite";

    REGISTER_COMMAND_FACTORY(SetGalileoSisaE1E5aIndex);


    SetGalileoSisaE1E5aIndex::SetGalileoSisaE1E5aIndex()
      : CommandBase(CmdName)
    {}

    SetGalileoSisaE1E5aIndex::SetGalileoSisaE1E5aIndex(int prn, int sisai)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSisai(sisai);
    }


    SetGalileoSisaE1E5aIndexPtr SetGalileoSisaE1E5aIndex::create(int prn, int sisai)
    {
      return SetGalileoSisaE1E5aIndexPtr(new SetGalileoSisaE1E5aIndex(prn, sisai));
    }

    SetGalileoSisaE1E5aIndexPtr SetGalileoSisaE1E5aIndex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSisaE1E5aIndex>(ptr);
    }

    bool SetGalileoSisaE1E5aIndex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["Sisai"])
        ;

    }

    std::string SetGalileoSisaE1E5aIndex::documentation() const { return Documentation; }


    int SetGalileoSisaE1E5aIndex::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetGalileoSisaE1E5aIndex::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoSisaE1E5aIndex::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoSisaE1E5aIndex::sisai() const
    {
      return parse_json<int>::parse(m_values["Sisai"]);
    }

    void SetGalileoSisaE1E5aIndex::setSisai(int sisai)
    {
      m_values.AddMember("Sisai", parse_json<int>::format(sisai, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
