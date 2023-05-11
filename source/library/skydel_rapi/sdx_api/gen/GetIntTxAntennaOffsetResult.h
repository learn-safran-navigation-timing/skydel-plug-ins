#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxAntennaOffset.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// X     double Antenna X offset in the body frame
    /// Y     double Antenna Y offset in the body frame
    /// Z     double Antenna Z offset in the body frame
    /// Yaw   double Antenna Yaw offset in the body frame
    /// Pitch double Antenna Pitch offset in the body frame
    /// Roll  double Antenna Roll offset in the body frame
    /// Id    string Transmitter unique identifier.
    ///

    class GetIntTxAntennaOffsetResult;
    typedef std::shared_ptr<GetIntTxAntennaOffsetResult> GetIntTxAntennaOffsetResultPtr;
    
    
    class GetIntTxAntennaOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxAntennaOffsetResult();

      GetIntTxAntennaOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);
  
      static GetIntTxAntennaOffsetResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);
      static GetIntTxAntennaOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** x ****
      double x() const;
      void setX(double x);


      // **** y ****
      double y() const;
      void setY(double y);


      // **** z ****
      double z() const;
      void setZ(double z);


      // **** yaw ****
      double yaw() const;
      void setYaw(double yaw);


      // **** pitch ****
      double pitch() const;
      void setPitch(double pitch);


      // **** roll ****
      double roll() const;
      void setRoll(double roll);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

