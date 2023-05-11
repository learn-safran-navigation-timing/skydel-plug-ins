#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxFix.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------
    /// Lat   double Latitude (rad)
    /// Lon   double Longitude (rad)
    /// Alt   double Altitude (m)
    /// Yaw   double Yaw (rad)
    /// Pitch double Pitch (rad)
    /// Roll  double Roll (rad)
    /// Id    string Transmitter unique identifier.
    ///

    class GetIntTxFixResult;
    typedef std::shared_ptr<GetIntTxFixResult> GetIntTxFixResultPtr;
    
    
    class GetIntTxFixResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxFixResult();

      GetIntTxFixResult(CommandBasePtr relatedCommand, double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id);
  
      static GetIntTxFixResultPtr create(CommandBasePtr relatedCommand, double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id);
      static GetIntTxFixResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** lat ****
      double lat() const;
      void setLat(double lat);


      // **** lon ****
      double lon() const;
      void setLon(double lon);


      // **** alt ****
      double alt() const;
      void setAlt(double alt);


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

