#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get antenna offset and orientation relative to body frame.
    /// The origin of the body frame follows the transmitter trajectory.
    /// When the body yaw/pitch/roll are zeros, the body X-axis is pointing north
    ///                          Y-axis is pointing east
    ///                          Z-axis is pointing down
    /// The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and
    /// the Roll is rotating arond the X-axis of the body frame.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxAntennaOffset;
    typedef std::shared_ptr<GetIntTxAntennaOffset> GetIntTxAntennaOffsetPtr;
    
    
    class GetIntTxAntennaOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxAntennaOffset();

      GetIntTxAntennaOffset(const std::string& id);
  
      static GetIntTxAntennaOffsetPtr create(const std::string& id);
      static GetIntTxAntennaOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

