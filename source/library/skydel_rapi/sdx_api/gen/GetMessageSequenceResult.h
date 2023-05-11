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
    /// Result of GetMessageSequence.
    ///
    /// Name     Type      Description
    /// -------- --------- -------------------------------
    /// Signal   string    Signal Name ("L2C" for example)
    /// Sequence array int List of message type
    ///

    class GetMessageSequenceResult;
    typedef std::shared_ptr<GetMessageSequenceResult> GetMessageSequenceResultPtr;
    
    
    class GetMessageSequenceResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageSequenceResult();

      GetMessageSequenceResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& sequence);
  
      static GetMessageSequenceResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& sequence);
      static GetMessageSequenceResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** sequence ****
      std::vector<int> sequence() const;
      void setSequence(const std::vector<int>& sequence);
    };
  }
}

