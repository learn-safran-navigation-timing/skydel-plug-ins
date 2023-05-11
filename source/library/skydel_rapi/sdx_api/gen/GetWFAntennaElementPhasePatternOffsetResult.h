#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFAntennaElementPhasePatternOffset.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------------
    /// PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]
    /// Element     int    One-based index for element in antenna.
    ///

    class GetWFAntennaElementPhasePatternOffsetResult;
    typedef std::shared_ptr<GetWFAntennaElementPhasePatternOffsetResult> GetWFAntennaElementPhasePatternOffsetResultPtr;
    
    
    class GetWFAntennaElementPhasePatternOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWFAntennaElementPhasePatternOffsetResult();

      GetWFAntennaElementPhasePatternOffsetResult(CommandBasePtr relatedCommand, double phaseOffset, int element);
  
      static GetWFAntennaElementPhasePatternOffsetResultPtr create(CommandBasePtr relatedCommand, double phaseOffset, int element);
      static GetWFAntennaElementPhasePatternOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** phaseOffset ****
      double phaseOffset() const;
      void setPhaseOffset(double phaseOffset);


      // **** element ****
      int element() const;
      void setElement(int element);
    };
  }
}

