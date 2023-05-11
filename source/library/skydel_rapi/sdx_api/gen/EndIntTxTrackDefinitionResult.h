#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// EndIntTxTrackDefinition Result with created track informations.
    ///
    /// Name  Type   Description
    /// ----- ------ ----------------------------------------------------------------------------------------------------
    /// Count int    Number of nodes in the track. The client can compare this value with the number of positions pushed.
    /// Id    string Transmitter unique identifier.
    ///

    class EndIntTxTrackDefinitionResult;
    typedef std::shared_ptr<EndIntTxTrackDefinitionResult> EndIntTxTrackDefinitionResultPtr;
    
    
    class EndIntTxTrackDefinitionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EndIntTxTrackDefinitionResult();

      EndIntTxTrackDefinitionResult(CommandBasePtr relatedCommand, int count, const std::string& id);
  
      static EndIntTxTrackDefinitionResultPtr create(CommandBasePtr relatedCommand, int count, const std::string& id);
      static EndIntTxTrackDefinitionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** count ****
      int count() const;
      void setCount(int count);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

