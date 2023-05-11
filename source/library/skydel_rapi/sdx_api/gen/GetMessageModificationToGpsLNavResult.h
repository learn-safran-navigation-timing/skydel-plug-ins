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
    /// Result of GetMessageModificationToGpsLNav.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ------------------------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "L1CA", "L1P" and "L2P" (empty for all)
    /// SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)
    /// Page             int          Page 1..25 (use 0 to apply modification to all pages)
    /// Word             int          Word 1..10 (use 0 to apply modification to all words)
    /// UpdateParity     bool         Recalculate parity after making modification
    /// WordModification string       Modification string must be 30 bits long
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToGpsLNavResult;
    typedef std::shared_ptr<GetMessageModificationToGpsLNavResult> GetMessageModificationToGpsLNavResultPtr;
    
    
    class GetMessageModificationToGpsLNavResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToGpsLNavResult();

      GetMessageModificationToGpsLNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);
  
      static GetMessageModificationToGpsLNavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);
      static GetMessageModificationToGpsLNavResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signalArray ****
      std::vector<std::string> signalArray() const;
      void setSignalArray(const std::vector<std::string>& signalArray);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** startTime ****
      int startTime() const;
      void setStartTime(int startTime);


      // **** stopTime ****
      int stopTime() const;
      void setStopTime(int stopTime);


      // **** subframe ****
      int subframe() const;
      void setSubframe(int subframe);


      // **** page ****
      int page() const;
      void setPage(int page);


      // **** word ****
      int word() const;
      void setWord(int word);


      // **** updateParity ****
      bool updateParity() const;
      void setUpdateParity(bool updateParity);


      // **** wordModification ****
      std::string wordModification() const;
      void setWordModification(const std::string& wordModification);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

