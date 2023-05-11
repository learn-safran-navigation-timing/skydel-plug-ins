#pragma once

#include <memory>
#include "command_result.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetTransmittedPrnForSV.
    ///
    /// Name          Type            Description
    /// ------------- --------------- --------------------------------------------------------------------------------
    /// SvId          int             Satellite SV ID.
    /// SignalPrnDict dict string:int A dictionary of signal prn pairs.
    ///                               Accepted keys are: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C",
    ///                                                  "B2a", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                                  "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S" and "NAVICL5"
    ///

    class GetTransmittedPrnForSVResult;
    typedef std::shared_ptr<GetTransmittedPrnForSVResult> GetTransmittedPrnForSVResultPtr;
    
    
    class GetTransmittedPrnForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetTransmittedPrnForSVResult();

      GetTransmittedPrnForSVResult(CommandBasePtr relatedCommand, int svId, const std::map<std::string, int>& signalPrnDict);
  
      static GetTransmittedPrnForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::map<std::string, int>& signalPrnDict);
      static GetTransmittedPrnForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signalPrnDict ****
      std::map<std::string, int> signalPrnDict() const;
      void setSignalPrnDict(const std::map<std::string, int>& signalPrnDict);
    };
  }
}

