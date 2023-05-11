#pragma once

#include <memory>
#include "command_result.h"
#include "date_time.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehicleTrajectoryOrbit.
    ///
    /// Name              Type     Description
    /// ----------------- -------- ---------------------------------------------------------------------
    /// Type              string   Trajectory type ("Orbit")
    /// Reference         datetime Orbital parameters reference time (UTC)
    /// SemiMajorAxis     double   Semi-major axis (meter)
    /// Inclination       double   Inclination angle (rad)
    /// RightAscension    double   Geographic longitude of the ascending node of the orbital plane (rad)
    /// Eccentricity      double   Eccentricity
    /// MeanAnomaly       double   Mean anomaly (rad)
    /// ArgumentOfPerigee double   Argument of perigee (rad)
    ///

    class GetVehicleTrajectoryOrbitResult;
    typedef std::shared_ptr<GetVehicleTrajectoryOrbitResult> GetVehicleTrajectoryOrbitResultPtr;
    
    
    class GetVehicleTrajectoryOrbitResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTrajectoryOrbitResult();

      GetVehicleTrajectoryOrbitResult(CommandBasePtr relatedCommand, const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee);
  
      static GetVehicleTrajectoryOrbitResultPtr create(CommandBasePtr relatedCommand, const std::string& type, const Sdx::DateTime& reference, double semiMajorAxis, double inclination, double rightAscension, double eccentricity, double meanAnomaly, double argumentOfPerigee);
      static GetVehicleTrajectoryOrbitResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** reference ****
      Sdx::DateTime reference() const;
      void setReference(const Sdx::DateTime& reference);


      // **** semiMajorAxis ****
      double semiMajorAxis() const;
      void setSemiMajorAxis(double semiMajorAxis);


      // **** inclination ****
      double inclination() const;
      void setInclination(double inclination);


      // **** rightAscension ****
      double rightAscension() const;
      void setRightAscension(double rightAscension);


      // **** eccentricity ****
      double eccentricity() const;
      void setEccentricity(double eccentricity);


      // **** meanAnomaly ****
      double meanAnomaly() const;
      void setMeanAnomaly(double meanAnomaly);


      // **** argumentOfPerigee ****
      double argumentOfPerigee() const;
      void setArgumentOfPerigee(double argumentOfPerigee);
    };
  }
}

