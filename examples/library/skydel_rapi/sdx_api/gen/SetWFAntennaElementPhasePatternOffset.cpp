#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaElementPhasePatternOffset
///
#include "gen/SetWFAntennaElementPhasePatternOffset.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaElementPhasePatternOffset::CmdName = "SetWFAntennaElementPhasePatternOffset";
    const char* const SetWFAntennaElementPhasePatternOffset::Documentation = "Set WF Antenna phase pattern offset (in rad) for this element";

    REGISTER_COMMAND_FACTORY(SetWFAntennaElementPhasePatternOffset);


    SetWFAntennaElementPhasePatternOffset::SetWFAntennaElementPhasePatternOffset()
      : CommandBase(CmdName)
    {}

    SetWFAntennaElementPhasePatternOffset::SetWFAntennaElementPhasePatternOffset(double phaseOffset, int element)
      : CommandBase(CmdName)
    {

      setPhaseOffset(phaseOffset);
      setElement(element);
    }


    SetWFAntennaElementPhasePatternOffsetPtr SetWFAntennaElementPhasePatternOffset::create(double phaseOffset, int element)
    {
      return std::make_shared<SetWFAntennaElementPhasePatternOffset>(phaseOffset, element);
    }

    SetWFAntennaElementPhasePatternOffsetPtr SetWFAntennaElementPhasePatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFAntennaElementPhasePatternOffset>(ptr);
    }

    bool SetWFAntennaElementPhasePatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PhaseOffset"])
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string SetWFAntennaElementPhasePatternOffset::documentation() const { return Documentation; }


    int SetWFAntennaElementPhasePatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetWFAntennaElementPhasePatternOffset::phaseOffset() const
    {
      return parse_json<double>::parse(m_values["PhaseOffset"]);
    }

    void SetWFAntennaElementPhasePatternOffset::setPhaseOffset(double phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<double>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetWFAntennaElementPhasePatternOffset::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void SetWFAntennaElementPhasePatternOffset::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
