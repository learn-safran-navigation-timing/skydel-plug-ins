#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPrnOfSVID.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C", "B2a", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// SvId   int    Satellite SV ID.
    /// Prn    int    PRN number.
    ///

    class GetPrnOfSVIDResult;
    typedef std::shared_ptr<GetPrnOfSVIDResult> GetPrnOfSVIDResultPtr;
    
    
    class GetPrnOfSVIDResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPrnOfSVIDResult();

      GetPrnOfSVIDResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn);
  
      static GetPrnOfSVIDResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn);
      static GetPrnOfSVIDResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

