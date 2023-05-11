#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get interference transmitter trajectory.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxTrajectory;
    typedef std::shared_ptr<GetIntTxTrajectory> GetIntTxTrajectoryPtr;
    
    
    class GetIntTxTrajectory : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxTrajectory();

      GetIntTxTrajectory(const std::string& id);
  
      static GetIntTxTrajectoryPtr create(const std::string& id);
      static GetIntTxTrajectoryPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

