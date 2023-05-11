#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVIDsOfPrn.
    ///
    /// Name     Type      Description
    /// -------- --------- ----------------------------------------------------------------------
    /// Signal   string    Signal key - see GetSVIDsOfPrn command description for possible values
    /// Prn      int       Satellite PRN number
    /// SvIdList array int A list containing all SV ID of a specific signal
    ///

    class GetSVIDsOfPrnResult;
    typedef std::shared_ptr<GetSVIDsOfPrnResult> GetSVIDsOfPrnResultPtr;
    
    
    class GetSVIDsOfPrnResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVIDsOfPrnResult();

      GetSVIDsOfPrnResult(CommandBasePtr relatedCommand, const std::string& signal, int prn, const std::vector<int>& svIdList);
  
      static GetSVIDsOfPrnResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, int prn, const std::vector<int>& svIdList);
      static GetSVIDsOfPrnResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** svIdList ****
      std::vector<int> svIdList() const;
      void setSvIdList(const std::vector<int>& svIdList);
    };
  }
}

