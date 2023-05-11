#pragma once

#include <memory>
#include "command_result.h"
#include "gen/GNSSBand.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVGainPatternOffset.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band. ("L1", "L2" or "L5")
    /// System      string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Offset      double          Power offset
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetSVGainPatternOffsetResult;
    typedef std::shared_ptr<GetSVGainPatternOffsetResult> GetSVGainPatternOffsetResultPtr;
    
    
    class GetSVGainPatternOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVGainPatternOffsetResult();

      GetSVGainPatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName = {});
  
      static GetSVGainPatternOffsetResultPtr create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName = {});
      static GetSVGainPatternOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);


      // **** antennaName ****
      Sdx::optional<std::string> antennaName() const;
      void setAntennaName(const Sdx::optional<std::string>& antennaName);
    };
  }
}

