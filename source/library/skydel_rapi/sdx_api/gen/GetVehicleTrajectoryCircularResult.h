#pragma once

#include <memory>
#include "command_result.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehicleTrajectoryCircular.
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------
    /// Type        string          Trajectory type ("Circular")
    /// Lat         double          Center latitude (rad)
    /// Lon         double          Center longitude (rad)
    /// Alt         double          Altitude (m)
    /// Radius      double          Radius (m)
    /// Speed       double          Speed (m/s)
    /// Clockwise   bool            If true, vehicle turns clockwise
    /// OriginAngle optional double Vehicle angle at elapsed time 0.
    ///

    class GetVehicleTrajectoryCircularResult;
    typedef std::shared_ptr<GetVehicleTrajectoryCircularResult> GetVehicleTrajectoryCircularResultPtr;
    
    
    class GetVehicleTrajectoryCircularResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTrajectoryCircularResult();

      GetVehicleTrajectoryCircularResult(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle = {});
  
      static GetVehicleTrajectoryCircularResultPtr create(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double radius, double speed, bool clockwise, const Sdx::optional<double>& originAngle = {});
      static GetVehicleTrajectoryCircularResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** lat ****
      double lat() const;
      void setLat(double lat);


      // **** lon ****
      double lon() const;
      void setLon(double lon);


      // **** alt ****
      double alt() const;
      void setAlt(double alt);


      // **** radius ****
      double radius() const;
      void setRadius(double radius);


      // **** speed ****
      double speed() const;
      void setSpeed(double speed);


      // **** clockwise ****
      bool clockwise() const;
      void setClockwise(bool clockwise);


      // **** originAngle ****
      Sdx::optional<double> originAngle() const;
      void setOriginAngle(const Sdx::optional<double>& originAngle);
    };
  }
}

