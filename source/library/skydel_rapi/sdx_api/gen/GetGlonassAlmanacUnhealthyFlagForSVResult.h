#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassAlmanacUnhealthyFlagForSV.
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------
    /// SvId   int  The satellite's SV ID 1..24
    /// Health bool Status, false = Non-operability, true = Operability (Good)
    ///

    class GetGlonassAlmanacUnhealthyFlagForSVResult;
    typedef std::shared_ptr<GetGlonassAlmanacUnhealthyFlagForSVResult> GetGlonassAlmanacUnhealthyFlagForSVResultPtr;
    
    
    class GetGlonassAlmanacUnhealthyFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassAlmanacUnhealthyFlagForSVResult();

      GetGlonassAlmanacUnhealthyFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetGlonassAlmanacUnhealthyFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetGlonassAlmanacUnhealthyFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

